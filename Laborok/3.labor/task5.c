#include <stdio.h>
int main (){
    double piover4 = 0, pi;
    for (double i = 0; i <= 100; i = i + 1 ){

    int i2 = (int)i ; 

    if (i2%2 == 0){
    piover4 = piover4 + (1/(1+2*i));
    }    

    if (i2%2 == 1){
    piover4 = piover4 - (1/(1+2*i));   
    }
}
printf("%lf ", piover4);
pi = piover4*4;
printf("%lf ", pi );
    return 0;
}