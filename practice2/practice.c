#include <stdio.h>

struct Person {
    char name[50];
    int age;
    float height;
};

union Data
{
    int i;
    float f;
    char str[20];
};

enum State {
    On = 100, Off = 400
};


int main() {
    struct Person p = {"John", 20};
    printf("%f\n", p.height);

    union Data data;
    data.i = 10;
    printf("i = %d\n", data.i);

    data.f = 10.1;
    printf("f = %.1f, i = %d\n", data.f, data.i);
    printf("%s\n", data.str);

    enum State state;
    state = On;
    printf("State: %d\n", state);

    return 0;
}