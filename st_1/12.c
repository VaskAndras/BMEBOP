#include <stdio.h>
int main(){
    float f, g;
    printf ("Write two positive integers: \n");
    int scan = scanf("%f %f", &f,&g);
    int a = (int)f, b= (int)g;
    if (scan != 2 || f != a || g != b){
        printf("\n Invalid input, please write two integers");
    }
    
    else{
        if (a<b){
            int temp = a;
            a = b;
            b = temp;   
        }
        if (a<0){
            a = -a;
        }
        if (b<0){
            b = -b;
        }
        while (a>=b){
            a = a - b;
        }
        if (f<0 || g<0){
            a = -a;
        }
        printf("\n The modulo: %d", a);
    }
    return 0;
}