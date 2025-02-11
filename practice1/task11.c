#include <stdio.h>

int main(){
    float percent;
    scanf("%f", &percent);
    if (percent <= 15.0) {
        printf("Attention, attention!!!");
    } else {
        printf("Everthing all right");
    }
}