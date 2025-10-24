#include <stdio.h>
int main (){
    float f=1 , d=1;
    for (int i = 1; i < 4; i = i+1){
        while (f*f < 5){
            f = f + d;
        }
        f = f - d;
        d = d/10;
    }
    printf ("Square root of 5 is approximately: %.2f\n", f);
    return 0;
}