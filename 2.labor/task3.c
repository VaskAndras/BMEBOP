#include <stdio.h>
#include <math.h>

int main() {
    printf("Enter the parameters of the parabolic equasion in (a, b, c) order \n");
    float a, b, c;
    scanf("%f %f %f", &a, &b, &c);
    float D = b * b - 4 * a * c;
    if (D < 0) {
        printf("The equasion has no real roots \n");
    } 
    else if (D == 0) {
        float x = -b / (2 * a);
        printf("The equasion has one real root: x1 = x2 = %.2f \n", x);
    } 
    else {
        float x1 = (-b - sqrt(D)) / (2 * a);
        float x2 = (-b + sqrt(D)) / (2 * a);
        printf("The equasion has two real roots: x1 = %.2f and x2 = %.2f \n", x1, x2);
    }
    return 0;
}