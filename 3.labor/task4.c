#include <stdio.h>

int main() {
    double piover2=1, pi;
    for (double i = 2; i<= 2000; i = i+2 ){
    piover2 = piover2*((i*i)/ ((i-1)*(i+1)));
    }
    printf ("piover2: %lf ", piover2 );
    pi = piover2*2;
    printf("pi: %lf ", pi);
    return 0;
}
