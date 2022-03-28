#include "../include/leaves.h"

int lborderL(Leaf* l) {
	for (int y = 0; y < l->rows; y++) {
		for (int x = 0; x < l->columns; x++) {
		    if (x == 0 || x == l->columns - 1) {
				lpwriteCHL(l, x, y, '|');
			}

			else if (y == 0 || y == l->rows - 1) {
				lpwriteCHL(l, x, y, '-');
			}
		}
	}

	lpwriteCHL(l, 0, 0, '+');
	lpwriteCHL(l, l->columns - 1, 0, '+');
	lpwriteCHL(l, 0, l->rows - 1, '+');
	lpwriteCHL(l, l->columns - 1, l->rows - 1, '+');

	lcurxyL(l, 0, 0);

	return SUCCESS;
}
