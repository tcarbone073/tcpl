/* counts blanks, tabs, and newlines in a file */

#include <stdio.h>

int main(void) {
    
    // declare blank count, tab count, and line count variables
    int bc, tc, lc, c;

    bc = tc = lc = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ')
            ++bc;
        else if (c == '\t')
            ++tc;
        else if (c == '\n')
            ++lc;
    }

    printf("blanks = %d, tabs = %d, lines = %d\n", bc, tc, lc);

    return 0;
}
