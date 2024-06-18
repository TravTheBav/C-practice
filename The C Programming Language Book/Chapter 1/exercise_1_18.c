#include <stdio.h>
#define MAXLINE 251 /* maximum input line size */

int getLine(char line[], int maxline);
void removeBlanks(char to[], char from[]);
void printLine(char line[]);

/* Repeatedly get lines of input an remove any trailing blanks or tabs. */
int main()
{
    int len;                        /* current line length */
    char line[MAXLINE];             /* current input line */
    char formattedLine[MAXLINE];    /* current line with all trailing white spaces removed */

    /* print program instructions */
    printf("\nEnter in strings up to %d characters (including blank spaces) on each line.\n", MAXLINE - 1);
    printf("After pressing ENTER, the string will be printed to the console with all trailing white spaces removed.\n");
    printf("NOTE: any strings over the character limit will be truncated.\n\n");


    while ((len = getLine(line, MAXLINE)) >= 0) {
        removeBlanks(formattedLine, line);
        printLine(formattedLine);
    }
        
    return 0;
}

/* getline: read a line into s, return length */
int getLine(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
        
    if (c == '\n') {
        s[i] = '\n';
        ++i;
    }

    s[i] = '\0';
    
    /* line is at the char limit and the last character on the line is not a newline char */
    if (i == lim - 1 && s[lim - 2] != '\n')
        return i;
    /* line is below the char limit, or the line is at the char limit but the last character is a newline char */
    else
        return i - 1;
}

/* removeBlanks: copy 'from' into 'to', removing any trailing white spaces; assume to is big enough */
void removeBlanks(char to[], char from[])
{
    char c;
    int i, j, isBlank;
    i = j = isBlank = 0;

    while (from[i] != '\n' && from[i] != '\0') {
        c = from[i];

        if (isBlank == 1 && c != '\t' && c != ' ')
            isBlank = 0;

        if (isBlank == 0) {
            to[j] = c;
            ++j;
        }

        if (c == '\t' || c == ' ') {
            isBlank = 1;
        }

        ++i;
    }

    /* add the null terminator */
    if (to[j - 1] == ' ' || to[j - 1] == '\t')
        to[j - 1] = '\0';
    else
        to[j] = '\0';
}

/* printLine: prints out the line to the console */
void printLine(char line[])
{
    int i = 0;
    putchar('\'');

    while (line[i] != '\0') {
        putchar(line[i]);
        ++i;
    }

    putchar('\'');
    putchar('\n');
}