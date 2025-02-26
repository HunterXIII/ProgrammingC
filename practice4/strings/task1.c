#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRLEN 50

int main() {
    int n;
    printf("Enter count ships: ");
    scanf("%d", &n);
    char **ships = malloc(n * sizeof(char *));
    getchar();
    for (int i = 0; i < n; i++) {
        ships[i] = malloc((STRLEN + 1) * sizeof(char));
        fgets(ships[i], STRLEN + 1, stdin);
        ships[i][strcspn(ships[i], "\n")] = 0;
    }
    printf("Names of ships beginning with 'SS': \n");
    int flag = 0;
    for (int i = 0; i < n; i++) {
        if (strncmp(ships[i], "SS", 2) == 0) {
            printf("%s\n", ships[i]);
            flag = 1;
        }
    }
    if (!flag) {
        printf("Not found\n");
    }
    
    for (int i = 0; i < n; i++){
        free(ships[i]);
    }
    free(ships);
    return 0;
}