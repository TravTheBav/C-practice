#include <stdio.h>

main()
{
    int c, blanks, tabs, newlines;
    blanks = tabs = newlines = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ')
            ++blanks;
        else if (c == '\t')
            ++tabs;
        else if (c == '\n')
            ++newlines;
    }

    printf("Blanks count: %d\n", blanks);
    printf("Tabs count: %d\n", tabs);
    printf("Newlines count: %d\n", newlines);
}



