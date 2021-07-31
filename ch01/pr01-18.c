/* Exercise 1-18: Write a program to remove trailing blanks and tabs from each
 * line of input, and to delete entirely blank lines. */

#define MAXLINE	100

#include <stdio.h>

int get_line(char[], int);
void trim_ws(char[], char[], int);
int is_blank_line(char[], int);

int main(void) {

	int c, i;
	int len;					/* length of line */
	char line[MAXLINE];			/* current line */
	char line_no_ws[MAXLINE];	/* current line, trailing whitespace removed */

	while ((len = get_line(line, MAXLINE)) > 0) {
		trim_ws(line, line_no_ws, len);

		if (is_blank_line(line_no_ws, len) == 0)
			printf("%s", line_no_ws);
	}	

	return 0;
}


int get_line(char s[], int lim) {
	/* 
	 * Copies the current line of a file into `s`, including a trailing `\n`
	 * and `\0`. The length of the string is returned. Note the length of the
	 * string includes `\n` as a character of the array, as it should.
	 */
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


void trim_ws(char s[], char new_s[], int len) {
	/* 
	 * Trims whitespace by replacing all whitespace (e.g., \t, \n, ' ', or \0)
	 * at the end of a line with '\n\0'.
	 */

	int i;
	int stop;

	/* Here, we iterate backwards thru the line moving right to left. If we
	 * encounter any character that isn't a whitespace, we save the index in
	 * `stop` and break out of the loop. */
	stop = 0;
	for (i=len-1; i>=0; --i)
		if (s[i] != '\t' && s[i] != ' ' && s[i] != '\n' && s[i] != '\0') {
			stop = i;
			break;
		}

	/* Next, we iterate from the beginning of the line to the `stop` index,
	 * copying each character into the array `new_s`. Lastly, we append the null
	 * character to the end of the array.  */
	for (i=0; i<=stop; ++i)
		new_s[i] = s[i];	
	new_s[i] = '\n';
	++i;
	new_s[i] = '\0';
}


int is_blank_line(char s[], int len) {
	/* 
	 * Returns 1 if `s` contains no visible characters.
	 * Returns 0 is `s` contains only whitespace.
	 */
	int i, is_blank;

	is_blank = 1;
	for (i=0; i<len; ++i)
		if (s[i] != '\t' && s[i] != ' ' && s[i] != '\n' && s[i] != '\0') {
			is_blank = 0;
			break;
		}

	return is_blank;

}
