#include <stdlib.h>
#include <stdio.h>

int main() {
    char sym = getchar();
    if ('A' <= sym && sym <= 'Z') {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
}