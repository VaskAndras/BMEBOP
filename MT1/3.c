#include <stdio.h>
int main(){
    int arr[15];
    for (int i = 0; i < 15; i++){
        printf("\n Please enter the %d th integer: ", i+1);
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < 15; i++){
        if (arr[i]%5==0 && arr[i]%3 != 0){
            printf("\n %d", arr[i]);
        }
    }
return 0;
}
