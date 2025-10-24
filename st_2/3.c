#include <stdio.h>
int p(int a){
    for (int i = 2; i <= a / 2; i++) {
        if (a % i == 0) {
            return 0; // Not a prime number
        }
    }
    return 1; // Is a prime number
}

int main() {
    int a[10];
    for (int i = 0; i < 10; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &a[i]);
    }
    printf("The prime numbers are: ");
    for (int i = 0; i < 10; i++) {
        if (a[i] > 1 && p(a[i])) {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
    return 0;
}