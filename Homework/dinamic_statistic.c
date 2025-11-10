#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct CharStat {
    char character;
    int count;
    struct CharStat *Left;
    struct CharStat *Right;
} CharStat;

CharStat* compress_chars_dynamic(const int *input, int size, int *out_count) {
    int count = 0;

    // firstly count the number of nonzero elements
    for (int i = 0; i < size; i++) {
        if (input[i] != 0) {
            count++;
        }
    }

    // is there is no nonzero we go back with the nullpointer
    if (count == 0) {
        *out_count = 0;
        return NULL;
    }

    // Dinamic memory allocation fro the counting
    CharStat *result = malloc(count * sizeof(CharStat));
    if (result == NULL) {
        perror("Memóriafoglalási hiba");
        exit(EXIT_FAILURE);
    }

    // filling the new array
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (input[i] != 0) { // we want just the nonyero elements
            result[j].character = (char)i;
            result[j].count = input[i];
            j++;
        }
    }
    // passing back the length
    *out_count = count;

    // passing back the array
    return result;
}

CharStat* create_a_new_node(CharStat *left, CharStat *right) {
// This is a function for creating a new node of the tree
    //lets allocate memory for this task
    CharStat* a = malloc(sizeof(CharStat));
    if ( a == NULL ) { // allocation check
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    // filling with properties
    a->Left = left;   
    a->Right = right; 
    a->character = '\0'; // bc it's inside 
    a->count = left->count + right->count; // the sum of the counts of the leafs is the value of this point 
    return a;
}

CharStat* create_a_tree(CharStat **array, int size){
    // this is a recursive function for creating a pointer which point to the root of our tree.

    // Count the active elements
    int count = 0;
    for (int i = 0; i < size; i++){
        if (array[i] != NULL) count++;
    }

    // if there is just one active pointer
    if (count == 1) {
        // creating a new pointer for the root
        CharStat* root = NULL;
        // look for the only one (this is not really neccesarry, bc it schould be at the beginning of the array)
        for (int i = 0; i < size; i++) {
            if (array[i] != NULL) {
                root = array[i];
                break;
            }
        }
        free(array); // we dont want the array anymore
        return root; // end of recursion
    }

    // schearching for the two smallest value from the array 
    int min1 = -1, min2 = -1;
    for (int i = 0; i < size; i++){ 
        if (array[i] == NULL) continue; // skipping the null pointers 
        if (min1 == -1 || array[i]->count < array[min1]->count) { // this is for skipping the first element as min1 bc it can't be 
            min2 = min1; 
            min1 = i; 
        } else if (min2 == -1 || array[i]->count < array[min2]->count) { // same here
            min2 = i; 
        }
    }

    // just some extra, if two values are equal, the order will be by character code order
    if (array[min1]->count == array[min2]->count && array[min1]->character > array[min2]->character) { 
        //swiching if they aren't at the right order
        CharStat* temp = array[min2];
        array[min2] = array[min1];
        array[min1] = temp;
    }

    // Creatng a new node from the least 2 values
    array[min1] = create_a_new_node(array[min1], array[min2]);
    array[min2] = NULL;

    // pushing the zero values to the back 
    int write = 0;
    // goes throught the array and push every zero to the rear like a bubble sort  
    for (int read = 0; read < size; read++){
        // it's put everyting one before it was if there is no null. If there is, it's skips that, to overwrite it next time 
        if (array[read] != NULL){
            // operate, then incrase
            array[write++] = array[read];
        }
    }
    // writing the remaining parts with zeros
    for (int i = write; i < size; i++){
        array[i] = NULL; 
    }

    // recursion part 
    return create_a_tree(array, size);
}
void free_huffman_tree(CharStat* root) {
// this is a function for free the binary tree
    if (root == NULL) return;       // the end point check
    free_huffman_tree(root->Left);  // free the left side recursively
    free_huffman_tree(root->Right); // free the right side recursively
    free(root);                     // free the root
}

CharStat** make_pointer_array(CharStat *array, int size) {
// from a dinamic array, creating a dinamic pointer array, to opeate the pointers of the array one by one

    if (array == NULL || size <= 0) return NULL; // checking the original array
    
    // allocate memory for the new array 
    CharStat **ptr_array = malloc(size * sizeof(CharStat*));
    if (ptr_array == NULL) { // allocation check
        perror("Memory allocation failed for pointer array");
        exit(EXIT_FAILURE); 
    }

    // filling with pointers of the elements of the original arrays
    for (int i = 0; i < size; i++) {
        ptr_array[i] = &array[i];
    }

    return ptr_array;  // returning 
}

typedef struct {
    char ch;
    char code[32];
} huffman_codes;


void fill_codes(CharStat* root, huffman_codes* arr, char*newcode,int *index ,int depth){
    //the gole of the function is to fill the array with recursion but an another function will be needed
    if (root == NULL) return;

    // If I found a leaf
    if (root->Left == NULL && root->Right == NULL) {
    newcode[depth] = '\0'; // the last character of the code will be the end of string
    arr[*index].ch = root->character; //the character of the next element of the result array will be the character of the leef
    strcpy(arr[*index].code, newcode); // the code part of the new element will be the newcode
    (*index)++; //increase bc it's needed for the next element and it's a pointer bc it's value goes thruough the recursion
    return; // end of this part of the recursion
    }
    
    // Left side  part the code will be 0
    newcode[depth] = '0'; // the 
    fill_codes(root->Left, arr, newcode, index,depth + 1);

    // right side part the code will be 1
    newcode[depth] = '1';
    fill_codes(root->Right, arr, newcode, index, depth + 1);
}

huffman_codes *fill_the_array(CharStat* root, int size){
    // the goal is to give back a perfectly sized array with the codes
    huffman_codes* a = (huffman_codes*)malloc(size*sizeof(huffman_codes));
    char newcode[32]={0}; //should be enought
    int index = 0;
    int depth = 0;
    fill_codes(root, a, newcode, &index, depth); 
    return a;
}

int main(){
    int List_of_characters[128];
    
    for (int i = 0; i<128; i++){
        List_of_characters[i] = 0;
    }

    printf("Please write ");

    char scan;
    while (scanf("%c", &scan ) == 1){
        int int_scan = (int)scan;
        List_of_characters[int_scan]++;
    }

    printf("\nFrequency\n");
    for (int i = 0; i < 128; i++){
        char chari = (char)i;
        printf("%c appeard %d times\n", chari, List_of_characters[i]);
    }


    int count = 0;
    CharStat *filtered = compress_chars_dynamic(List_of_characters, 128, &count);

    printf("Nem nullás karakterek (%d):\n", count);
    for (int i = 0; i < count; i++) {
        printf("'%c' → %d\n", filtered[i].character, filtered[i].count);
    }

    printf("ordered solution");
    for (int i = 0; i < count; i++) {
        printf("'%c' → %d\n", filtered[i].character, filtered[i].count);
    }
    

    CharStat** Filtered_extra = make_pointer_array(filtered, count);
    CharStat * Tree = create_a_tree(Filtered_extra, count);
    huffman_codes * codes = fill_the_array(Tree, count);
    
    for (int i = 0; i < count; i++) {
        printf("\n'%c'", codes[i].ch);
            for (int j = 0; codes[i].code[j] != '\0'; j++ ){
                printf("%c",codes[i].code[j]);
            }
    }

    free(filtered);
    free_huffman_tree(Tree);
    free(codes);
    
 return 0;
    }
  