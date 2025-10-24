#include <stdio.h>
int main(){
    float f[10];
    float sum = 0; 
    for (int i = 1; i < 11; i= i+1)
    {
        printf("enter the %d th element:", i);
        scanf("%f", &f[i-1]);
        sum = sum + f[i-1];}
    sum = sum/10;

    printf("The averange of the elements %f:", sum);
    return 0;    
}
