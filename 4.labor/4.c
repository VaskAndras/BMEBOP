#include <stdio.h>
int main(){
    
    int s=10, n = 1;
    do {
    printf("0. Restore the initial value (n = 1)\n"
       "1. Add 1\n"
       "2. Negate the number (+/-)\n"
       "3. Multiple by 2\n"
       "9. Exit\n"); 
    scanf("%d", &s);
    printf("Please enter a number: ");
    scanf ("%d", &n);
    
    switch (s)
    {
        case 0:
            n = 1;
            printf("n = %d\n", n);
            break;
        case 1:
            n = n + 1;
            printf("n = %d\n", n);
            break;
        case 2:
            n = -n;
            printf("n = %d\n", n);
            break;
        case 3:
            n = n * 2;
            printf("n = %d\n", n);
            break;
        case 9:
            break;
        default:
            printf("Error: invalid input!\n");
            break;
    }

printf("\n\n\n\n"); 
} while (s != 9);
    return 0;
}