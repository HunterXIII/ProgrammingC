#include <stdio.h>

int main() {
    int count;
    scanf("%i", &count);
    
    for (int four = 0; four <= count / 4; four++) {
        for (int three = 0; three <= count - four * 4; three++) {
            for (int two = 0; two <= count - four * 4 - three * 3; two++) {
                if (count - four * 4 - three * 3 - two * 2 == 0) {
                    printf("4-seater: %d, 3-seater: %d, 2-seater: %d\n", four, three, two);
                }
            }
        }
    }
}