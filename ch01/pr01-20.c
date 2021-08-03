/* Exercise 1-20: Write a program `detab` that replaces tabs in the input with
 * the appropriate number of blanks to space to the next tab stop. Assume a
 * fixed set of tab stops, say every n columns. Should n be a variable or
 * symbolic constant? */

#include <stdio.h>

#define NBLANKS	4 /* number of banks equalling one tab */

int main(void) {

	int c, i;

	while ((c=getchar()) != EOF) {
		if (c == '\t')
			for (i=0; i<NBLANKS; ++i)
				putchar(' ');
		else
			putchar(c);
	}

	return 0;
}

