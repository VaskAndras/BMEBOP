#include <stdio.h>

int main() {
    double num, prev1 = 0, prev2 = 0;
    int inputCount = 0, tooSmallCount = 0;

    printf("Enter real numbers (program stops when a number > 1000 is entered):\n");

    while (1) {
        printf("Number: ");
        scanf("%lf", &num);

        if (num > 1000)
            break;

        inputCount++;

        if (inputCount >= 3) {
            if (!(num >= 2 * prev1 && num >= 2 * prev2)) {
                printf("Too small!\n");
                tooSmallCount++;
            }
        }

        prev2 = prev1;
        prev1 = num;
    }

    printf("\nTotal 'Too small!' cases: %d\n", tooSmallCount);

    return 0;
}