#include <stdio.h>
#include <math.h>

float cube(float n){
    return n*n*n;
}

float abst(float n){
    if(n<0) return -n;
    return n;
}

int main(){
        printf("%8s %8s %8s %8s\n", "a", "a^3", "|a|", "sin(a)");
    for (float i = -1; i <= 1; i = i + 0.1){
        printf("%8.4f %8.4f %8.4f %8.4f\n", i, cube(i), abst(i), sin(i));
    }
    return 0;
}