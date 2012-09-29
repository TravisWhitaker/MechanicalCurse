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
	getmaxyx(stdscr,row,col);
	refresh();
}

void deinitialize()
{
	endwin();
}

void makeABabby()
{
	text_win_row = (row/2)-2;
	text_win_col = (col-3);
	user_win_row = 4;
	user_win_col = (col-3);

	text_win_border = newwin(text_win_row+2,text_win_col+2,1,1);
	text_win = newwin(text_win_row,text_win_col,2,2);
	box(text_win_border,0,0);
	wrefresh(text_win_border);
	wrefresh(text_win);

	user_win_border = newwin(user_win_row+2,user_win_col+2,text_win_row+3,1);
	user_win = newwin(user_win_row,user_win_col,text_win_row+4,2);
	box(user_win_border,0,0);
	wrefresh(user_win_border);
	wrefresh(user_win);

	refresh();
	return;
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

void populateTextWin()
{
	int i=0;
	char j;
	while(1)
	{
		j = textArray[i];
		if(j == '\0')
		{
			break;
		}
		else if(j == '~')
		{
			asm("nop");
		}
		else
		{
			wprintw(text_win,"%c",j);
		}
		i++;
	}
	return;
}
