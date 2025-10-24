#include <stdio.h>

int main() {
    float f;
    printf("Enter a 4-digit integer: ");

    int s = scanf("%f", &f);
    int n = (int)f;

    // Input ellenőrzés: csak 4 jegyű egész szám
    if (s != 1 || f != n || n < 1000 || n > 9999) {
        printf("Error: invalid input!\n");
    } else {
        int first_digit = n / 1000;       // ezres hely
        int second_digit = (n / 100) % 10; // százak helye
        int third_digit = (n / 10) % 10;   // tízes hely
        int fourth_digit = n % 10;        // egyes hely

        if (first_digit == fourth_digit && second_digit == third_digit) {
            printf("%d is a palindromic number.\n", n);
        } else {
            printf("%d is not a palindromic number.\n", n);
        }
    }

    return 0;
}