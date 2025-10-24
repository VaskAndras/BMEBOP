#include <stdio.h>
int main(){
    int a[10];
    for(int i=0;i<10;i++){
        printf("Please enter the %d. number: ",i+1);
        scanf("%d",&a[i]);
}
    printf("\n Array: ");
    for(int i=0;i<10; i++){
        printf("%d ",a[i]);
    }
    printf("\n Array: ");
    for(int i=0;i<10; i++){
        printf(" [%d]= %d ", i, a[i]);
    }
    int min = a[0], place;
    for(int i=1;i<10;i++){
        if(a[i]<min){
            min = a[i];
            place = i;
        }
}
    printf("\n The least: %d," , min);
    printf("\n Marked:");
    for (int i=0;i<10;i++){
        if(i==place){
            printf(" %d[MIN] ", a[i]);
        }
        else{
            printf(" %d ",a[i]);
        }
    }
    return 0;
}
