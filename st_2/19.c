#include <stdio.h>

int main() {
    int num, prev1 = 0, prev2 = 0;
    int inputCount = 0, mismatchCount = 0;

    printf("Enter positive integers (negative number to stop):\n");

    while (1) {
        printf("Number: ");
        scanf("%d", &num);

        if (num < 0)
            break;

        inputCount++;

        if (inputCount >= 3) {
            if (num != prev1 + prev2) {
                printf("Mismatch!\n");
                mismatchCount++;
            }
        }

        prev2 = prev1;
        prev1 = num;
    }

    printf("\nTotal 'Mismatch!' cases: %d\n", mismatchCount);

    return 0;
}