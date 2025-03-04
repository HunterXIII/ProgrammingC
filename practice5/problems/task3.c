#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef float (*operation)(float a, float b);

float addition(float a, float b) {
    return a + b;
}

float difference(float a, float b) {
    return a - b;
}

float multiplication(float a, float b) {
    return a * b;
}

float divison(float a, float b) {
    if (b == 0) {
        printf("Zero division\n");
        return 0;
    }
    return a / b;
}

typedef struct {
    char sign;
    operation op;
} Calculator;

int main() {
    Calculator calculate[] = {
        {'+', addition},
        {'-', difference},
        {'*', multiplication},
        {'/', divison},
        {'0', NULL}
    };
    float a, b;
    char sign;
    printf("Enter expression: ");
    scanf(" %f %c %f", &a, &sign, &b);
    for (int i = 0; calculate[i].sign != '0'; i++) {
        if (calculate[i].sign == sign) {
            printf("Result: %.3f", calculate[i].op(a, b));
            break;
        }
    }

}