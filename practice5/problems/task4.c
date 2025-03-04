#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef int (*compare)(const void *, const void *);

void lower(char *str) {
    for (int i = 0; i < strlen(str); i++) {
        str[i] = tolower(str[i]);
    }
}

int alpha(const void *val1, const void *val2) {
    char *str1 = *(char**)val1;
    char *str2 = *(char**)val2;
    lower(str1);
    lower(str2);
    return strcmp(str1, str2);
}

int bylength(const void *val1, const void *val2) {
    char *str1 = *(char**)val1;
    char *str2 = *(char**)val2;
    return strlen(str1) > strlen(str2) ? 1: strlen(str1) < strlen(str2) ? -1: 0;
}

int byvowels(const void *val1, const void *val2) {
    int count1 = 0, count2 = 0;
    char *str1 = *(char**)val1;
    char *str2 = *(char**)val2;
    lower(str1);
    lower(str2);
    char vowels[] = "еиаоэюяeiaou";
    for (int i = 0; i < strlen(str1); i++) {
        if (strchr(vowels, str1[i])) {
            count1++;
        }
    }
    for (int i = 0; i < strlen(str2); i++) {
        if (strchr(vowels, str2[i])) {
            count2++;
        }
    }
    return count1 > count2 ? 1: count1 < count2 ? -1: 0;
}


int main() {
    printf("Enter the number of strings: ");
    int n;
    scanf("%d", &n);

    compare cmps[] = {
        alpha,
        bylength,
        byvowels
    };

    char **arr = malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        arr[i] = malloc(50);
        scanf(" %49[^\n]", arr[i]);
        
    }

    printf("Before: \n");
    for (int i = 0; i < n; i++) {
        printf("%d: %s\n", i, arr[i]);
    }
    printf("\n\n");

    printf(
"1) Alphabetically\n\
2) by lenght\n\
3) by number of vowels\n\
Enter sorting option: "
);
    int choice;
    scanf("%d", &choice);
    qsort(arr, n, sizeof(char *), cmps[choice - 1]);

    printf("Result: \n");
    for (int i = 0; i < n; i++) {
        printf("%d: %s\n", i, arr[i]);
        free(arr[i]);
    }
    free(arr);    
    return 0;
}