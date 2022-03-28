#ifndef LEAVES_H
#define LEAVES_H

#define _CRT_SECURE_NO_WARNINGS

#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#ifdef _WIN32
#include <Windows.h>
#endif

typedef struct {
	char* con;

	int columns;
	int rows;

	int pos_columns;
	int pos_rows;

	int len;
	int char_len;

	int cur_cols;
	int cur_rows;
} Leaf;

#define CUR_ORIGIN "\x1b[H"
#define ENABLE_TERM_ALT_BUF "\x1b[?1049h"
#define DISABLE_TERM_ALT_BUF "\x1b[?1049l"
#define CLEAR_SCR "\x1b[2J"
#define ENABLE_CUR "\x1b[?25h"
#define DISABLE_CUR "\x1b[?25l"

#define SUCCESS 0
#define FAILURE 1

#define TRUE 1
#define FALSE 0

#define TERM_IN_RAW 1
#define TERM_IN_COOKED 2

#define FG_BLACK   0x1E
#define FG_RED     0x1F
#define FG_GREEN   0x20
#define FG_YELLOW  0x21
#define FG_BLUE    0x22
#define FG_MAGENTA 0x23
#define FG_CYAN    0x24
#define FG_WHITE   0x25
#define FG_DEFAULT 0x27

#define BG_BLACK   0x28
#define BG_RED     0x29
#define BG_GREEN   0x2A
#define BG_YELLOW  0x2B
#define BG_BLUE    0x2C
#define BG_MAGENTA 0x2D
#define BG_CYAN    0x2E
#define BG_WHITE   0x2F
#define BG_DEFAULT 0x31

extern Leaf* scr;

extern int showCurL(int status);
extern int lcurxyL(Leaf* l, int x, int y);

extern int lwriteL(Leaf* l, const char* string, ...);
extern int appendToLeaf(Leaf* l, const char* string, ...);
extern int appendToLeafCH(Leaf* l, char ch);
extern int lwriteCHL(Leaf* l, char ch);

extern char inChL();

extern Leaf* newLeaf(int x, int y, int columns, int rows);
extern int delLeaf(Leaf* l);

extern int initL();
extern int exitL();

extern int lsizeL(Leaf* l, int x, int y);
extern int termSize(int* cols, int* rows);
extern int lposL(Leaf* l, int x, int y);

extern int lupdateL(Leaf* l);

extern int lclrmemL(Leaf* l);
extern int clrscrL();

extern int lcolorL(Leaf* l, int FG, int BG);

extern int setTermios(FILE* fOperator, int ECHOMODE, int INMODE);

extern int setTitleL(const char* title);

extern int lborderL(Leaf* l);

#define lpwriteL(l, x, y, string, ...) {lcurxyL(l, x, y); lwriteL(l, string, ## __VA_ARGS__);}
#define pwriteL(x, y, string, ...) {lcurxyL(scr, x, y); lwriteL(scr, string, ## __VA_ARGS__);}
#define lpwriteL(l, x, y, string, ...) {lcurxyL(l, x, y); lwriteL(l, string, ## __VA_ARGS__);}
#define lcwriteL(l, FG, BG, string, ...) {lcolorL(l, FG, BG); lwriteL(l, string, ## __VA_ARGS__)
#define lpcwriteL(l, x, y, FG, BG, string, ...) {lcolorL(l, FG, BG); lcurxyL(l, x, y); lwriteL(l, string, ## __VA_ARGS__);}
#define cwriteL(FG, BG, string, ...) {lcolorL(scr, FG, BG); lwriteL(scr, string, ## __VA_ARGS__);}
#define pcwriteL(x, y, FG, BG, string, ...) {lcurxyL(scr, x, y); lcolorL(scr, FG, BG); lwriteL(scr, string, ## __VA_ARGS__);}

#define lpwriteCHL(l, x, y, ch, ...) {lcurxyL(l, x, y); lwriteCHL(l, ch);}
#define pwriteCHL(x, y, ch, ...) {lcurxyL(scr, x, y); lwriteCHL(scr, ch);}
#define lpwriteCHL(l, x, y, ch, ...) {lcurxyL(l, x, y); lwriteCHL(l, ch);}
#define lcwriteCHL(l, FG, BG, ch, ...) {lcolorL(l, FG, BG); lwriteCHL(l, ch);}
#define lpcwriteCHL(l, x, y, FG, BG, ch, ...) {lcolorL(l, FG, BG); lcurxyL(l, x, y); lwriteCHL(l, ch);}
#define cwriteCHL(FG, BG, ch, ...) {lcolorL(scr, FG, BG); lwriteCHL(scr, ch);}
#define pcwriteCHL(x, y, FG, BG, ch, ...) {lcurxyL(scr, x, y); lcolorL(scr, FG, BG); lwriteCHL(scr, ch);}

#define writeL(string, ...) lwriteL(scr, string, ## __VA_ARGS__)

#define updateL() {lupdateL(scr); termSize(&scr->columns, &scr->rows); lsizeL(scr, scr->columns, scr->rows);}

#define curxyL(x, y) lcurxyL(scr, x, y)

#define colorL(FG, BG) lcolorL(scr, FG, BG)

#define clrmemL() {lclrmemL(scr);}
#endif
