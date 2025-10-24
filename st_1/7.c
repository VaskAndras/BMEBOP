#include <stdio.h>
int main () {
    float f;
    printf ("Enter a positive integer: ");
    int s = scanf ("%f", &f);
    int n = (int)f;
    // Input ellenőrzés: csak pozitív egész szám
    if (s != 1 || f <= 0 || f != n) {
        printf ("Error: invalid input!\n");
    }
    else{
    int reverse = 0;
 while (n > 0) {
        reverse = reverse * 10 + n % 10; // számjegy hozzáfűzése
        n /= 10;                        // utolsó számjegy eltávolítása
    }
    printf ("Reversed number: %d\n", reverse);  
}
    return 0;
}