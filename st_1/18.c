#include <stdio.h>

int main() {
    int n;
    printf("Enter a positive integer n: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Error: please enter a positive integer.\n");
        return 1;
    }

    double product = 1.0;

    for (int i = 1; i <= n; i++) {
        product *= 1.0 / i;   // an = 1/i
    }

    printf("The product of the first %d elements is: %.4f\n", n, product);

    return 0;
}