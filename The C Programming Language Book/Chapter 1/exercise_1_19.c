#include <stdio.h>
#define MAXLINE 251 /* maximum input line size */

int getLine(char line[], int maxline);
void printLine(char line[]);
void reverse(char to[], char from[], int len);

/* Repeatedly get lines of input and reverses them. */
int main()
{
    int len;                        /* current line length */
    char line[MAXLINE];             /* current input line */
    char reversed[MAXLINE];         /* reversed input */

    /* print program instructions */
    printf("\nEnter in strings up to %d characters (including blank spaces) on each line.\n", MAXLINE - 1);
    printf("After pressing ENTER, the string will be reversed and printed to the console.\n");
    printf("Press CTRL-D to quit.\n\n");

    while ((len = getLine(line, MAXLINE)) >= 0) {
        reverse(reversed, line, len);
        printLine(reversed);
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

/* printLine: prints out the line to the console */
void printLine(char line[])
{
    int i = 0;

    while (line[i] != '\0') {
        putchar(line[i]);
        ++i;
    }

    putchar('\n');
}

/* reverse: reverses the characters in 'from' and copies them to 'to'. len == the length of 'from' */
void reverse(char to[], char from[], int len)
{
    int left, right;
    right = len - 1;

    for (left = 0; left < len; ++left) {
        to[left] = from[right];
        --right;
    }
    
    to[left] = '\0';
}