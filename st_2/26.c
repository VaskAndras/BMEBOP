#include <stdio.h>

int main() {
    int arr[30];
    int i, validCount = 0;

    printf("Enter 30 positive integers:\n");
    for (i = 0; i < 30; i++) {
        printf("Number %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nNumbers divisible by 3 but not by 5 (in reverse order):\n");
    for (i = 29; i >= 0; i--) {
        if (arr[i] % 3 == 0 && arr[i] % 5 != 0) {
            printf("%d ", arr[i]);
            validCount++;
        }
    }

    if (validCount == 30)
        printf("\nAll valid\n");
    else if (validCount == 0)
        printf("None match the condition.\n");

    return 0;
}