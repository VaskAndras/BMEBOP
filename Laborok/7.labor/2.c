#include <stdio.h>


void (float lenght, float* volume, float* surface_area){
    *volume = lenght * lenght * lenght;
    *surface_area = 6 * lenght * lenght;
}

int main(){
    float lenght;
    float volume;
    float surface_area; 
    printf("Enter the lenght of the cube: ");
    scanf("%f", &lenght);
    calculate(lenght, &volume, &surface_area);
    printf("Volume: %.2f\n", volume);
    printf("Surface Area: %.2f\n", surface_area);
    
    return 0;
}
