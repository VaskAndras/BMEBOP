#include <stdio.h>

int main() {
    double num, prev1 = 0, prev2 = 0;  // To store the previous two inputs
    int count = 0;                      // To count "Too low!" cases
    int inputCount = 0;                 // To track how many numbers have been entered

    printf("Enter real numbers (0 to stop):\n");

    while (1) {
        printf("Number: ");
        scanf("%lf", &num);

        // Stop when user enters 0
        if (num == 0)
            break;

        inputCount++;

        // Starting from the third input
        if (inputCount >= 3) {
            double average = (prev1 + prev2) / 2.0;
            if (num <= average) {
                printf("Too low!\n");
                count++;
            }
        }

        // Shift previous values
        prev2 = prev1;
        prev1 = num;
    }

    printf("\nTotal 'Too low!' cases: %d\n", count);

    return 0;
}