#include <stdio.h>

typedef union
{
    int i; 
    float f;
    char s[52];
} Data;

int main() {
    printf("1 - int\n2 - float\n3 - string\nChoice: ");
    int n;
    scanf("%d", &n);
    Data data;
    if (n == 1) {
        scanf("%d", &data.i);
        printf("Integer: %d\n", data.i);
    } else if (n == 2) {
        scanf("%f", &data.f);
        printf("Float: %.2f\n", data.f);
    } else {
        scanf("%s", &data.s);
        printf("String: %s\n", data.s);
    }
    return 0;
}
