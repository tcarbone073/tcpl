/* count characters in input - 2nd version */

#include <stdio.h>

int main(void) {

    double nc;

    nc = 0;
    while (getchar() != EOF) {

        // here, we use the prefix increment operator
        ++nc;
    }
    printf("%.0f\n", nc);

    return 0;
}
