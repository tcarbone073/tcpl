/* Exercise 1-19: Write a function reverse(s) that reverses the character
 * string s. Use it to write a program that reverses its input a line at a
 * time. */

#include <stdio.h>

#define MAXLINE 100

int get_line(char[], int);
void reverse(char[], char[], int);

int main(void) {

	int c, i;
	int len;
	char line[MAXLINE];
	char rline[MAXLINE];

	while ((len = get_line(line, MAXLINE)) > 0) {
		reverse(line, rline, len);
		printf("%s", rline);
	}

	return 0;
}


int get_line(char s[], int lim) {

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

void reverse(char s[], char rs[], int len) {
	/* 
	 * Input string `s` is printed in reverse order into `rs`. Note that this
	 * functions assumes `s`, ends with a newline '\n' and a null '\0'
	 * character.
	 */

	int i, j;

	/* This algoroithm is not obvious. We start by simply looping thru the
	 * character array `s` like normal. However, becuase we are looking to
	 * oreverse the array, we need to establish a reverse index, `j`. Because
	 * we do not want to print the final '\n' from `s`, we establish the
	 * reverse index from `len-2` in lieu of `len-1`.
	 * */
	for (i=0; i<len-1; ++i) {
		j = len-2-i;
		rs[i] = s[j];
	}
	rs[i] = '\n';
	++i;
	rs[i] = '\0';
}
