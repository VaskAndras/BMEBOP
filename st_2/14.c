#include <stdio.h>

int main() {
    int num, prev1 = 0, prev2 = 0;
    int inputCount = 0, invalidCount = 0;

    printf("Enter integers (program stops on non-integer input):\n");

    while (1) {
        printf("Number: ");
        if (scanf("%d", &num) != 1) {
            break; // terminate on non-integer input
        }

        inputCount++;

        if (inputCount >= 3) {
            if (num % 2 != 0 || num <= prev1 || num <= prev2) {
                printf("Invalid!\n");
                invalidCount++;
            }
        }

        prev2 = prev1;
        prev1 = num;
    }

    printf("\nTotal 'Invalid!' cases: %d\n", invalidCount);

    return 0;
}