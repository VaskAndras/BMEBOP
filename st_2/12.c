#include <stdio.h>

int main() {
    int time;              // current input
    int prev1 = 0;         // most recent previous time
    int prev2 = 0;         // the one before that
    int inputCount = 0;    // number of inputs entered so far
    int tooCloseCount = 0; // count of "Too close!" cases

    printf("Enter positive integers for time in minutes (0 to stop):\n");

    while (1) {
        printf("Time: ");
        scanf("%d", &time);

        // Stop when user enters 0
        if (time == 0)
            break;

        // Ignore negative input (since only positive allowed)
        if (time < 0) {
            printf("Please enter a positive integer.\n");
            continue;
        }

        inputCount++;

        // Starting from the third input
        if (inputCount >= 3) {
            if (!(time >= prev1 + 30 && time >= prev2 + 30)) {
                printf("Too close!\n");
                tooCloseCount++;
            }
        }

        // Update previous values
        prev2 = prev1;
        prev1 = time;
    }

    printf("\nTotal 'Too close!' cases: %d\n", tooCloseCount);

    return 0;
}