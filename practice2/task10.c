#include <stdio.h>
#include <stdlib.h>
typedef struct {
    char name[20];
    int credits;
    char teacher[20];
} Course;

int main() {
    int n;
    printf("Count courses: ");
    scanf("%d", &n);
    Course *courses = malloc(sizeof(Course) * n);
    for (int i = 0; i < n; i++) {
        scanf("%s %d %s", &courses[i].name, &courses[i].credits, &courses[i].teacher);
    }
    for (int i = 0; i < n; i++) {
        printf("Course: %s\nCredits: %d\nProfessor: %s\n\n", courses[i].name, courses[i].credits, courses[i].teacher);
    }
    return 0;
}