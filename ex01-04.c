/* print Fahrenheit-Celsius table - floating-point version
 * using for loop */

#include <stdio.h>

int main(void) {
    
    int fahr;
    
    // for loop:
    //  fahr = 0        done only once, before the loop begins
    //  fahr <= 300     evaluate BEORE the loop begins
    //  fahr += 20      performed AFTER each loop iteration
    for (fahr = 0; fahr <= 300; fahr += 20) {
        printf("%3.0f%6.1f\n", fahr, (5.0/9.0)*(fahr-32));
    }

    return 0;
}
