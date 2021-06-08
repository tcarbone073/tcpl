/* print Celsius-Fahrenheit table */

#include <stdio.h>

int main(void) {
    
    float fahr, cels;
    int lower, step, upper;

    lower = 0;
    step = 20;
    upper = 200;

    printf(" Cels   Fahr \n");
    printf("------ ------\n");

    cels = lower;
    while (cels <= upper) {
        fahr = ((9.0/5.0) * cels) + 32.0;
        printf("%6.0f %6.1f\n", cels, fahr);
        cels += step;
    }

    return 0;
}
