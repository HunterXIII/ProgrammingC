#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[101];
    fgets(str, 101, stdin);
    str[strcspn(str, "\n")] = 0;

    char symbols[] = "@#$^&*№;:?*()_";
    size_t start = strspn(str, symbols);
    size_t len = strcspn(str + start, symbols);
    char *message = strndup(str + start, len);
    printf("Result: %s\n", message);
    free(message);
}