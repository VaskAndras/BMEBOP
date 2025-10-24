#include <stdio.h>

int main() {
    int prev2 = 0, prev1 = 0, current = 0;
    int count = 0;
    int inputCount = 0;

    printf("Enter integers (0 to stop):\n");

    while (1) {
        scanf("%d", &current);

        if (current == 0)  // Terminate on 0
            break;

        inputCount++;

        if (inputCount >= 3) {
            if (current < prev1 && current < prev2) {
                printf("Drop detected!\n");
                count++;
            }
        }

        // Shift the numbers for the next iteration
        prev2 = prev1;
        prev1 = current;
    }

    printf("Total drops detected: %d\n", count);

    return 0;
}