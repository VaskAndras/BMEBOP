#include <stdio.h>

int main() {
    float f;
    printf("Enter a positive integer: ");

    int s = scanf("%f", &f);
    int n = (int)f;

    // Input ellenőrzés: csak pozitív egész szám
    if (s != 1 || f <= 0 || f != n) {
        printf("Error: invalid input!\n");
    } 
    else {
        int sum = 0;
        int temp = n;

        while (temp > 0) {
            sum += temp % 10;  // utolsó számjegy hozzáadása
            temp /= 10;        // utolsó számjegy eltávolítása
        }

        printf("Sum of digits of %d is: %d\n", n, sum);
    }

    return 0;
}