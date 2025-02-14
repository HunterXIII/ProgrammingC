#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int age;
    float gpa;
} Student;

int main() {
    printf("Count students: ");
    int n;
    scanf("%d", &n);
    Student *students = malloc(sizeof(Student) * n);
    for (int i = 0; i < n; i++){
        Student *ptr = &students[i];
        scanf("%s %d %f", &ptr->name, &ptr->age, &ptr->gpa);
    }

    for (int i = 0; i < n; i++){
        Student *ptr = &students[i];
        printf("Name: %s\nAge: %d\nGPA: %.1f\n\n", ptr->name, ptr->age, ptr->gpa);
    }
    return 0;
}