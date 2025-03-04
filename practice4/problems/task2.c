#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../../mylibraries/mystrings.h"

typedef void (*handler)(char *str);

void del_spaces(char *str) {
    int i;
    while ((i = strcspn(str, " ")) < strlen(str)) {
        for (int j = i + 1; j < strlen(str) + 1; j++) {
            str[j - 1] = str[j];
        }
    } 
}

void replace_vowels(char *str) {
    char vowels[] = "еиаоэюяeiaou";
    for (int i = 0; i < strlen(str); i++) {
        if (strchr(vowels, tolower(str[i]))) {
            str[i] = '*';
        }
    }
}

void invert_registr(char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if (isupper(str[i])) {
            str[i] = tolower(str[i]);
        } else {
            str[i] = toupper(str[i]);
        }
    }
}

int main() {
    char *str = strread();
    int choice;
    handler handlers[] = {del_spaces, replace_vowels, invert_registr};
    while (1) {

    printf("1) Delete spaces\n\
2) Replace vowels with *\n\
3) Invertation registr\n\
4) Exit\n\
Enter number command: ");

    scanf("%d", &choice);

    if (choice == 4) {
        break;
    } else if (choice < 1 || choice > 4 ) {
        printf("Command not found\n");
        continue;
    }

    handlers[choice - 1](str);
    printf("Result: %s\n", str);

    }
    free(str);
}