/* A function to convert Farenheit to Celsius */


#include <stdio.h>

/* convertTemp: convert Farenheit temp to Celsius and return the Celsius temp  */
int convertTemp(int fahr)
{
    int celsius;
    celsius = 5 * (fahr - 32) / 9;
    
    return celsius;
}

int main()
{
    printf("F: %d, C: %d\n", 32, convertTemp(32));
    printf("F: %d, C: %d", 212, convertTemp(212));
}
