#include <stdio.h>
int main (){
    int x;
    int choice;
    printf("Dear user!\n");
    printf("What would you like to do?\n");
    printf("Write 1 if zou want to see the first N squre numbers\n");
    printf("Write 2 if you want to see the square numbers less than N\n");
    scanf("%d", &choice);
    if (choice == 1){
        printf("Enter a number, I will print the first N square numbers!\n");
        scanf("%d", &x);
        for (int i=1; i<=x; i++){
            printf("%d ", i*i);
        }
        printf("\n");
    }
    if (choice == 2){
        printf("Enter a number, I will print the square numbers less than N!\n");
        scanf("%d", &x);
        for (int i=1; i*i<x; i++){
            printf("%d ", i*i);
        }
        printf("\n");
    }
    return 0;
}