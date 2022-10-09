#include <stdio.h>
#include "./strcat_ptr.c"
#include "./alloc.c"

#define MAXLINES 100

int main_qsort()
{
    char *lines[MAXLINES];
    readlines(lines, MAXLINES);
    qsort(lines);
    writelines(lines);
}

#define MAXLENGTH 100

int readlines_alloc(char *lines[], int maxlines)
{
    int len, nlines = 0;
    char *p, line[MAXLENGTH];
    while((len = getline(lines, MAXLENGTH)) > 0) {
        if(nlines >= maxlines || (p = alloc(len)) == NULL) {
            return -1;
        }
        else {
            strcpy(p, line);
            lines[nlines++] = p;
        }
    }

    return nlines;
}

static char readline_buf[10000];

int readlines(char* lines[], int maxlines)
{
    int len, nlines = 0, idx = 0;
    char line[MAXLENGTH];
    while((len = getline(line, MAXLENGTH))) {
        if(nlines >= maxlines) {
            return 0;
        }
        else {
            char *p = &readline_buf[idx];
            for(int i = 0; line[i] != '\0'; ) {
                if(idx >= 10000) {
                    return -1;
                }
                else {
                    readline_buf[idx++] = line[i++];
                }
            }
            lines[nlines] = p;
        }
    }

    return nlines;
}