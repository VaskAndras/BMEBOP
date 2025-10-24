#include <stdio.h>

int main() {
    float f;
    printf("Enter a positive integer: ");

    int s = scanf("%f", &f);
    int n = (int)f;

    // Input ellenőrzés: csak pozitív egész szám
    if (s != 1 || f <= 0 || f != n) {
        printf("Error: invalid input!\n");
        return 1;
    }

    int product = 1;

    while (n > 0) {
        product *= n % 10;  // utolsó számjegy
        n /= 10;            // utolsó számjegy eltávolítása
    }

    printf("Product of digits: %d\n", product);
    return 0;
}