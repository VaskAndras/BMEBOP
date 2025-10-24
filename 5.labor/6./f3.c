#include <stdio.h>
int main(){
    int a[5];
    for(int i=0;i<5;i++){
        printf("Please enter the  number: %d ", i+1);
        scanf("%d",&a[i]);
    }
    int c = 5;

    while (1){
        if  (a[4] == 0){
            printf("End of program.\n"); 
            break;
        }
        printf("Please enter the %d. number: ",c);
        c++;
        for(int i=0;i<4;i++){
            a[i] = a[i+1];
        }
        scanf("%d",&a[4]);
        int sum = 0;
        for(int i=0;i<5;i++){
            sum += a[i];
        }
        printf("The average of the last 5 numbers: %d\n", sum/5);   
    }
    return 0;
}