/* Copies input to output, replacing each string of one or more blanks by a single blank. */

#include <stdio.h>

main()
{
    int c;
    int isBlank;
    isBlank = 0;

    while ((c = getchar()) != EOF)
        if (c == ' ' && isBlank == 0) {
            isBlank = 1;
            putchar(' ');
        }
        else if (c != ' ') {
            isBlank = 0;
            putchar(c);
        }
}
