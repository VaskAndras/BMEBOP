#include <stdio.h>
int main (){
    int N, sum=0;
    printf ("Write an integer:");
    scanf("%d", &N );
for (int i= 1; i < N; ++i) {
    if (N%i == 0){
        sum = sum + i; 
    }
}
    printf("%d", sum );
if (sum==N){
    printf("perfect number");
}
    return 0;
}