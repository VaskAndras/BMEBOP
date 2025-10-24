#include <stdio.h>
int main (){ 
    double d = 1, j = 0;
    for (int i = 0; i < 3; i = i+1 )  {
        
        while ((j * j) < 3) {
        j = j + d;     
        }
        j = j - d;
        d = d / 10;
    }
    printf("%.2lf", j);
    return 0;
}