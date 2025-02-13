#include <stdio.h>

int main() {
    float mb, speed;
    printf("Ввведите скорость и объём: ");
    scanf("%f %f", &speed, &mb);
    printf("%f Kbits/sec\n", mb * 8388.608 / speed);
}