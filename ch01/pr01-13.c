/* Write a program to print a histogram of the lengths of words in its input.
 * It is easy to draw the histogram with the bars horizontal;a vertical
 * orientation is more challenging. */

#include <stdio.h>

int main(void) {
    
    /* note that we do not use 0 indexing here, which is strange. mainly
     * becuase there will never be a word with length of 0, so starting at 1 is
     * appropriate. */

    int c, i, j;
    int nletters;
    int wordlen[20];

    c = i = j = nletters = 0;
    for (i = 1; i < 20; ++i)
        wordlen[i] = 0;

    while((c = getchar()) != EOF) {
       if (c == ' ' || c == '\n' || c == '\t') {
           ++wordlen[nletters];
           nletters = 0;
       } else
           ++nletters;
    }

    for (i = 1; i < 20; ++i) {
        printf("%2d: ", i);
        for (j = 1; j <= wordlen[i]; ++j)
            printf("-");
        printf("\n");
    }

    return 0;
}


