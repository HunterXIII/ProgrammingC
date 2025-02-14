#include <stdio.h>
#include <stdlib.h>

typedef enum {
    Gasoline, Diesel, Electric
} Type_engine;

char *NameTypeEngine[3] = {"Gasoline", "Diesel", "Electric"};

typedef struct {
    char brand[20];
    char model[20];
    int year;
    Type_engine engine;
} Car;

int main() {
    int n;
    printf("Count cars: ");
    scanf("%d", &n);
    Car *cars = malloc(sizeof(Car) * n);
    for (int i = 0; i < n; i++) {
        char str_type[20];
        scanf("%s %s %d %s", &cars[i].brand, &cars[i].model, &cars[i].year, &str_type);
        
        if (*str_type == *NameTypeEngine[0]){
            cars[i].engine = Gasoline;
        } else if (*str_type == *NameTypeEngine[1]) {
            cars[i].engine = Diesel;
        } else {
            cars[i].engine = Electric;
        }

    }
    
    for (int i = 0; i < n; i++) {
        printf("Vehicle: %s %s\nYear: %d\nEngine Type: %s\n\n",
                cars[i].brand, cars[i].model, cars[i].year, NameTypeEngine[cars[i].engine]);
    }
    free(cars);
    return 0;
}