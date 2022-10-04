#include <stdio.h>

#define IN 1
#define OUT 0

void file_copy() {
    int c;

    while((c = getchar()) != EOF) {
        putchar(c);
    }
}

// 1.9
void file_copy_replace_multiple_blank() {
    int c, inspace;

    inspace = OUT;
    while((c = getchar()) != EOF) {
        if(c == ' ' && inspace == OUT) {
            putchar(c);
            inspace = IN;
        }
        else if(c == ' ') {
            
        }
        else if(inspace == IN) {
            putchar(c);
            inspace = OUT;
        }
        else {
            putchar(c);
        }
    }
}

// 1.10
void file_copy_replace_tab () {
    int c;

    while((c = getchar()) != EOF) {
        if(c == '\t') {
            putchar('\\');
            putchar('t');
        }
        else if(c == '\\') {
            putchar('\\');
            putchar('\\');
        }
        else if(c == '\b') {
            putchar('\\');
            putchar('b');
        }
        else {
            putchar(c);
        }
    }
}