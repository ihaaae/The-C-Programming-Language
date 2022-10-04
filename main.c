#include <stdio.h>
#include <assert.h>
#include "./chapter_1/final.c"
#include <string.h>

int test_remove_comment() {
    char s_1[] = "i = 1;\n/* assignment*/\n";
    char e_1[] = "i = 1;\n\n";
    remove_comment(s_1, strlen(s_1));
    assert(strcmp(s_1, e_1) == 0);

    char s_2[] = "i /= 1;\n/* assignment*/\n";
    char e_2[] = "i /= 1;\n\n";
    remove_comment(s_2, strlen(s_2));
    assert(strcmp(s_2, e_2) == 0);


    char s_3[] = "i /= 1;\n/* assi */i = i * a;\n";
    char e_3[] = "i /= 1;\ni = i * a;\n";
    remove_comment(s_3, strlen(s_3));
    assert(strcmp(s_3, e_3) == 0);

    char s_4[] = "char s[] = \"/*not comment*/\"\n";
    char e_4[] = "char s[] = \"/*not comment*/\"\n";
    remove_comment(s_4, strlen(s_4));
    assert(strcmp(s_4, e_4) == 0);

    char s_5[] = "i = 1;\n/* \"assignment\" */\n";
    char e_5[] = "i = 1;\n\n";
    remove_comment(s_5, strlen(s_5));
    assert(strcmp(s_5, e_5) == 0);
}

int test_syntax_check() {
    char code_1[] = "foo(a)\n";
    assert(syntax_check(code_1) == 1);

    char code_2[] = "foo(bar(foo(1, 1))\n";
    assert(syntax_check(code_2) == -1);

    char code_3[] = "int i = foo(bar(foo(\")\", 1)))\n";
    assert(syntax_check(code_3) == 1);

    char code_4[] = "/* a test for (*/\nint i = foo(bar(foo(\")\", 1)))\n";
    assert(syntax_check(code_4) == 1);
}

int main() {
    test_syntax_check();
    printf("All successes");

    return 0;
}