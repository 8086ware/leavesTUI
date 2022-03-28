#include "../include/leaves.h"

int lupdateL(Leaf* l) {
	if(fwrite(l->con, sizeof(char), l->len, stdout) != l->len) {
		return FAILURE;
	}

	fflush(stdout);
	
	return SUCCESS;
}
