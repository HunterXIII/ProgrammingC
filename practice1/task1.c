#include <stdio.h>

int main() {
    int weight;
    scanf("%d", &weight);
    if (60 <= weight && weight <= 90) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    
}