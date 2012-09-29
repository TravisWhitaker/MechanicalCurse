#	MechanicalCurse Copyright (C) 2012 Travis Whitaker

CC = clang
CFLAGS= -lncurses
BIN= mcurse
SOURCES= $(wildcard src/*.c)
INCLUDE= -I./include

default: mcurse

mcurse:
	$(CC) $(CFLAGS) $(INCLUDE) -o $(BIN) $(SOURCES)

clean:
	rm $(BIN)
