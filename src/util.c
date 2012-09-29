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
	fseek(wordfile,0,SEEK_END);
	filesize = ftell(wordfile);
	fseek(wordfile,0,SEEK_SET);

	wordArray = malloc(filesize*sizeof(char));

	char head;

	for(int i;i<=(filesize+8);i++)
	{
		head = fgetc(wordfile);

		if(head == EOF)
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
