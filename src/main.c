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

	move(2,2);
	populateTextWin();
	wrefresh(text_win);


	move(text_win_row+4,2);
	getyx(stdscr,y,x);
	refresh();
	while(1)
	{
		ch = getch();
		if(ch == 'q')
		{
			break;
		}
		else
		{
			wprintw(user_win,"%c",ch);
		}
		wrefresh(user_win);
	}
	deinitialize();

	return 0;

}
