#include  <stdio.h>
#include  <math.h>

int main() {
    int x1, y1, x2, y2;
    printf("Import the first point coordinates (two integer) \n");
    scanf("%d %d", &x1, &y1);
    printf("Import the second point coordinates (two integer) \n");
    scanf("%d %d", &x2, &y2);
    float lenght = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    printf("The length of the vector is: %.2f \n", lenght);

    return 0;
}