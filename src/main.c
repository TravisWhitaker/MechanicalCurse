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
		werase(text_win);
		if(wrong == 0)
		{
			populateTextWin(nextWordLength(),0);
		}
		else if(wrong == 1)
		{
			populateTextWin(0,nextWordLength());
		}
		else
		{
			populateTextWin(0,0);
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
		else
		{
			user_buff[wr] = ch;
			wr++;
			werase(user_win);
			mvwprintw(user_win,0,0,"%s",user_buff);
			getyx(user_win,y,x);
			wrefresh(user_win);
		}
	}

	deinitialize();

	return 0;

}
