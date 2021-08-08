/* Exercise 1-22: Write a program to "fold" long input lines into two or more
 * shorter lines after the last non-blank character that occurs before the n-th
 * column of input. Make sure your program does something intelligent with very
 * long lines, and if there are no blanks or tabs before the chosen column
 * width. */

#include<stdio.h>

#define LIM		50
#define TAB		4
#define MAXLINE	90

int get_line(char[], int);
int get_indent(char[], char[], int);
int enum_indent(char[], int);
int get_chunk(char[], char[], int, int);

int main(void) {

	int linelen;
	int indent_ascii_len;
	int indent_print_len;
	int wordstart;
	int col;
	int chunk_ascii_len;
	int chunk_print_len;

	char line[MAXLINE];
	char indent[MAXLINE];
	char word[MAXLINE];

	/* Read each line of text from stdin into `line` */
	while ((linelen = get_line(line, MAXLINE)) > 0) {

		/* Copy any leading tabs of spaces into `indent`, returning the length
		 * of the leading indent into `indent_ascii_length`. Note that this
		 * length treats each ASCII value as a single character (i.e., '\t'
		 * counts as 1). Print the leading indent. */
		indent_ascii_len = get_indent(line, indent, linelen);
		printf("%s", indent);

		/* Return the actual length of the leading indent (i.e., '\t' counts
		 * for however many blank spaces one tab stop is worth)  */
		indent_print_len = enum_indent(indent, indent_ascii_len);

		/* We keep track of the current column being printed using `col`. Set
		 * it to the width of the leading indent, initially. */
		col = indent_print_len;

		/* We  keep track of the index of each word in the line with
		 * `wordstart`, which is also initially set to the width of the leading
		 * indent. */
		wordstart = indent_ascii_len;

		/* word-reading loop */	
		while (1) {

			/* Moving from left to right along the current line, read the chunk
			 * beginning at index `wordstart` into `word`. In this application,
			 * a chunk is a single blank or special character ('\t', ' ', or
			 * '\n') or any string of non-special characters, each appended
			 * with '\0' to form a string. The length of the chunk is returned
			 * as `chunk_ascii_length`. Again, \t counts as one. */
			chunk_ascii_len = get_chunk(line, word, wordstart, linelen);

			/* If we read a '\n', we are at the end of the line. Break out of
			 * the word-reading loop. */
			if (word[0] == '\n') {
				putchar('\n');
				break;
			}

			/* If the chunk is a tab, resolve the length of a tab stop as the
			 * print length. Otherwise, the length of the chuck is the same as
			 * the ASCII length. */
			if (word[0] == '\t')
				chunk_print_len = TAB;
			else
				chunk_print_len = chunk_ascii_len;

			/* If the column counter plus the length of the chuck exceeds the
			 * column limit, print a newline, print the leading indentation,
			 * and reset the column counter. */
			if (col + chunk_print_len > LIM) {
				putchar('\n');
				printf("%s", indent);
				col = indent_print_len;
			}

			/* Finally, print the chuck. */	
			printf("%s", word);

			/* Increment counters. Reminder that `wordstart` is tracking the
			 * leading index of each word in the current line, and `col` is
			 * tracking the current column that has been printed. */
			wordstart += chunk_ascii_len;
			col += chunk_print_len;
		}
	}

	return 0;
}


int get_line(char s[], int lim) {
	/* 
	 * Read the current line from stdin into `s`, returning the length of the
	 * line.
	 */

    int c, i;

    for (i=0; i<lim-1 && (c=getchar()) != EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}


int get_indent(char line[], char indent[], int len) {
	/* 
	 * Reading from left to right along the string `line`, copy all leading
	 * blank space (tabs and spaces) into `indent`, returning the number of
	 * ASCII characters that comprised the indentation string. 
	 */
	int i;


	for (i=0; i<len-1; ++i) {
		if (line[i] == '\t' || line[i] == ' ')
			indent[i] = line[i];
		else {
			indent[i] = '\0';
			break;
		}
	}

	return i;
}


int enum_indent(char indent[], int indent_ascii_len) {
	/* 
	 * Return the number of columns taken by `indent` when it is printed.
	 */
	int i;
	int indent_print_len;

	indent_print_len = 0;
	for (i=0; i<indent_ascii_len; ++i)
		if (indent[i] == '\t')
			indent_print_len += TAB;
		else
			indent_print_len += 1;

	return indent_print_len;
}


int get_chunk(char line[], char word[], int n, int linelen) {
	/* 
	 * Reading from left to right along the string `line`, copy the chunk that
	 * begins at index `n`, returning the length of the chunk. In this context,
	 * a chunk is a string consisting of a blank, tab, or newline appended with
	 * a null character, or a continuous string of non-blank characters,
	 * appended with a null character.
	 *
	 * Ex:	Chunks of "The quick brown  dog." are: "The\0", " \0", "quick\0",
	 * " \0", "brown\0", " \0", " \0", "dog.\0"
	 */
	int c, i;
	int len;


	if (line[n] == '\t' || line[n] == ' ' || line[n] == '\n') {
		word[0] = line[n];
		word[1] = '\0';
		len = 1;
	}


	/* Start indexing `line` at teh start of the current chucnk, `n`. */
	else {
		for (i=n; i<linelen-1; ++i)
			if (line[i] != '\t' && line[i] != ' ' && line[i] != '\n')
				word[i-n] = line[i];
			else
				break;

		word[i-n] = '\0';
		len = i-n;
	}

	return len;
}
