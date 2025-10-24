#include <stdio.h>
void separate_odd_even(int a[], int size, int** odd, int** even)
{
    int* odd_count = NULL;
    int* even_count = NULL;
    int even_index = 0;
    int odd_index = 0;

    for (int i = 0; i < size; i++) {
        if (a[i] % 2 == 0) { 
            even_count = realloc(even_count, (( even_index + 1) * sizeof(int)));
            even_count[even_index] = a[i];
            even_index++;

            
        } else {
            odd_count = realloc(odd_count, (( odd_index + 1) * sizeof(int)));
            odd_count[odd_index] = a[i];
            odd_index++;
        }
    }
    even = realloc(even, (even_index) * sizeof(int));
    odd = realloc(odd, (odd_index) * sizeof(int));
    *odd = odd_count;
    *even = even_count;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int* odd = NULL;
    int* even = NULL;

    separate_odd_even(arr, size, &odd, &even);

    printf("Odd numbers: ");
    for (int i = 0; i < (sizeof(odd)/sizeof(odd[0])); i++) {
        if (odd[i] != 0) {
            printf("%d ", odd[i]);
        }
    }
    printf("\n");

    printf("Even numbers: ");
    for (int i = 0; i < (sizeof(even)/sizeof(even[0])); i++) {
        if (even[i] != 0) {
            printf("%d ", even[i]);
        }
    }
    printf("\n");

    return 0;
}