#include "../include/leaves.h"

int lcolorL(Leaf* l, int FG, int BG) {
	return appendToLeaf(l, "\x1b[0;%d;%dm", BG, FG);
}
