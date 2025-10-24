#include <stdio.h>

#include <stdio.h>

int main() {
    int a[] = {1, 2, 3, 4, 5};
    int n = sizeof(a) / sizeof(a[0]);
    char *sep = "[";   

    for (int i = 0; i < n; i++) {
        printf("%s%d", sep, a[i]);
        sep = ", ";    
    }

    printf("]\n");     
    return 0;
}