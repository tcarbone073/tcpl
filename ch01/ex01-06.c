/* copy input to output, 1st version */

#include <stdio.h>

int main(void) {
    
    // here, we use a int type to store the current character, rather than a 
    // char type. we need to ensure that any character is large enough to be
    // contained by c, so we use an int to be safe.
    int c;

    c = getchar();

    // 'EOF' is a symbolic constant from the 'stdio.h' library
    while (c != EOF) {
        putchar(c);
        c = getchar();
    }
    return 0;
}
