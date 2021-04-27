/* print Fahrenheit-Celsius table - floating-point version */

#include <stdio.h>

int main(void) {
    
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    while (fahr <= upper) {

        // here, a decimal point indicates that the value is a floating-point, 
        // and arithmetic will not not truncate. if a operation has one
        // integer operand and one floating-point operand, the integer operand
        // will be converted to a floating-point. thus, writing 32.0 is 
        // actually redundant, since the 'fahr' is a float; however, we write 
        // 32.0 to be obvious in our intentions
        celsius  = (5.0/9.0) * (fahr-32.0);

        // here, the formatted text inludes'.0' and '.1' modifiers, which
        // indicate how many decimal places of precision the float is formatted
        // to
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }

    return 0;
}
