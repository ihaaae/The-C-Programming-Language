#include <stdio.h>
#include <ctype.h>
// #include "getch.c"

int getch();
void ungetch(int);

// 5.1
int getint_fixed(int *pn)
{
    int c, sign;

    while(isspace(c = getch())) {
        ;
    }

    if(!isdigit(c) || c != '+' || c != '-' || c != EOF) {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;

    if(c == '+' || c == '-') {
        c = getch();
    }
    else if(isdigit(c)) {
        *pn = c;
    }
    else {
        return 0;
    }

    for(; isdigit(c); c = getch()) {
        *pn = *pn * 10 + (c - '0');
    }

    *pn = *pn * sign;

    if(c != EOF) {
        ungetch(c);
    }

    return c;
}

int getfloat(float *pn)
{

}