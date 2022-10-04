#include <stdio.h>

#define MAXLENGTH 100
#define TABEND 3

void copy(char[], int, int, char[], int);

void detab()
{
    char s[MAXLENGTH]; 
    int c;
    int i = 0;
    while((c = getchar()) != EOF) {
        if(c == '\t') {
            s[i + 2] = s[i + 1] = s[i] = ' ';
            i = i + TABEND;
        }
        else{
            s[i] = c;
            i = i + 1;
        }
    }
}

void entab(char s[], int len) 
{
    for(int i = 0, j = 0, blank_count = 0; i < len; i++) {
        if(s[i] == ' ' && blank_count == 0) {
            blank_count++;
        }
        else if(s[i] == ' ') {
            blank_count++;
        }
        else if(blank_count == 0) {
            s[j] = s[i];
            j++;
        }
        else {
            int tab_count =  blank_count / TABEND;
            int blank_number = blank_count % TABEND; 
            for(int k = 0; k < tab_count; k++) {
                s[j++] = '\t';
            }
            for(int k = 0; k < blank_number; k++) {
                s[j++] = ' ';
            }
        }
    }
}

#define LINEWEIGHT 15

void fold_line(char s[], int len)
{
    char fs[MAXLENGTH];
    for(int i = 0 + LINEWEIGHT - 1, j = 0; i < len;) {
        if(s[i] != ' ') {
            copy(s, j, i, fs, j);
            i += 1;
            j = i;
        }
        else if(s[i] == ' ') {
            i = i - 1;
        }
    }
}

void remove_comment(char s[], int len)
{
    int i;
    int comment;
    int j;
    int in_string;
    for(i = 0, comment = 0, j = 0, in_string = 0; i < len; ) {
        if(comment == 1 && s[i] == '*' && s[i + 1] == '/') {
            comment = 0;
            i += 2;
        }
        else if(comment == 1) {
            i += 1;
        }
        else if(in_string == 1 && s[i] == '\"') {
            in_string = 0;
            s[j++] = s[i++];
        }
        else if(in_string == 1){
            s[j++] = s[i++];
        }
        else if(in_string == 0 && s[i] == '\"') {
            in_string = 1;
            s[j++] = s[i++];
        }
        else if(in_string == 0 && s[i] == '/' && s[i + 1] == '*') {
            comment = 1;
            i += 2;
        }
        else {
            s[j++] = s[i++];
        }
    }
    s[j] = '\0';
}

int syntax_check(char code[])
{
    int i;
    int comment;
    int in_string;
    int parentheses = 0;
    for(i = 0, comment = 0, in_string = 0; code[i] != '\0'; ) {
        if(comment == 1 && code[i] == '*' && code[i + 1] == '/') {
            comment = 0;
            i += 2;
        }
        else if(comment == 1) {
            i++;
        }
        else if(in_string == 1 && code[i] == '\"') {
            in_string = 0;
            i++;
        }
        else if(in_string == 1){
            i++;
        }
        else if(code[i] == '\"') {
            in_string = 1;
            i++;
        }
        else if(code[i] == '/' && code[i + 1] == '*') {
            comment = 1;
            i += 2;
        }
        else if(code[i] == '(') {
            parentheses += 1;
            i++;
        }
        else if(code[i] == ')') {
            parentheses -= 1;
            i++;
        }
        else {
            i++;
        }
    }

    if(parentheses != 0) {
        return -1;
    }
    else {
        return 1;
    }
}

void copy(char s[], int start_s, int end_s, char d[], int d_s) {
    // TODO
}