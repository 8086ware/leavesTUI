#include "../include/leaves.h"
#ifndef _WIN32
#include <termios.h>

int setTermios(FILE* fOperator, int ECHOMODE, int INMODE) {
	struct termios term;
	
	tcgetattr(fileno(fOperator), &term);
	
	if(ECHOMODE == FALSE) term.c_lflag &= ~ECHO;
	else term.c_lflag |= ECHO;

	if(INMODE == TERM_IN_RAW) term.c_lflag &= ~ICANON;
	else if(INMODE == TERM_IN_COOKED) term.c_lflag |= ICANON;

	tcsetattr(fileno(fOperator), TCSANOW, &term);

	return SUCCESS;
}
#endif
