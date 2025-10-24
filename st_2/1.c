#include <stdio.h>
int main() {
    int a[10];
    for (int i = 0; i < 10; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &a[i]);
    }
    int min = a[0];
    for (int i = 1; i < 10; i++) {
        if (a[i] < min) {
            min = a[i];
}
    }
    printf("The smallest number is: %d\n", min);
    return 0;
}