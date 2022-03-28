#include "../include/leaves.h"

int appendToLeafCH(Leaf* l, char ch) {
	char* temp = realloc(l->con, l->len + 1);
	if (temp == NULL) exit(1);

	l->con = temp;

	l->len++;
	l->con[l->len - 1] = ch;

	return SUCCESS;
}

int appendToLeaf(Leaf* l, const char* string, ...) {
	char* buffer = malloc(sizeof(string) + BUFSIZ);
	if (buffer == NULL) exit(1);

	va_list args;
	va_start(args, string);
	vsprintf(buffer, string, args);
	va_end(args);
	
	for(int i = 0; i < strlen(buffer); i++) {
		appendToLeafCH(l, buffer[i]);
	}

	return SUCCESS;
}

int lwriteCHL(Leaf* l, char ch) {
	if (l->cur_cols >= l->columns) {		
		int x = 0;
		int y = l->cur_rows + 1;

		l->cur_cols = 0;
		l->cur_rows += 1;

		appendToLeaf(l, "\x1b[%d;%dH", l->pos_rows + y + 1, l->pos_columns + x + 1);

		if (l->cur_rows >= l->rows) {
			return FAILURE;
		}
	}

	l->cur_cols++;
	l->char_len++;

	return appendToLeafCH(l, ch);
}

int lwriteL(Leaf* l, const char* string, ...) {
	char* buffer = malloc(sizeof(string) + BUFSIZ);
	if (buffer == NULL) exit(1);

	va_list args;
	va_start(args, string);
	vsprintf(buffer, string, args);
	va_end(args);

	for (int i = 0; i < strlen(buffer); i++) {
		if(lwriteCHL(l, buffer[i]) == FAILURE) break;
	}

	return SUCCESS;
}
