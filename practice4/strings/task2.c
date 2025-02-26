#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int start = 0, end = 0;
    char str[100];
    printf("Enter a message:");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = 0;
    
    int flag = 1;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] != '*' && str[i] != '#') {
            start = i;
            break;
        }   
    }
    end = start + 1;
    for (int i = start + 1; i < strlen(str); i++) {
        if (str[i] == '*' || str[i] == '#') {
            end = i;
            break;
        }
    }
    char res[100];
    strncpy(res, &str[start], end - start);
    res[end] = 0;
    printf("Message: %s \nLength: %d\n", res, end - start);
    return 0;
}