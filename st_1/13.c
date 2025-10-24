#include <stdio.h>

int main() {
    float f1, f2;
    printf("Enter two integers: ");

    int s = scanf("%f %f", &f1, &f2);
    int a = (int)f1, b = (int)f2;

    // Input ellenőrzés
    if (s != 2 || f1 != a || f2 != b) {
        printf("Error: invalid input!\n");
        return 1;
    }

    int result = 0;
    int sign = 1;

    // Ha b negatív, átállítjuk pozitívra és jelet tárolunk
    if (b < 0) {
        b = -b;
        sign = -1;
    }

    // Összeadásos szorzás
    for (int i = 0; i < b; i++) {
        result += a;
    }

    result *= sign;

    printf("The product is: %d\n", result);
    return 0;
}