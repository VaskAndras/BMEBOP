#include <stdio.h>

int main() {
    float f_div, f_divisor;
    printf("Enter two positive integers (dividend and divisor): ");

    int s = scanf("%f %f", &f_div, &f_divisor);
    int dividend = (int)f_div, divisor = (int)f_divisor;

    // Input ellenőrzés: csak pozitív egész szám
    if (s != 2 || f_div <= 0 || f_div != dividend || f_divisor <= 0 || f_divisor != divisor) {
        printf("Error: invalid input!\n");
        return 1;
    }

    int quotient = 0;
    int remainder = dividend;

    // Hányados kiszámítása kivonással
    while (remainder >= divisor) {
        remainder -= divisor;
        quotient++;
    }

    printf("Quotient = %d, Remainder = %d\n", quotient, remainder);
    return 0;
}