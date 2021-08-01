/* print the longest line of a text file input */

#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

int max;
char line[MAXLINE];
char longest[MAXLINE];

int get_line(void);
void copy(void);


/* print the longest input line */
int main(void) {
    
    int len;                /* current line length */
	extern int max;
	extern char longest[];

    max = 0;
    while ((len = get_line()) > 0)
        if (len > max) {
            max = len;
            copy();
        }
    
    if (max > 0)
        printf("%s", longest);

    return 0;
}


/* getline: read a line into `s`, return length */
int get_line(void) {

    int c, i;
	extern char line[];

    for (i = 0; i < MAXLINE- 1 && (c=getchar()) != EOF && c!='\n'; ++i)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

/* copy: copy `from` into `to`: assume `to` is big enough */
void copy() {
    
    int i;
	extern char line[], longest[];

    i = 0;
    while ((longest[i] = line[i]) != '\0')
        ++i;
}

