// MechanicalCurse Copyright (C) 2012 Travis Whitaker

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ncurses.h>

#include <util.h>

int main(int argc,char *argv[])
{
//	if(argc < 2)
//	{
//		printf("TOO FEW ARGUMENTS\n");
//		return 0;
//	}
//	else if(argc > 2)
//	{
//		printf("TOO MANY ARGUMENTS\n");
//		return 0;
//	}

	initialize();
	getyx(stdscr,y,x);

	text_win = newwin((row-7),(col-1),1,1);
	box(text_win,0,0);
	wrefresh(text_win);

	user_win = newwin(6,(col-1),(row-6),1);
	box(user_win,0,0);
	wrefresh(user_win);


	move(row-5,2);
	getyx(stdscr,y,x);
	refresh();
	int pingas = getch();
	deinitialize();

	return 0;

}
