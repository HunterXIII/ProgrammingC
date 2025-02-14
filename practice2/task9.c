#include <stdio.h>

typedef enum {
    Sunny, Cloudy, Rainy 
} State;

char *NameState[3] = {"Sunny", "Cloudy", "Rainy"};

typedef struct {
    float temp;
    float humidity;
    State state;
} Weather;

int main() {
    Weather weather;
    char s[10];
    scanf("%f %f %s", &weather.temp, &weather.humidity, &s);
    if (*s == *NameState[0]) {
        weather.state = Sunny;
    } else if (*s == *NameState[1]) {
        weather.state = Cloudy;
    } else {
        weather.state = Rainy;
    }
    printf("Temperature: %.1f\nHumidity: %.1f%\nCondition: %s\n", weather.temp, weather.humidity, NameState[weather.state]);

}