#include <stdio.h>

int main() {
    float f_base, f_exp;
    printf("Enter the base and exponent (integers): ");
    
    int s = scanf("%f %f", &f_base, &f_exp);
    int base = (int)f_base;
    int exponent = (int)f_exp;

    // Input ellenőrzés: csak egész számok
    if (s != 2 || f_base != base || f_exp != exponent) {
        printf("Error: invalid input!\n");
        return 1;
    }

    int result = 1;

    // negatív kitevő kezelése
    if (exponent >= 0) {
        for (int i = 0; i < exponent; i++) {
            result *= base;
        }
        printf("Result: %d\n", result);
    } else {
        // negatív kitevő esetén törtszám lenne, de mivel int, hiba
        printf("Error: negative exponent not supported for integer result!\n");
        return 1;
    }

    return 0;
}