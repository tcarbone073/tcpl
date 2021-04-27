/* copy input to output, verifying that EOF is not reached  */

#include <stdio.h>

int main(void) {
    
    // here, we use a int type to store the current character, rather than a 
    // char type. we need to ensure that any character is large enough to be
    // contained by c, so we use an int to be safe.
    int c;
    int b;

    c = getchar();

    // 'EOF' is a symbolic constant from the 'stdio.h' library
    while (c != EOF) {

        // to verify that c = getchar() = 0 or 1, print for each word
        b = (c != EOF);
//        putchar(bc);
        printf("%i\n", b);
        c = getchar();
    }
    return 0;
}
