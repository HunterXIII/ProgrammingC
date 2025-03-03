#include <stdio.h>
#include <stdlib.h>

double calculate(double a, double b, double (*func)(double, double)){
    return func(a, b);
}

double add(double a, double b) { return a + b; }
double dif(double a, double b) { return a - b; }
double mul(double a, double b) { return a * b; }
double dev(double a, double b) { return a / b; }

int main() {
    double a, b, res;
    char sign;
    scanf("%lf %c %lf", &a, &sign, &b);
    switch (sign)
    {
    case '+':
        res = calculate(a, b, add);
        break;
    
    case '-':
        res = calculate(a, b, dif);
        break;
    
    case '*':
        res = calculate(a, b, mul);
        break;

    case '/':
        res = calculate(a, b, dev);
        break;

    default:
        printf("Error sign");
        return 1;
    }
    printf("%lf %c %lf = %lf\n", a, sign, b, res);
    return 0;
}