/* Copies input to output and replaces: tabs with "/t", backslashes with "//", and newlines with "/n". */

#include <stdio.h>

#define BACKSLASH '\\'

main()
{
    int c;

    while ((c = getchar()) != EOF)
        if (c == '\n') {
            putchar(BACKSLASH);
            putchar('n');
        }
        else if (c == '\t') {
            putchar(BACKSLASH);
            putchar('t');
        }
        else if (c == BACKSLASH) {
            putchar(BACKSLASH);
            putchar(BACKSLASH);
        }
        else {
            putchar(c);
        }
}
