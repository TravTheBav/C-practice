#include <stdio.h>
#include <string.h>

#define MAXLINE 10
long htoi(char hexStr[]);

/* prompts user for a hexadecimal string and converts it to a decimal value */
int main()
{
    char hexStr[MAXLINE];
    long decimal;

    /* print program instructions */
    printf("\nEnter a hexadecimal string up to %d characters.\n", MAXLINE - 1);
    printf("After pressing ENTER, the string will be converted to a decimal and printed to the console.\n");
    printf("A '0x' or '0X' prefix is optional and will not affect the result.\n\n");

    fgets(hexStr, MAXLINE, stdin);
    decimal = htoi(hexStr);
    printf("%ld\n", decimal);

    return 0;
}

/* htoi: takes in a string representing a hex number, and converts it to its decimal value. String
        may begin with '0x' or '0X' but is not required. */
long htoi(char hexStr[])
{
    int len, i;
    long n;
    len = strlen(hexStr) - 1;

    /* move start index by 2 if there is a '0x' or '0X' hexadecimal prefix */
    if (len >= 2 && hexStr[0] == '0' && (hexStr[1] == 'x' || hexStr[1] == 'X'))
        i = 2;
    else
        i = 0;

    /* calculate the decimal value */
    n = 0;
    for (; i < len; ++i) {
        if (hexStr[i] >= '0' && hexStr[i] <= '9')
            n = 16 * n + (hexStr[i] - '0');
        else
            n = 16 * n + (hexStr[i] - 55);
    }

    return n;
}
