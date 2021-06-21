/* print Fahrenheit-Celsius table - floating-point version
 * using for loop, in reverse order from 300 to 0 
 * ... this time using a function */

#include <stdio.h>

float fahr2cels(int fahr);

int main(void) {

    int fahr;
    
    for (fahr = 300; fahr >= 0; fahr -= 20) {
        printf("%3d%6.1f\n", fahr, fahr2cels(fahr));
    }

    return 0;
}


/* return Fahrenheit from a Celsius input  */
float fahr2cels(int fahr) {
    return (5.0/9.0)*(fahr-32);
}
