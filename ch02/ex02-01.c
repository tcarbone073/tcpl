/* Exercise 2-1: Write a program to determine the ranges of 'char', 'short',
 * 'int', and 'long' variables, both 'signed' and 'unsigned', by printing
 * appropriate values from standard headers and by direct computation. Harder
 * if you compute them: determine the ranges of various floating-point types. */

#include<stdio.h>
#include<limits.h>
#include<float.h>

void disp(char type_name[], long size, char desc[]);

int main(void) {
	
	printf("\n");
	disp("CHAR_BIT",  CHAR_BIT,  "bits in a 'char'");
	disp("CHAR_MIN",  CHAR_MIN,  "minimum value of 'char'");
	disp("CHAR_MAX",  CHAR_MAX,  "maximum value of 'char'");
	disp("SCHAR_MIN", SCHAR_MIN, "minimum vlaue of 'signed char'");
	disp("SCHAR_MAX", SCHAR_MAX, "maximum value of 'signed char'");
	disp("UCHAR_MAX", UCHAR_MAX, "maximum value of 'unsigned char'");
	disp("INT_MIN",   INT_MIN,   "minimum value of 'int'");
	disp("INT_MAX",   INT_MAX,   "maximum value of 'int'");	
	disp("UINT_MAX",  UINT_MAX,  "maximum value of 'unsigned int'");
	disp("LONG_MIN",  LONG_MIN,  "minimum value of 'long int'");
	disp("LONG_MAX",  LONG_MAX,  "maximum value of 'long int'");
	disp("ULONG_MAX", ULONG_MAX, "maximum value of 'unsigned long'");
	disp("SHRT_MIN",  SHRT_MIN,  "minimum value of 'short int'");
	disp("SHRT_MAX",  SHRT_MAX,  "maximum value of 'short int'");
	disp("USHRT_MAX", USHRT_MAX, "maximum value of 'unsigned short int'");
	printf("\n");

	return 0;
}

void disp(char type_name[], long size, char desc[]) {
	/* Print as unsigned or signed. */
	if (type_name[0] == 'U')
		printf("%12s%22lu  %s\n", type_name, size, desc);
	else
		printf("%12s%22ld  %s\n", type_name, size, desc);
}
