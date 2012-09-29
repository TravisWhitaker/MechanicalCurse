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

//	initialize();
	textArray = constructTextArray(argv[1]);
//	printw("POOP");
	printf("%s",textArray);
//	refresh();
//	int pingas = getch();
//	deinitialize();
	free(textArray);

	return 0;

}
