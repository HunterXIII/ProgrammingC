#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char old[200];
    fgets(old, 200, stdin);
    old[strcspn(old, "\n")] = 0;
    char *new = strdup(old);
    printf("Original: %s\nCopy: %s\n", old, new);
}