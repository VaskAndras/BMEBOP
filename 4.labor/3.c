#include <stdio.h>    
int prime (int n){
    int s = 0;
    for (int i = 2; i <= n-1; i++ ){
        if (n%i == 0){
            s = 1; 
        }
    }
return s;
}
int digit5 (int n){
    int s = 0, d= 0;
    while (n>0) {
        if (n%10 == 5){
            s = 1;
            break;
        }
        n = n/10;
    }
return s;
}

int main (){
    int counter = 0, s = 2;
    while (counter < 60){
        if (prime(s)==0 && prime(s+2)==0 ){
            counter = counter+1; 
        }
        s = s + 1;
    }
    printf("the 60. twin primes: %d, %d", s-1, s+1);

    return 0;
}