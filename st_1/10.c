#include <stdio.h>

int main() {
    float f;
    printf("Enter a non-negative integer: ");

    int s = scanf("%f", &f);
    int n = (int)f;

    // Input ellenőrzés: csak nemnegatív egész szám
    if (s != 1 || f < 0 || f != n) {
        printf("Error: invalid input!\n");
        return 1;
    }

    long long factorial = 1; // nagyobb számokhoz long long

    for (int i = 1; i <= n; i++) {
        factorial *= i;
    }

    printf("Factorial of %d is: %lld\n", n, factorial);
    return 0;
}
