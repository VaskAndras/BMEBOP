#include <stdio.h>
int main() {
    double a[10];
    for (int i = 0; i < 10; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%lf", &a[i]);
    }
    double max = a[0];
    double min = a[0];
    for (int i = 1; i < 10; i++) {
        if (a[i] > max) {
            max = a[i];
        }
        if (a[i] < min) {
            min = a[i];
        }
    }
    printf("The largest number is: %lf\n", max);
    printf("The smallest number is: %lf\n", min);
    return 0;
}