/* copy input to output, replacing strings of blanks with a single blank */

#include <stdio.h>

int main(void) {
    
    int c, d;

    while ((c = getchar()) != EOF) {

        // print the character to the console
        putchar(c);

        // if the character is space
        if (c == ' ') {
            while ((d = getchar()) == ' ') {
                 // do nothing unil there are no more spaces
            }

            // at this point, 'd' is a character that is NOT a space. we need
            // to put it to the screen, otherwise the next iteration of the 
            // loop using 'c' will get the next chacter. effectively, without
            // this line, the first letter of each word is skipped.
            putchar(d);
        }
    }

    return 0;
}
