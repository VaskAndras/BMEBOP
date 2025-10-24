#include <stdio.h>

int main() {
    float f;
    printf("Enter an integer: ");
    
    int s = scanf("%f", &f);
    int n = (int)f;

    if (s != 1 || n != f) {
        printf("Error: invalid input!\n");
        return 1;
    }

    if (n < 0) n = -n;  // negatív szám → abszolútérték
    
    if (n == 0) {
        printf("The number has 1 digit.\n");
        return 0;
    }

    int count = 0;
    while (n > 0) {
        n /= 10;
        count++;
    }

    printf("The number has %d digits.\n", count);
    return 0;
}