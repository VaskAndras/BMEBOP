#include <stdio.h>

int main() {
    int rows;
    printf("Enter the number of rows: ");
    int s = scanf("%d", &rows);

    if (s != 1 || rows <= 0) {
        printf("Error: invalid input!\n");
    } else {
        for (int i = 1; i <= rows; i++) {
            // szóközök a bal oldalon
            for (int j = 1; j <= rows - i; j++) {
                printf(" ");
            }
            // csillagok száma: 2*i - 1
            for (int j = 1; j <= 2*i - 1; j++) {
                printf("*");
            }
            printf("\n");
        }
    }

    return 0;
}

