// MechanicalCurse Copyright (C) 2012 Travis Whitaker

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ncurses.h>

#include <util.h>

void initialize()
{
	initscr();
	cbreak();
	noecho();
	keypad(stdscr,TRUE);
}

void deinitialize()
{
	endwin();
}

char *constructTextArray(char *filename)
{
	FILE *wordfile;
	int filesize;
	char *wordArray;

	wordfile = fopen(filename,"r");

	if(NULL == wordfile)
	{
		printf("'wordfile' IS NULL!\n");

		return 0;
	}

	fseek(wordfile,0,SEEK_END);
	filesize = ftell(wordfile);
	fseek(wordfile,0,SEEK_SET);

	wordArray = malloc(filesize*sizeof(char));

	if(NULL == wordArray)
	{
		printf("MALLOC FAILED!\n");

		return 0;
	}

	char head;

	for(int i=0;i<(filesize);i++)
	{
		head = fgetc(wordfile);

		if(EOF == head)
		{
			break;
		}
		else
		{
			wordArray[i] = head;
		}
	}

	fclose(wordfile);

	return wordArray;
}
