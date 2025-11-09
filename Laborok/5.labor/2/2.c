#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int array[10], i;

    for (i = 0; i < 10; i = i + 1)
        array[i] = i;
    i = 0;
    while (true) {
        printf("%dth element: %d\n", i, array[i]);
        i += 1;
    }

    return 0;
}

