// 5.3
// cat *t* to the end of *s*
void strcat_ptr(char *s, char *t)
{
    while(*s != '\0') {
        s++;
    }
    while((*s++ = *t++) != '\0') {
    }
}

// 5.4
int strend(char *s, char *t)
{
    char *s_b = *s;
    char *t_b = *t;
    while(*s++ != '\0') {
        ;
    }
    while(*t++ != '\0') {
        ;
    }

    while(*t-- == *s--) {
        if(t == t_b) {
            return 1;
        }
    }

    return 0;
}

// 5.5
void strncpy(char *s, char *t, int n)
{
    for(int i = 0; i < n; i++) {
        *s++ = *t++;
    }
    return 0;
}

void strncat(char *s, char *t, int n)
{
    while(*s++ != '\0') {
        ;
    }
    for(int i = 0; i < n; i++) {
        *s++ = *t++;
    }
}

int strncmp(char *s, char *t, int n)
{
    for(int i = 0; i < n; i++) {
        if(*s++ != *t++) {
            return 0;
        }
    }
    return 1;
}

// 5.6
// TODO