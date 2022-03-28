#include "../include/leaves.h"

Leaf* scr;

Leaf* newLeaf(int x, int y, int columns, int rows) {
	if(x < 0 || y < 0) return NULL;

	Leaf* temp = malloc(sizeof(Leaf));
	if (temp == NULL) exit(1);

	temp->columns = columns;
	temp->rows = rows;
	
	temp->pos_columns = x;
	temp->pos_rows = y;

	temp->con = malloc(0);

	if (temp->con == NULL) exit(1);

	temp->cur_cols = 0;
	temp->cur_rows = 0;

	temp->len = 0;
	temp->char_len = 0;

	lcurxyL(temp, 0, 0);
	lcolorL(temp, 39, 39);	
	
	return temp;
}

int delLeaf(Leaf* l) {
	free(l->con);
	free(l);
	
	return SUCCESS;
}
