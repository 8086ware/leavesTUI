#include "../include/leaves.h"

int lclrmemL(Leaf* l) {
	free(l->con);
	
	l->con = malloc(0);

	if(l->con == NULL) return FAILURE;
	
	l->cur_cols = 0;
	l->cur_rows = 0;
	
	l->len = 0;
	l->char_len = 0;

	lcurxyL(l, 0, 0);
	
	return SUCCESS;
}

int clrscrL() {
	return appendToLeaf(scr, CLEAR_SCR);
}
