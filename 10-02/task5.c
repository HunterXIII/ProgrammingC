#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
    double calculate, factual;
    scanf("%lf %lf", &calculate, &factual);
    
    if (fabs(calculate - factual) <= 0.1 + 0.00001){
        printf("Stable\n");
    } else {
        printf("Not stable\n");
    }
}