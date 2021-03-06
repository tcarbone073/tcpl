/* print Fahrenheit-Celsius table - floating-point version
 * using for loop and symbolic constants */

#include <stdio.h>

// these are constants
#define LOWER   0
#define UPPER   300
#define STEP    20

int main(void) {
    
    int fahr; 

    for (fahr = LOWER; fahr <= UPPER; fahr += STEP) {
        printf("%3.0f%6.1f\n", fahr, (5.0/9.0)*(fahr-32));
    }

    return 0;
}
