#include <stdio.h>

int main(){
    int lenght;
    printf("Length of the line\n");
    scanf("%d", &lenght);
    printf ("+");
    for (int i=0; i<lenght; i++){
        printf("-");
    }
    printf ("+\n");
    return 0;
}