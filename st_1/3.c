#include <stdio.h>
int main (){
    int a,b;
    printf(" \n Write two positive integer: \n a:");
    scanf("%d", &a);
    printf("\n b:");
    scanf("%d", &b);

    if (a < 0 || b < 0 ){
        printf("Error, please write positive numbers");
    }
    else{
    while(a != b){
        if (a <= b){
            b = b - a;
        }
        if ( a > b){
            a = a - b;
        }
    }
    
        printf("\n The greatest common divisor: %d", a );
    }
    return 0;
}