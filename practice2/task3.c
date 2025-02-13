#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int day;
    int mounth;
    int year;
} Date;

typedef struct {
    char event_name[20];
    Date date;
    char description[20];
} Event;

int main() {
    int n;
    printf("Count events: ");
    scanf("%d", &n);
    Event *events = malloc(sizeof(Event) * n);
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d %d %s", 
                &events[i].event_name, 
                &events[i].date.day, &events[i].date.mounth, &events[i].date.year,
                &events[i].description);
    }
    for (int i = 0; i < n; i++) {
        printf("Event: %s\nDate: %d/%d/%d\nDescription: %s\n\n",
                events[i].event_name, 
                events[i].date.day, events[i].date.mounth, events[i].date.year,
                events[i].description);
    }
    return 0;
}
