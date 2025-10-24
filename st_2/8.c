#include <stdio.h>
int main(){
    int a = 1, b = 0, c = 0; 
    int count = 0;
    int countlow = 0;
    while(a!=0){
        count++;
        c=b;
        b=a;
        scanf("%d",&a);
        if (count > 2 && a < (b+c)/2){
        printf("Too low"); 
        countlow++;
        }
        }
return 0;

    }
