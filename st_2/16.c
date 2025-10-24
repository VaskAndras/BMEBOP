#include <stdio.h>

int main() {
    int num, prev1 = 0, prev2 = 0;
    int inputCount = 0, outOfRangeCount = 0;

    printf("Enter integers (9999 to stop):\n");

    while (1) {
        printf("Number: ");
        scanf("%d", &num);

        if (num == 9999)
            break;

        inputCount++;

        if (inputCount >= 3) {
            int min = (prev1 < prev2) ? prev1 : prev2;
            int max = (prev1 > prev2) ? prev1 : prev2;

            if (num < min || num > max) {
                printf("Out of range!\n");
                outOfRangeCount++;
            }
        }

        prev2 = prev1;
        prev1 = num;
    }

    printf("\nTotal 'Out of range!' cases: %d\n", outOfRangeCount);

    return 0;
}