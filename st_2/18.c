#include <stdio.h>

int main() {
    double num, prev1 = 0, prev2 = 0;
    int inputCount = 0, tooLowCount = 0;

    printf("Enter floating-point numbers (123.456 to stop):\n");

    while (1) {
        printf("Number: ");
        scanf("%lf", &num);

        if (num == 123.456)
            break;

        inputCount++;

        if (inputCount >= 3) {
            double average = (prev1 + prev2) / 2.0;
            if (num < average) {
                printf("Too low!\n");
                tooLowCount++;
            }
        }

        prev2 = prev1;
        prev1 = num;
    }

    printf("\nTotal 'Too low!' cases: %d\n", tooLowCount);

    return 0;
}