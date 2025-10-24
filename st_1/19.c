#include <stdio.h>

int main() {
    float f;
    printf("Enter the number of elements: ");
    
    int s = scanf("%f", &f);
    int n = (int)f;

    if (s != 1 || f <= 0 || f != n) {
        printf("Error: invalid input!\n");
    } else {
        double product = 1.0;

        for (int i = 1; i <= n; i++) {
            product *= (i * i); // n^2 szorzása
        }

        printf("Product of the first %d elements is: %.2lf\n", n, product);
    }

    return 0;
}