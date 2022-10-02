#include <ctype.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
//convert string s to doublek 
// double atof(char s[])
// {
//     double val, power;
//     int i, sign;

//     for(i = 0; isspace(s[i]); i++) {

//     }
//     sign = (s[i] == )
// }

double atof(char s[])
{
    int i = 0;
    double val = 0.0;
    double power = 1.0;
    for(; isspace(s[i]); i++) {
    }

    int sign = (s[i] == '-' ? -1 : 1);
    if(s[i] == '+' || s[i] == '-') {
        i++;
    }
    for(; isdigit(s[i]); i++) {
        val = val * 10.0 + (s[i] - '0');
    }

    if(s[i] == '.') {
        i++;
    }
    for(; isdigit(s[i]); i++) {
        val = val * 10.0 + (s[i] - '0');
        power = power * 10.0;
    }

    double e_val = 0.0;
    double e_sign = 10.0;
    if(s[i] == 'e') {
        i++;
    }
    if(s[i] == '-') {
        e_sign = 0.1;
    }
    if(s[i] == '+' || s[i] == '-') {
        i++;
    }
    for(; isdigit(s[i]); i++) {
        e_val = e_val * 10 + (s[i] - '0');
    }

    return sign * val / power * pow(e_sign, e_val);
}

int main()
{
    // printf("All success");
    char atof_1[] = "-1.0e-2";;
    double atof_d_1 = -0.01;
    assert(fabs((atof(atof_1)) - atof_d_1) < 0.00001);
//    printf("%f\n", atof(atof_1));
//    printf("%f\n", atof_d_1);

    printf("\nAll success");
    return 0;
}