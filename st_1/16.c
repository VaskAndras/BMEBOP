#include <stdio.h>
int main(){
    
    printf ("Write an integer: \n");
    
    float n, result;
    int scan = scanf("%f", &n);
    int intn = (int)n;

    if (scan != 1 || n < 0 || n -intn > 0 ){
        printf("\n Invalid input, please write a positive integer");
    }
    
    else{
        for (int i = 0; i <= n; i=i+1){
            result = result + i; 
        }

        printf("\n %.0f", result);
    }
    return 0;
}