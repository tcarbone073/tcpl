/* Write a program that prints its input one word per line. */

#include <stdio.h>

int main(void) {

    int c, d;

    while ((c = getchar()) != EOF) {

        if (c == ' ' || c == '\n') {

            putchar('\n');

            // if there is more than one sequential space or newline, do
            // nothing until the next non-blank character is encountered
            d = getchar();
            while (d  == ' ' || d == '\n') {
                // do nothing
                d = getchar();
            }

            // print the first non-blank after the string of blanks, otherwise
            // the next 'c' will skip the first letter of the new word
            putchar(d);
        } else
            putchar(c);
    }

    return 0;
}
