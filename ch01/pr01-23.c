/* Exercise 1-23: Write a program to remove all comments from a c program. */

#include<stdio.h>

#define OUTSIDE_COMMENT	0
#define INSIDE_COMMENT	1

int main(void) {
	
	int c;
	int state = OUTSIDE_COMMENT;
	int possible = 0;

	while ((c=getchar()) != EOF) {

		if (state == OUTSIDE_COMMENT) {

			/* State 1: Outside of a comment block, and possible entering
			 * comment block.  */
			if (c == '/')
				possible = 1;
			
			else if (possible == 1)

				/* State 2: Outside of a comment block, and confirming that we
				 * have entered a comment block. */
				if (c == '*') {
					state = INSIDE_COMMENT;
					possible = 0;
				}
				
				/* State 3: Outside of a comment block, and it wasn't a
				 * comment, after all. */
				else {
					possible = 0;
					putchar('/');
					putchar(c);
				}
			
			/* State 4: Outside of a comment block, and not possibly entering a
			 * comment block. */
			else
				putchar(c);
		}

		else if (state = INSIDE_COMMENT) {

			/* State 5: Inside of a comment block, and possible exiting the
			 * comment block. */
			if (c == '*')
				possible = 1;

			/* State 6: Inside of a comment block, and confirming that we have
			 * exited the comment block. */
			else if (possible = 1 && c == '/') {
				state = OUTSIDE_COMMENT;
				possible = 0;
			}

			/* State 7: No code needed for this state, but here we are inside
			 * of a comment block and are not printing anything to the screen. */
		}
	}

	return 0;
}
