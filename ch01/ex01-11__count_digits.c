/* count digits, white space, others */

#include <stdio.h>

int main(void) {
    
    int c, i, nwhite, nother;
    int ndigit[10];

    // initialize all to zero
    nwhite = nother = 0;
    for (i = 0; i < 10; ++i)
        ndigit[i] = 0;
 
    while ((c = getchar()) != EOF)

        /* here, we test if the value of the character is between 30 and 39
         * (i.e., ascii values for 0 thru 9). this is implied becuase c is
         * declared to be an int. the value of c minus the ascii value for 0
         * (30) yields the value of the digit. then, its place in the array is
         * increased by one. */
        if (c >= '0' && c <= '9')
            ++ndigit[c-'0'];

        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else
            ++nother;

    printf("digits = ");
    for (i = 0; i < 10; ++i)
        printf(" %d", ndigit[i]);
    printf(", white space = %d, other = %d\n", nwhite, nother);

    return 0;
}
