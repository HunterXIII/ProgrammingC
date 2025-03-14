#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef void (*cmdpnt)(char*);


void upper(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        str[i] = toupper(str[i]);
    }
};

void lower(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        str[i] = tolower(str[i]);
    }
};

void reverse(char* str) {
    for (int i = 0; i < strlen(str) / 2; i++) {
        char tmp = str[i];
        str[i] = str[strlen(str) - i - 1];
        str[strlen(str) - i - 1] = tmp;
    }
};



typedef struct {
    char name[10];
    cmdpnt cmd;
} Command;

Command cmdlist[] = {
    {"upper", upper},
    {"lower", lower},
    {"reverse", reverse},
};

int main() {
    
    while (1) {
        char command[10];
        char str[100];
        int flag = 1;

        printf("Enter the command: ");
        scanf("%s", command);
        if (strcmp(command, "exit") == 0) {
            return 0;
        }
        scanf(" %99[^\n]", str);

        for (int i = 0; i < sizeof(cmdlist) / sizeof(Command); i++) {
            if (strcmp(command, cmdlist[i].name) == 0) {
                cmdlist[i].cmd(str);
                flag = 0;
                break;
            }
        }

        printf("Result: %s\n", str);
    }

}


