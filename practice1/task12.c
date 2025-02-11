#include <stdio.h>

int main() {
    int degree;
    scanf("%i", &degree);
    if (-180 <= degree && degree <= 180) {
        printf("Good");
    } else {
        printf(":(");
    }
}