#include <stdio.h>
#include "ship.h"

int main() {
    float speed, time;
    printf("Введите скорость:");
    scanf("%f", &speed);
    printf("Введите время:");
    scanf("%f", &time);
    printf("Расстояние = %.2f\n", calculate_distance(speed, time));
    printf("Введите уровень топлива: ");
    int fuel_level, max_fuel_level;
    scanf("%d", &fuel_level);
    printf("Введите максимальный уровень топлива: ");
    scanf("%d", &max_fuel_level);
    if (!check_fuel(fuel_level, max_fuel_level)) {
        printf("Недостаточно топлива\n");
        return 0;
    }
    printf("Полетели!\n");
}