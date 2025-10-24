#include <stdio.h>

int main() {
    char arr[90];
    int i, count = 0;

    printf("Enter 90 characters:\n");
    for (i = 0; i < 90; i++) {
        printf("Character %d: ", i + 1);
        scanf(" %c", &arr[i]);
    }

    printf("\nAlphabetic characters before 'm' or 'M':\n");
    for (i = 0; i < 90; i++) {
        char c = arr[i];
        if ((c >= 'a' && c < 'm') || (c >= 'A' && c < 'M')) {
            printf("%c ", c);
            count++;
        }
    }

    if (count > 45)
        printf("\nEarly letters rule\n");

    return 0;
}