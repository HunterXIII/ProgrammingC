#include <stdio.h>

int main() {
    int weight;
    scanf("%i", &weight);
    if (weight % 4 == 0) {
        printf("Weight of one part: %i\n", weight / 4);
    } else {
        printf("No\n");
    }
}