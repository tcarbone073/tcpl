/* print Fahrenheit-Celsius table - integer version */

#include <stdio.h>

int main(void) {
    
    int fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    while (fahr <= upper) {

        // note here that we use the syntax of multiplying by 5 then dividing
        // 9 at the end. this is becuase integer arithmatic is truncated. if 
        // we used 5/9, it would be truncated to zero
        celsius  = 5 * (fahr-32) / 9;

        // the notation of '%3' and '%6' indicate that the formatted text
        // consumes 3 or 6 digits wide and is right-justified in their field
        printf("%3d\t%6d\n", fahr, celsius);
        fahr = fahr + step;
    }

    return 0;
}
