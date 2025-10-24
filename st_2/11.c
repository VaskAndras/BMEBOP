#include <stdio.h>

int main() {
    int num;              // current input
    int prev1 = 0;        // most recent previous number
    int prev2 = 0;        // the one before that
    int inputCount = 0;   // number of inputs entered so far
    int dropCount = 0;    // count of "Drop detected!" cases

    printf("Enter integers (0 to stop):\n");

    while (1) {
        printf("Number: ");
        scanf("%d", &num);

        // Stop when user enters 0
        if (num == 0)
            break;

        inputCount++;

        // Starting from the third number, check for a drop
        if (inputCount >= 3) {
            if (num < prev1 && num < prev2) {
                printf("Drop detected!\n");
                dropCount++;
            }
        }

        // Update previous values
        prev2 = prev1;
        prev1 = num;
    }

    printf("\nTotal 'Drop detected!' cases: %d\n", dropCount);

    return 0;
}