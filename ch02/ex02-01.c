/* Exercise 2-1: Write a program to determine the ranges of 'char', 'short',
 * 'int', and 'long' variables, both 'signed' and 'unsigned', by printing
 * appropriate values from standard headers and by direct computation. Harder
 * if you compute them: determine the ranges of various floating-point types. */

#include<stdio.h>
#include<limits.h>
#include<float.h>

int main(void) {

	printf("  %s\t%d %s\n", "CHAR_BIT", CHAR_BIT, "bits in a 'CHAR'");
	printf("  %s\t%d %s\n", "CHAR_MAX", CHAR_MAX, "max value of a 'CHAR'");
	printf("  %s\t%d %s\n", "CHAR_MIN", CHAR_MIN, "min value of a 'CHAR'");

	return 0;
}
