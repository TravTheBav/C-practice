#include <stdio.h>
#define MAXLINE 81 /* maximum input line size */

int getLine(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
int main()
{
    int len;                /* current line length */
    int max;                /* maximum length seen so far */
    char line[MAXLINE];     /* current input line */
    char longest[MAXLINE];  /* longest line saved here */

    /* print program instructions */
    printf("\nThis program will find the longest input string and print its character count.\n");
    printf("Enter in strings up to %d characters (including blank spaces) on each line.\n", MAXLINE - 1);
    printf("When you are finished, press ENTER and CTRL-D to get the results.\n");
    printf("NOTE: any strings over the character limit will be truncated. The first string to reach the limit will be the one in the result.\n\n");

    max = 0;
    while ((len = getLine(line, MAXLINE)) >= 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0)        /* there was a line */
        printf("\nmax length: %d\n", max);
        printf("string: %s\n", longest);
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

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}