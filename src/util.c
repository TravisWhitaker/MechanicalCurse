// MechanicalCurse Copyright (C) 2012 Travis Whitaker

#include <stdio.h>
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
