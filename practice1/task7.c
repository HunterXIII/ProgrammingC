#include <stdio.h>

int main() {
    float x;
    scanf("%f", &x);
    if (2.5 <= x && x <= 3.5) {
        printf("Stable");
    } else {
        printf("Not stable");
    }
}
