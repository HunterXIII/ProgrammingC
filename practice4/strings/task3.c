#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[100];
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = 0;
    char *pnt = strtok(str, ";");
    while (pnt != NULL){
        printf("%s\n", pnt);
        pnt = strtok(NULL, ";");
    }
    return 0;
}