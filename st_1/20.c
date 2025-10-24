#include <stdio.h>

int main() {
    float f_height, f_width;
    printf("Enter the height and width of the rectangle: ");
    int s = scanf("%f %f", &f_height, &f_width);

    int height = (int)f_height;
    int width  = (int)f_width;

    // Input ellenőrzés: pozitív egész számok
    if (s != 2 || height <= 0 || width <= 0 || f_height != height || f_width != width) {
        printf("Error: invalid input!\n");
   
    }
    else{
        // Felső sor
        printf("+");
        for (int i = 0; i < width; i++) {
            printf("-");
        }
        printf("+\n");

        // Középső sorok
        for (int i = 0; i < height; i++) {
            printf("|");
            for (int j = 0; j < width; j++) {
                printf(".");
            }
            printf("|\n");
        }

        // Alsó sor
        printf("+");
        for (int i = 0; i < width; i++) {
            printf("-");
        }
        printf("+\n");
    }
    return 0;
}