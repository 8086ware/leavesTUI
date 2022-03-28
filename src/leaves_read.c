#include "../include/leaves.h"

char inChL() {	
#ifdef _WIN32
	return _getch();
#else
	char byteread = 0;
	
	if(fread(&byteread, sizeof(char), 1, stdin) < 1) return 0;
	
	return byteread;
#endif
}
