#include <stdio.h>
int itisprime(int a){
    int isprime = 1;
    for (int i=2; i <= a/2; i++){
        if (a%i == 0){
        isprime = 0;
        }
    }
    return isprime;
}

int main(){
    int gap = 0;
    int max = 0;

    for (int i = 1; i <= 100; i++){
        if (itisprime(i) == 1){
            if (gap > max){
                max = gap;
            }
            gap = 0;
        }
        if (itisprime(i) == 0){
            gap++;
        }
    printf ("\n number: %d\n gap: %d\n max: %d ", i, gap, max);
    }
    return 0;
}