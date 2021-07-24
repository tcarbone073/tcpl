/* Revise the main routine of the longest-line program so it will correctly
 * print the length of arbitrarily long input lines, and as much possible of
 * the text. */

#include <stdio.h>

#define MAXLINE         1000    /* maximum line length */
#define LINE_LEN        15      /* minimum line length that gets printed */
#define LINE_LEN_SHOW   12      /* how much of the line gets printed */

int get_line(char line[], int maxline);

int main(void) {

	int len;
	int c, i;
	char line[MAXLINE];

	for (i=0; i<MAXLINE-1; ++i)
		line[i]=0;
    
    while ((len = get_line(line, MAXLINE)) > 0)
		if (len > LINE_LEN) {
            for (i = 0; i < LINE_LEN_SHOW - 1; ++i)
                printf("%c", line[i]);
			printf("\n");
			}
		else
			printf("<Line not longer than %d characters.>\n", LINE_LEN);
    return 0;
}

int get_line(char s[], int lim) {
	/* Read a line of characters into `s`. If a `\n` is encountered, apend the
	 * null character and return length of the line, `i`. */

    int c, i;

    for (i=0; i<lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
