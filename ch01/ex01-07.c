/* count characters in input - 1st version */

#include <stdio.h>

int main(void) {

    long nc;

    nc = 0;
    while (getchar() != EOF) {

        // here, we use the prefix increment operator
        ++nc;
    }
    printf("%1d\n", nc);

    return 0;
}
