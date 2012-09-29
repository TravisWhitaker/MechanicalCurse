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

	underPrint(text_win,"POOP",1);

	wrefresh(text_win);
	refresh();

	char poop = getch();


	deinitialize();

	return 0;

}
