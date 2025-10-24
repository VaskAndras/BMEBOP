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

    int last_digit = n % 10;

    // Első számjegy meghatározása
    int first_digit = n;
    while (first_digit >= 10) {
        first_digit /= 10;
    }

    int sum = first_digit + last_digit;

    printf("First digit: %d\n", first_digit);
    printf("Last digit: %d\n", last_digit);
    printf("Sum of first and last digits: %d\n", sum);

    return 0;
}