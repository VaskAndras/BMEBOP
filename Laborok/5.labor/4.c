#include <stdio.h>
int main(){
    int a[10];
    for(int i=0;i<10;i++){
        printf("Please enter the %d. number: ",i+1);
        scanf("%d",&a[i]);
}
for (int i=0;i<10;i++){
    for (int j=0;j<10;j++){
        printf("%d",a[j]);
    }
    printf("\n");
    int c;
    for (int j=0;j<9;j++){
       c = a[j];
       a[j] = a[j+1];
       a[j+1] = c;
    }       
}
    return 0;
}
