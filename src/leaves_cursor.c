#include "../include/leaves.h"

int showCurL(int status) {
	if(status == FALSE)
		return appendToLeaf(scr, DISABLE_CUR);
	else if(status == TRUE)
		return appendToLeaf(scr, ENABLE_CUR);
	else
		return FAILURE;
}

int lcurxyL(Leaf* l, int x, int y) {
	if(x < 0 || y < 0 || x > l->columns - 1 || y > l->rows - 1) return FAILURE;

	l->cur_cols = x;
	l->cur_rows = y;

	return appendToLeaf(l, "\x1b[%d;%dH", l->pos_rows + y + 1, l->pos_columns + x + 1);
}
