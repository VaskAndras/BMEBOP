#include < stdio.h>
int main() {
    int a[10];
    for (int i = 0; i < 10; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &a[i]);
    }
    int max = a[0];
    for (int i = 1; i < 10; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    printf("The largest number is: %d\n", max);
    return 0;
}   