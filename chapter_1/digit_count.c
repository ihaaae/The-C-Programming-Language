#include <stdio.h>
#include "word_count.c"

void digit_count() {
    int c, nwhite, nother;
    int ndigit[10];

    nwhite = nother = 0;
    for(int i = 0; i < 10; i++) {
        ndigit[i] = 0;
    }

    while((c = getchar()) != EOF) {
        if(c >= '0' && c <= '9') {
            ++ndigit[c - '0'];
        }
        else if(c == ' ' || c == '\n' || c == '\t') {
            ++nwhite;
        }
        else {
            ++nother;
        }
    }
}

#define MAXLENGTH 15
// 
void length_count_hor() {
    int c, state;
    int wl;
    int nlength[MAXLENGTH];

    for(int i = 0; i < MAXLENGTH; i++) {
        ++nlength[i];
    }

    state = OUT;
    wl = 0;
    while((c = getchar()) != EOF) {
        if(c == ' ' && state == OUT) {

        }
        else if(c == ' ' && state == IN) {
            ++nlength[wl];
            state = OUT;
        }
        else if(state == OUT) {
            wl = 1;
            state = IN;
        }
        else {
            ++wl;
        }
    }

    for(int i = 0; i < MAXLENGTH; i++) {
        printf("%2d:" ,i);
        for(int j = 0; j < nlength[i]; j++) {
            printf("*");
        }
        printf("|\n");
    }
}

void length_count_ver() {
    int c, state;
    int wl;
    int nlength[MAXLENGTH];

    for(int i = 0; i < MAXLENGTH; i++) {
        ++nlength[i];
    }

    state = OUT;
    wl = 0;
    while((c = getchar()) != EOF) {
        if(c == ' ' && state == OUT) {

        }
        else if(c == ' ' && state == IN) {
            ++nlength[wl];
            state = OUT;
        }
        else if(state == OUT) {
            wl = 1;
            state = IN;
        }
        else {
            ++wl;
        }
    }

    int max = 0;
    for(int i = 0; i < MAXLENGTH; i++) {
        max = (nlength[i] > max) ? nlength[i] : max;
    }

    for(int i = max; i >= 0; i--) {
        for (int j = 0; j < MAXLENGTH; j++) {
            if(i <= nlength[j]) {
                printf("**");
            }
            else {
                printf("  ");
            }
        }
        printf("\n");
    }
    for(int i = 0; i < MAXLENGTH; i++) {
        printf("%2d", i);
    }
}