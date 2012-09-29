<!--- MechanicalCurse Copyright (C) 2012 Travis Whitaker -->

MechanicalCurse
========

A typing speed test written in C using ncurses.

---

Dependencies:
=============
- libc
- libncurses 

How to Build:
=============
The makefile specifies Clang/LLVM as the compiler. You are of course free to change these, just make sure that you link against ncurses, usually with the -lncurses compiler flag, and that you are in C99 mode. There is no config script(right now).
