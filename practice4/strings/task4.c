#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    char code[12];
    fgets(code, 12, stdin);
    if (strcasecmp(code, "LAUNCH-2025") == 0) {
        printf("Code accepted\n");
    } else {
        printf("Error: incorrect code!\n");
    }
}