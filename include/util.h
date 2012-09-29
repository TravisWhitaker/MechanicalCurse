//	MechanicalCurse Copyright (C) 2012 Travis Whitaker

#ifndef UTIL
#define UTIL

char *textArray;
int row,col;
int x,y;
WINDOW *text_win,*user_win;

void initialize();
void deinitialize();
char *constructTextArray(char filename[]);

#endif
