#include <stdio.h>
void arraysearch(int arr[], int size, int target, int* return_i){
    *return_i = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            *return_i = i;
            return;
        }
    }
}

int* array_search_for_address(int arr[], int size, int target){
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return &arr[i];
        
            }
        }        
            return NULL;
}
int main(){
    int arr[] = {4, 2, 7, 1, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;
    int index;
    int* address;
    int* p;

    int x = 10;
    p = &x;


    printf("Enter an integer to search for: ");
    scanf("%d", &target);
    
    arraysearch(arr, size, target, &index);
    address = array_search_for_address(arr, size, target);
    

    if (index != -1) {
        printf("Element %d found at index %d.\n", target, index);
        printf("Element %d found at address %p.\n", target, address);
    } else {
        printf("Element %d not found in the array.\n", target);
    }
    
    return 0;
}