/* count lines in input */

#include <stdio.h>

int main(void) {
    
    int c, lc;

    while ((c = getchar()) != EOF) {
        if (c == '\n')
            ++lc;
    }

    printf("%d\n", lc);

    return 0;
}
