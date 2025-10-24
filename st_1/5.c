#include <stdio.h>

int main() {
    float f;
    double result = 0.0;

    printf("\nWrite an integer: ");
    int s = scanf("%f", &f);
    int n = (int)f;

    // Hibás input ellenőrzése
    if (s != 1 || f <= 0 || n != f) {
        printf("\nError, invalid input, please write a positive integer");
    } 
    else {
        for (int i = 1; i <= n; i++) {
            // kiszámoljuk (i*i)!-t
            int k = i * i;
            double fact = 1.0;
            for (int j = 1; j <= k; j++) {
                fact *= j;
            }
            result += 1.0 / fact;
        }
        printf("\nThe result is: %.2f\n", result);
    }

    return 0;
}