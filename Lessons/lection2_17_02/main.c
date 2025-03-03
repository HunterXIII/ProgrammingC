#include <stdio.h>
#include "func.h"

// int myMax(int, int); // Прототип, который лучше выносить в отдельный header

int main() {
    int a = 10, b = 5;
    printf("MAX: %d", myMax(a, b));
    return 0;
}