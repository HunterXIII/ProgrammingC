#include <stdio.h>
#include <stdlib.h>
typedef union {
    int grade_int;
    char grade_ch;
} Grade;

int main() {
    int n; 
    printf("Count grades: ");
    scanf("%d", &n);
    Grade grade;
    for (int i = 0; i < n; i++) {
        printf("1 - int\n2 - letter\nFormat grade: ");
        int c; 
        scanf("%d", &c);
        switch (c) {
            case 1:
                scanf("%d", grade.grade_int);
                printf("Grade: %d", grade.grade_int);
                break;
            case 2:
                scanf("%d", grade.grade_ch);
                printf("Grade: %c", grade.grade_ch);
                break;
        }
    }
}