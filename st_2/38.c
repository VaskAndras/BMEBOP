#include <stdio.h>

int main() {
    char arr[75];
    int i, matchCount = 0;

    printf("Enter 75 characters:\n");
    for (i = 0; i < 75; i++) {
        printf("Character %d: ", i + 1);
        scanf(" %c", &arr[i]);
    }

    printf("\nLowercase consonants not preceded by space (in reverse order):\n");
    for (i = 74; i > 0; i--) {
        char c = arr[i];
        if (c >= 'a' && c <= 'z' && c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' && arr[i-1] != ' ') {
            printf("%c ", c);
            matchCount++;
        }
    }

    if (matchCount == 0)
        printf("No clean consonants\n");

    return 0;
}