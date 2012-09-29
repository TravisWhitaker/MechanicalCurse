//	MechanicalCurse Copyright (C) 2012 Travis Whitaker

#ifndef UTIL
#define UTIL

char *textArray;
int row,col;
int x,y;
WINDOW *text_win,*text_win_border,*user_win,*user_win_border;
int ch;
int text_win_row,text_win_col,user_win_row,user_win_col;

void initialize();
void deinitialize();
void makeABabby();
char *constructTextArray(char filename[]);
void populateTextWin();

#endif
