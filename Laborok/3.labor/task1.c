#include <stdio.h>

int main() {
    int N;
    long long x = 1;
    printf("Enter a number, and I will calculate it's factorial: ");
    scanf("%d", &N);
    if (N > 0){
    for (int i = 1; i <= N; i = i + 1) {
        x = x*i;

    }
        printf("%lld", x);
       }
    else{
        printf("The number must be greater than 0");

    }
   
    return 0;
}