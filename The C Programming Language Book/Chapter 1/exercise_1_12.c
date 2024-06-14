/* Prints input one word per line. */

#include <stdio.h>

main()
{
    int c, isSpace;
    isSpace = 0;

    while((c = getchar()) != EOF)
        /* put a newline to output once between words; consecutive empty spaces are ignored */
        if (c == ' ' && isSpace == 0) {
            putchar('\n');
            isSpace = 1;
        }
        else if (c != ' ') {
            putchar(c);
            isSpace = 0;
        }
}
