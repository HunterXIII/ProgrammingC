#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
    char s[10];
    time_t now_time = time(NULL);
    struct tm *t = localtime(&now_time);
    strftime(s, sizeof(s), "%Y%m%d", t);
    int now = atoi(s);

    int date;
    scanf("%i", &date);

    if (now < date) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
}