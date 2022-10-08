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
    int c;
    float sign, power = 1.0;
    while(isspace(c = getch())) {
        ;
    }
    if(!isdigit(c) && c != '+' && c != '-' && c != EOF) {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1.0 : 1.0;

    if(c == '+' || c == '-') {
        c = getch();
    }
    else if(isdigit(c)) {
        *pn = c - '0';
    }
    else {
        return 0;
    }

    for(;isdigit(c); c = getch()) {
        *pn = *pn * 10.0 + (c - '0');
    }

    if(c == '.') {
        c = getch();
    }
    else {
        return c;
    }

    for(; isdigit(c); c = getch()) {
        *pn = *pn * 10.0 + (c - '0');
        power *= 10.0;
    }

    *pn = *pn / power * sign;

    if(c != EOF) {
        ungetch(c);
    }

    return c;
}