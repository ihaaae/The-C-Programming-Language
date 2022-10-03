#include <stdio.h>

// return number of lines of *input*
int line_count() {
    int c, nl;

    nl = 0;
    while((c = getchar()) != EOF) {
        if(c == '\n') {
            ++nl;
        }
    }

    return nl;
}

int blank_tab_line_cout() {
    int c, nb, nt, nl;

    nb = 0;
    nt = 0;
    nl = 0;

    while((c = getchar()) != EOF) {
        if(c == '\n') {
            ++nl;
        }
        else if(c == ' ') {
            ++nb;
        }
        else if(c == '\t') {
            ++nt;
        }
    }

    return nl;
}