#include <stdio.h>
int main (){
    printf ("Write a three-digit number: ");
    float f;
    int s = scanf ("%f", &f);
    int n = (int)f;
    if (n < 0) {
        n = -n;
        f = -f;
    }

    if (s != 1 || n < 100 || n >= 1000 || f != n){
        printf ("Incorrect input\n");
    }
    else {
        if (n/100 == n%10){
            printf ("Palindrom\n");
        }
        else {
            printf ("Not palindrom\n");
        }

    }
    return 0;
}