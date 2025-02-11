#include <stdio.h>

int main() {
    float m;
    scanf("%f", &m);
    printf("%f Kbits/sec\n", m * 8388.608);
}