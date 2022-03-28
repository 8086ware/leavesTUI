#ifdef _WIN32 
#include <Windows.h>
#else
#include <termios.h>
#include <sys/ioctl.h>
#endif

#include "../include/leaves.h"
#include <stdlib.h>

int termSize(int* cols, int* rows) {
#ifdef _WIN32
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int columns, row;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	row = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	*cols = columns;
	*rows = row;
#else
	struct winsize ws;
	
    if(ioctl(0, TIOCGWINSZ, &ws) < 0) {
		return FAILURE;
	}
	
	*cols = ws.ws_col;
	*rows = ws.ws_row;

	return SUCCESS;
#endif
}

int lsizeL(Leaf* l, int x, int y) {
	if (x < 0 || y < 0) return FAILURE;

	l->columns = x;
	l->rows = y;
	
	return SUCCESS;
}

int lposL(Leaf* l, int x, int y) {
	l->pos_columns = x;
	l->pos_rows = y;

	if (x < 0 || y < 0) return FAILURE;

	return lclrmemL(l);
}
