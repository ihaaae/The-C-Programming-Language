#include <stdio.h>

#define MAXLINE 100

int getline(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while((len = getline(line, MAXLINE)) > 0) {
        if(len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if(max > 0) {
        printf("%s",longest); 
    }

    return 0;
}


// read a line into *s*, return length
int getline(char s[], int lim)
{
    int c, i;

    for(i = 0; i < (lim - 1) && (c = getchar()) != EOF && c != '\n'; i++) {
        s[i] = c;
    }
    if(c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void copy(char from[], char to[])
{
    for(int i = 0; (to[i] = from[i]) != '\0'; i++) {
    }
}

// 1.16
void print_line_length()
{

    char line[MAXLINE];

    int max = 0;
    int len = 0;
    while((len = getline(line, MAXLINE)) > 0) {
        printf("%d", len);
    }
}

// 1.17
void print_line_80()
{
    int len;
    char line[MAXLINE];
    while((len = getline(line, MAXLINE)) > 80) {
        printf("%s", line);
    }
}

// 1.18
void erase_blank()
{
    
}