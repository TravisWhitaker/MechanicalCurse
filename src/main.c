// MechanicalCurse Copyright (C) 2012 Travis Whitaker

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ncurses.h>

#include <util.h>

int main(int argc,char *argv[])
{
	if(argc < 2)
	{
		printf("TOO FEW ARGUMENTS\n");
		return 0;
	}
	else if(argc > 2)
	{
		printf("TOO MANY ARGUMENTS\n");
		return 0;
	}

	initialize();
	getyx(stdscr,y,x);
	textArray = constructTextArray(argv[1]);

	makeABabby();

	move(text_win_row+4,2);
	getyx(stdscr,y,x);
	r = 0;
	wr = 0;
	wrong = 0;
	buffClear(user_buff,256);

	while(1)
	{
		getyx(user_win,y,x);
		werase(text_win);
		r = nextWordLength();
		if(wrong == 0)
		{
			populateTextWin(r,0);
		}
		else if(wrong == 1)
		{
			populateTextWin(0,r);
		}
		else
		{
			wmove(text_win,0,0);
			werase(text_win);
			wprintw(text_win,"ERROR: 'wrong' is equal to %d.",wrong);
			wrefresh(text_win);
		}
		wmove(user_win,y,x);
		wrefresh(user_win);
		ch = getch();
		if(ch == ERR || ch == KEY_DOWN || ch == KEY_UP || ch == KEY_HOME || ch == KEY_DL || ch == KEY_IL || ch == KEY_DC || ch == KEY_IC || ch == KEY_PPAGE || ch == KEY_NPAGE || ch == KEY_EOL || ch == KEY_EOS || ch == KEY_END || ch == KEY_ENTER || ch == KEY_BTAB || ch == KEY_CTAB || ch == '\t' || ch == '\n' || ch == '\r')
		{
			asm("nop");
		}
		else if(ch == 27)
		{
			break;
		}
		else if(ch == KEY_RIGHT)
		{
			getyx(user_win,y,x);
			if(x < wr)
			{
				wmove(user_win,y,x+1);
				wr++;
				getyx(user_win,y,x);
			}
		}
		else if(ch == KEY_LEFT)
		{
			getyx(user_win,y,x);
			if(x > 1)
			{
				wmove(user_win,y,x-1);
				wr--;
				getyx(user_win,y,x);
			}
		}
		else if(ch == KEY_BACKSPACE)
		{
			getyx(user_win,y,x);
			if(x>0)
			{
				wmove(user_win,y,x-1);
				wr--;
				user_buff[wr] = '\0';
				getyx(user_win,y,x);
				werase(user_win);
				wprintw(user_win,"%s",user_buff);
				wmove(user_win,y,x);
				getyx(user_win,y,x);
				wrefresh(user_win);
			}
		}
		else if(ch == ' ')
		{
			wrong = youAreWrong(user_buff,textArray,nextWordLength());
			r = nextWordLength()+1;
			if(wrong == 0)
			{
				buffClear(user_buff,256);
				wr = 0;
				werase(user_win);
				wmove(user_win,0,0);
				wrefresh(user_win);
				getyx(user_win,y,x);
				for(int c = 0;c<r;c++)
				{
					if(textArray[c] == '~')
					{
						r++;
					}
					else
					{
						textArray[c] = '~';
					}
				}
			}
			else
			{
				continue;
			}
		}
		else
		{
			user_buff[wr] = ch;
			wr++;
			getyx(user_win,y,x);
			werase(user_win);
			wprintw(user_win,"%s",user_buff);
			wmove(user_win,y,x+1);
			getyx(user_win,y,x);
			wrefresh(user_win);
		}
	}

	deinitialize();

	return 0;

}
