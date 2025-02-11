#include <stdio.h>

int main() {
    int temp;
    scanf("%i", &temp);
    if (-150 <= temp && temp <= 120) {
        print("It's OK");
    } else {
        printf("Not okay :(");
    }
}
