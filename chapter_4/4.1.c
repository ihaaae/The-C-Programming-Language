#include <stdio.h>
#include <string.h>
#define MAXLINE 100

int strindex(char source[], char searchfor[]);
int match(char souce[], int start, char searchfor[]);

int match(char s[], int start, char t[])
{
    int i = start;
    int j = 0;
    for(; t[j] != '\0' && s[i] == t[j]; i++, j++) {
    }

    if(t[j] == '\0') {
        return 1;
    }

    return -1;
}

// return index of *t* in *s*, return -1 if none
int strindex_r(char t[], char s[])
{
    for(int i = strlen(s); i >= 0; i--) {
        if(match(s, i, t) == 1) {
            return i;
        }
    }

    return -1;
}