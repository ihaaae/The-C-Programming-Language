#include <stdio.h>
#include <assert.h>
#include <string.h>
#define MAXLINE 100

int strindex(char search[], char searchfor[]);
int match(char search[], int start_index, char searchfor[]);
int strindex_r(char search[], char searchfor[]);

// return index of *t* in *s*, -1 if none
int strindex(char s[], char t[])
{
    for(int i = 0; s[i] != '\0'; i++) {
        if(match(s, i, t) == 1){
            return i;
        }
    }

    return -1;
}

// return 1 if *s*[*start*:] match *t*, else return -1 
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

#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);

int main()
{
    int type;
    double op2;
    char s[MAXOP];

    while((type = getop(s)) != EOF) {
        switch(type) {
            case NUMBER:
                push((atof(s)));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
            case '/':
                op2 = pop();
                if(op2 != 0.0):
                    push(pop()/op2);
                else {
                    printf("error: zero divisor");
                }
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
}

#define MAXVAL 100
int sp = 0;
double val[MAXVAL];

// push f into val stack
void push(double f)
{
    if(sp < MAXVAL){
        val[sp++] = f;
    }
    else {
        printf("error: stack full");
    }
}

// pop and return top value of stack
double pop(void)
{
    if(sp > 0) {
        return val[--sp];
    }
    else {
        printf("error: stack empty");
        return 0.0;
    }
}

int getch(void);
void ungetch(int);

// get next operator or numeric operand
int getop(char s[])
{
    int i, c;

    while((s[0] = c = getch()) == ' ' || c == 't')
        ;
    s[1] = '\n';
    if(!isdigit(c) && c != '.') {
        return c;
    }
    i = 0;
    if(isdigit(c)) {
        while(isdigit(s[++i]) = c = getch())
            ;
    }
    s[i] = '\0';
    if(c != EOF) {
        ungetch(c);
    }
    return NUMBER;
}

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if(bufp >= BUFSIZE) {
        printf()
    }
}

// int main(){
//     char match_s_1[] = "to_test";
//     char match_t_1[] = "test";
//     assert(match(match_s_1, 3, match_t_1) == 1);
//     char match_t_2[] = "eat";
//     assert(match(match_s_1, 4, match_t_2) == -1);
//     char sir_s_1[] = "test test";
//     char sir_t_1[] = "test";
//     assert(strindex_r(sir_t_1, sir_s_1) == 5);
//     assert(strindex(sir_s_1, sir_t_1) == 0);
//     printf("All success!\n");

//     return 0;
// }