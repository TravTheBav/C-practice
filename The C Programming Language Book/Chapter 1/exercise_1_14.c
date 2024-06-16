/* Prints a histogram of the frequencies of different characters in the input. */


#include <stdio.h>

/* 94 visible characters in the Standard ASCII chart, not including space */
#define ARRLEN 94
#define OFFSET 33

int main()
{
    int frequencies[ARRLEN];
    int c, i, j;

    printf("This program will print a histogram of the frequencies of each character in the input.\n\n");
    printf("When you are done typing in the input, press ENTER and CTRL+D to print the histogram.\n");
    printf("Each dash represents one occurrence of the given character.\n");

    /* Set each index in the array to 0 */
    for (i = 0; i < ARRLEN; ++i)
        frequencies[i] = 0;

    /* Update frequencies for each char until EOF */
    while ((c = getchar()) != EOF) {
        ++frequencies[c - OFFSET];
    }

    /* Print the histogram */
    for (i = 0; i < ARRLEN; ++i) {
        putchar(i + OFFSET);
        printf(":");

        for (j = 0; j < frequencies[i]; ++j)
            printf(" -");

        printf("\n");
    }

    return 0;
}
