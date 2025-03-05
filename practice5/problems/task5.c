#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../../myfunctions/mystrings.h"

typedef void (*cmd)(void *, char **, int *n);

typedef struct {
    char name[10];
    cmd command;
} Command;

void alloc(void *str_size, char **arr, int *n) {
    if (str_size != NULL) {
        char *csize = (char *)str_size;
        int size = atoi(csize);
        char *new_arr;
        new_arr = realloc(*arr, size * sizeof(char));
        *arr = new_arr;
        *n = size;
        printf("Allocated memory: %d\n", size);
    } else {
        printf("Uncorrect input - skipped <size>\n\talloc <size>\n");
    }
}

void myfree(void *nll, char **arr, int *n) {
    if (*arr != NULL) {
        free(*arr);
        *arr = NULL;
        printf("Memory is free\n");
    } else {
        printf("Array is NULL\n");
    }
}

void write(void *str, char **arr, int *n) {
    if (*arr == NULL) {
        printf("Memory isn't allocated\n");
    } else if (str == NULL) {
        printf("Incorrect input - skipped <text>\n\twrite <text>\n");
    } else if (strlen(str) != (size_t)*n) {
        printf("Length of str and length of array don't match\n");
    } else {
        strcpy(*arr, str);
        printf("Successful\n");
    }
}

void print(void *nll, char **arr, int *n) {
    if (*arr) {
        printf("In array: %s\n", *arr);
    } else {
        printf("Array is empty\n");
    }
}

int main() {
    Command commands[] = {
        {"alloc", alloc},
        {"free", myfree},
        {"write", write},
        {"print", print}
    };
    char *input;
    int n = 0;
    char *arr = NULL;
    int flag = 1;
    while (flag) {
        printf("Enter command: ");
        input = strread();
        char *pnt = strtok(input, " ");
        for (int i = 0; i < sizeof(commands) / sizeof(commands[0]); i++) {
            if (strcmp(pnt, "exit") == 0) {
                flag = 0;
            }
            if (strcmp(commands[i].name, pnt) == 0) {
                pnt = strtok(NULL, " ");
                commands[i].command(pnt, &arr, &n);
            }
        }
    }
    free(input);
}