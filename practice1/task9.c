#include <stdio.h>

int main() {
    double t;
    scanf("%lf", &t);
    int min = t / 60;
    double sec = t - min * 60;
    printf("%i min %.1lf sec\n", min, t);
}