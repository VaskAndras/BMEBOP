#include <stdio.h>
int main (){
    int n, d ;
    printf("\n Write a positive integer \n");
    scanf("%d", &n);
    
    if (n<0) { printf("Error, please write a posotive integer."); }

    else{
    while (n/10 > 0){
        d = d*(n%10);
        n = n/10;
     }
    printf ("\n The product of the digits: \n %d", d);
    printf ("\n \n \n %d", n);
    }
    return 0;
}