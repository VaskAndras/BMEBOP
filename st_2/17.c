#include <stdio.h>

int main() {
    int num, prev1 = 0, prev2 = 0;
    int inputCount = 0, noMatchCount = 0;
    int zeroStreak = 0;

    printf("Enter integers (two consecutive zeros to stop):\n");

    while (1) {
        printf("Number: ");
        scanf("%d", &num);

        if (num == 0) {
            zeroStreak++;
            if (zeroStreak == 2)
                break;
        } else {
            zeroStreak = 0;
        }

        inputCount++;

        if (inputCount >= 3 && num != 0) {
            if ((prev1 != 0 && num % prev1 == 0) || (prev2 != 0 && num % prev2 == 0)) {
                // okay
            } else {
                printf("No match!\n");
                noMatchCount++;
            }
        }

        prev2 = prev1;
        prev1 = num;
    }

    printf("\nTotal 'No match!' cases: %d\n", noMatchCount);

    return 0;
}