/* print Fahrenheit-Celsius table - floating-point version
 * WITH a header */

#include <stdio.h>

int main(void) {
    
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    // print column headers
    printf(" Fahr     Cels \n");
    printf("------   ------\n");

    fahr = lower;
    while (fahr <= upper) {

        // calculation
        celsius  = (5.0/9.0) * (fahr-32.0);

        // print
        printf("%6.0f   %6.1f\n", fahr, celsius);

        // next fahr
        fahr = fahr + step;
    }

    return 0;
}
