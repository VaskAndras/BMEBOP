#include <stdio.h>

int main() {
    char arr[120];
    int i, count = 0;

    printf("Enter 120 characters:\n");
    for (i = 0; i < 120; i++) {
        printf("Character %d: ", i + 1);
        scanf(" %c", &arr[i]);
    }

    printf("\nSpecial characters following digits (in reverse order):\n");
    for (i = 119; i > 0; i--) {
        if (arr[i - 1] >= '0' && arr[i - 1] <= '9' && !((arr[i] >= 'a' && arr[i] <= 'z') || (arr[i] >= 'A' && arr[i] <= 'Z') || (arr[i] >= '0' && arr[i] <= '9'))) {
            printf("%c ", arr[i]);
            count++;
        }
    }

    if (count < 5)
        printf("\nMinimal special flow\n");

    return 0;
}