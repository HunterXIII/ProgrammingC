#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char item[52];
    int quantity; 
    float price;
} Item;

int main() {
    printf("Count items: ");
    int n;
    scanf("%d", &n);
    Item *items = malloc(sizeof(Item) * n);

    for (int i = 0; i < n; i++){
        scanf("%s %d %f", &items[i].item, &items[i].quantity, &items[i].price);
    }

    for (int i = 0; i < n; i++){
        printf("Item: %s\nQuantity: %d\nPrice: %.2f\n\n", items[i].item, items[i].quantity, items[i].price);
    }
    return 0;
}