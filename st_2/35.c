#include <stdio.h>
#include <stdio.h>

int main() {
    char arr[60];
    int i, matchCount = 0;

    printf("Enter 60 characters:\n");
    for (i = 0; i < 60; i++) {
        printf("Character %d: ", i + 1);
        scanf(" %c", &arr[i]);
    }

    printf("\nLowercase consonants:\n");
    for (i = 0; i < 60; i++) {
        char c = arr[i];
        if (c >= 'a' && c <= 'z' && c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u') {
            printf("%c ", c);
            matchCount++;
        }
    }

    if (matchCount == 0)
        printf("Only vowels or non-lowercase\n");

    return 0;
}