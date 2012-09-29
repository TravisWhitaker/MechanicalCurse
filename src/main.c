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

	text_win_border = newwin((row-7),(col-1),1,1);
	text_win = newwin((row-9),(col-3),2,2);
	box(text_win_border,0,0);
	wrefresh(text_win_border);

	user_win_border = newwin(6,(col-1),(row-6),1);
	user_win = newwin(4,(col-3),(row-5),2);
	box(user_win_border,0,0);
	wrefresh(user_win_border);

	move(2,2);
	wprintw(text_win,textArray);
	wrefresh(text_win);


	move(row-5,2);
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
