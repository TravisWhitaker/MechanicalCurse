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

void populateTextWin(int underLines, int highLines)
{
	if(underLines != 0)
	{
		underPrint(text_win,textArray,underLines);
	}
	else if(highLines != 0)
	{
		highPrint(text_win,textArray,highLines);
	}
	else
	{
		wprintw(text_win,"%s",textArray);
	}
	wrefresh(text_win);
	refresh();
	return;
}

void buffClear(char buffer[],int buffsize)
{
	for(int i=0;i>buffsize;i++)
	{
		buffer[i] = '\0';
	}
	return;
}

void underPrint(WINDOW *window, char buffer[], int underChars)
{
	int i = 0;
	char j;
	while(1)
	{
		j = buffer[i];
		if(j == '\0')
		{
			return;
		}
		else if(j != '~')
		{
			if(i < underChars)
			{
				wattron(window,A_UNDERLINE);
				wprintw(window,"%c",j);
				wattroff(window,A_UNDERLINE);
			}
			else
			{
				wprintw(window,"%c",j);
			}
		}
		i++;
	}
}

void highPrint(WINDOW *window, char buffer[], int highChars)
{
	int i = 0;
	char j;
	while(1)
	{
		j = buffer[i];
		if(j == '\0')
		{
			return;
		}
		else if(j != '~')
		{
			if(i < highChars)
			{
				wattron(window,A_STANDOUT);
				wprintw(window,"%c",i);
				wattroff(window,A_STANDOUT);
			}
			else
			{
				wprintw(window,"%c",i);
			}
		}
		i++;
	}
}

int nextWordLength()
{
	int i=0;
	char j;
	while(1)
	{
		j = textArray[i];
		if(j == '~')
		{
		asm("nop");
		}
		else if(j == ' ')
		{
			return i;
		}
		i++;
	}
	return 0;
}

