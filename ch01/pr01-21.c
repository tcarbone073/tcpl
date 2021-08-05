/* Exercise 1-21: Write a program `entab` that replaces strings of of blanks by
 * the maximum number of tabs and blanks to achieve the same spacing. Use the
 * same tab stops as for `detab`. When either a tab of a single blank would
 * suffice to reach a tab stop, which should be given preference? */

#include <stdio.h>

#define NBLANKS	4 /* number of blanks per tab */

int main(void) {

	int c, i, n_blanks;

	n_blanks = 0;

	while ((c = getchar()) != EOF) {

		/* If the character is a blank, increment the blank space counter.
		 * If this is the NBLANK'th blank in a row, print a tab and reset
		 * the blank counter. */
		if (c == ' ') {
			++n_blanks;
			if (n_blanks == NBLANKS) {
				putchar('\t');
				n_blanks = 0;
			}
		}

		/* If the character is not a blank, print however many blanks have been
		 * encountered thus far, then print the character. Lastly, reset the
		 * blank counter to zero. */
		else {
			for (i=0; i<n_blanks; ++i)
				putchar(' ');
			putchar(c);
			n_blanks = 0;
		}
	}

	return 0;
}
