##	MechanicalCurse Copyright (C) 2012 Travis Whitaker

CC=clang
CFLAGS=-lncurses
SOURCE= $(wildcard src/*.c)
INCLUDE=-I./include
OUT=-o
EXECUTABLE=mcurse

all:
	$(CC) $(CFLAGS) $(INCLUDE) $(OUT) $(EXECUTABLE) $(SOURCE)

install:
	cp $(EXECUTABLE) /usr/bin/

clean:
	rm $(EXECUTABLE)
