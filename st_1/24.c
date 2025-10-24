#include <stdio.h>

int main() {
    float f;
    printf("Enter a positive integer: ");

    int s = scanf("%f", &f);
    int n = (int)f;

    // Input ellenőrzés: csak pozitív egész szám
    if (s != 1 || f <= 0 || f != n) {
        printf("Error: invalid input!\n");
    } else {
        int last_digit = n % 10;

        // Első számjegy meghatározása
        int first_digit = n;
        while (first_digit >= 10) {
            first_digit /= 10;
        }

        int product = first_digit * last_digit;

        printf("First digit: %d\n", first_digit);
        printf("Last digit: %d\n", last_digit);
        printf("Product of first and last digits: %d\n", product);
    }

    return 0;
}