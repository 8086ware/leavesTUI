#include "../include/leaves.h"

void sigHndl(int sig) {
	exitL();
	exit(0);
}

int initL() {
#ifdef _WIN32
	DWORD dwMode = 0;
	if (!GetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), &dwMode))
	{
		return FAILURE;
	}

	dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	if (!SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), dwMode))
	{
		return FAILURE;
	}
#endif
	fwrite(ENABLE_TERM_ALT_BUF, sizeof(char), strlen(ENABLE_TERM_ALT_BUF), stdout); 

	signal(SIGINT, sigHndl);
	
	int cols = 0;
	int rows = 0;
	
	termSize(&cols, &rows);
	scr = newLeaf(0, 0, cols, rows);
	clrscrL();
#ifndef _WIN32
	setTermios(stdin, FALSE, TERM_IN_RAW);
#endif
	return SUCCESS;
}

int exitL() {
	writeL(DISABLE_TERM_ALT_BUF); 
	writeL(ENABLE_CUR);
	colorL(39, 39);
	updateL();

	delLeaf(scr);
#ifndef _WIN32
	 setTermios(stdin, TRUE, TERM_IN_COOKED); 
#endif
	return SUCCESS;
}
