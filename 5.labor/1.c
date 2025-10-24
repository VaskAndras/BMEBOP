#include <stdio.h>

int main(void) {
    char letter;
    while (scanf("%c", &letter) == 1) {
        printf("letter='%c', letter=%d\n", letter, letter);
    }

    return 0;
}