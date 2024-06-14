/* Prints a histogram of the lengths of each word in the input. */

#include <stdio.h>

#define ARRLEN 10

int main()
{
    int wordLengths[ARRLEN + 1];
    int c, i, j, count, isBlank;
    count = isBlank = 0;

    printf("This program will print a histogram of the lengths of each word in the input.\n\n");
    printf("Enter in words separated by spaces, then press Enter and EOF command to print the histogram. Each word must be no greater than %d characters long.\n\n", ARRLEN);

    /* Set each index in the array to 0 */
    for (i = 1; i <= ARRLEN; ++i)
        wordLengths[i] = 0;

    /* Keep track of word lengths until EOF is inputed */
    while ((c = getchar()) != EOF)
        if ((c == ' ' || c == '\n' || c == '\t' || c == '\r') && isBlank == 0) {
            ++wordLengths[count];
            isBlank = 1;
            count = 0;
        }
        else if (c != ' ' && c != '\n' && c != '\t' && c != '\r') {
            ++count;
            isBlank = 0;
        }

    /* Update the last word if there was one */
    if (count > 0)
        ++wordLengths[count];

    /* Print the histogram */
    printf("\nWord lengths, where each dash represents one word of the given length.\n");
    for (i = 1; i <= ARRLEN; ++i) {

        if (i == 1)
            printf("%2d   char:  ", i);
        else
            printf("%2d  chars:  ", i);

        for (j = 0; j < wordLengths[i]; ++j)
            printf(" -");

        printf("\n");
    }

    return 0;
}
