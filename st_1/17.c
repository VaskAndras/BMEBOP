#include <stdio.h>

int main() {
    float f;
    printf("Enter the number of elements: ");

    int s = scanf("%f", &f);
    int n = (int)f;

    // Input ellenőrzés: csak pozitív egész szám
    if (s != 1 || f <= 0 || f != n) {
        printf("Error: invalid input!\n");
    } else {
        double sum = 0.0;
        for (int i = 1; i <= n; i++) {
            sum += 1.0 / i;
        }
        printf("Sum of the first %d elements: %.3lf\n", n, sum);
    }

    return 0;
}