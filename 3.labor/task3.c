#include <stdio.h>
int main(){
    double b=1 , e=1;
    for (int i= 1 ; i< 21; ++i){
    b = b*i;
    e= e +(1/b);

} 
printf ("%lf" , e );
    return 0;
} 