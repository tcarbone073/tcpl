/* Bare bones version of the UNIX program 'wc' */

#include <stdio.h>

#define IN  1
#define OUT 0

/* count lines, words, and characters in input */
int main(void) {
    
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("lines\twords\tcharacters\n");
    printf("%d\t%d\t%d\n", nl, nw, nc);

    return 0;
}
