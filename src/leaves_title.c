#include "../include/leaves.h"

int setTitleL(const char* title) {
	return appendToLeaf(scr, "%c]0;%s%c", '\033', title, '\007');
}
