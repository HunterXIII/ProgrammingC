#include <stdio.h>

void printHello(int a) {
    printf("Hello World, %d\n", a);
}

void execute(void (*func)(int), int a) {
    func(a);
}

int main() {
    int x = 1;
    execute(printHello, x);
    return 0;
}
