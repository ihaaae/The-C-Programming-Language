#include <stdio.h>

#define IN 1
#define OUT 0

void ch_w_l_count() {
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;
    while((c = getchar()) != EOF) {
        ++nc;
        if(c == '\n') {
            ++nl;
        }
        if(c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
        }
        else if(state == OUT) {
            state = IN;
            ++nw;
        }
    }

    printf("%d  %d  %d\n", nc, nw, nl);
}

// 1.12
void print_word() {
    int c, state;

    state = OUT;
    while((c = getchar()) != EOF) {
        if(c == ' ' && state == OUT) {

        }
        else if(c == ' ' && state == IN) {
            putchar('\n');
            state = OUT;
        }
        else if(state == OUT) {
            putchar(c);
            state = IN;
        }
        else {
            putchar(c);
        }
    }
}