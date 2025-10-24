#include <stdio.h>

int main() {
    int num, prev1 = 0, prev2 = 0;
    int inputCount = 0, notDivisibleCount = 0;

    printf("Enter non-negative integers (-99 to stop):\n");

    while (1) {
        printf("Number: ");
        scanf("%d", &num);

        if (num == -99)
            break;

        if (num < 0) {
            printf("Please enter a non-negative integer.\n");
            continue;
        }

        inputCount++;

        if (inputCount >= 3) {
            if (prev1 == 0 || prev2 == 0 || num % prev1 != 0 || num % prev2 != 0) {
                printf("Not divisible!\n");
                notDivisibleCount++;
            }
        }

        prev2 = prev1;
        prev1 = num;
    }

    printf("\nTotal 'Not divisible!' cases: %d\n", notDivisibleCount);

    return 0;
}