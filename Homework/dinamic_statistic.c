#include <stdio.h>
#include <stdlib.h>


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
        if (input[i] != 0) {
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
    CharStat* a = malloc(sizeof(CharStat));
    if ( a == NULL ) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    a->Left = left;
    a->Right = right;
    a->character = '\0';              // belső csomópont
    a->count = left->count + right->count;
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
        return root;
    }

    // Két legkisebb elem kiválasztása
    int min1 = -1, min2 = -1;
    for (int i = 0; i < size; i++){
        if (array[i] == NULL) continue;
        if (min1 == -1 || array[i]->count < array[min1]->count) {
            min2 = min1;
            min1 = i;
        } else if (min2 == -1 || array[i]->count < array[min2]->count) {
            min2 = i;
        }
    }

    // Ha count egyenlő, ABC sorrend
    if (array[min1]->count == array[min2]->count &&
        array[min1]->character > array[min2]->character) {
        CharStat* temp = array[min2];
        array[min2] = array[min1];
        array[min1] = temp;
    }

    // Új csomópont létrehozása
    array[min1] = create_a_new_node(array[min1], array[min2]);
    array[min2] = NULL;

    // Tömb tömörítése
    int write = 0;
    for (int read = 0; read < size; read++){
        if (array[read] != NULL){
            array[write++] = array[read];
        }
    }
    for (int i = write; i < size; i++){
        array[i] = NULL;
    }

    // Rekurzív hívás
    return create_a_tree(array, size);
}
void free_huffman_tree(CharStat* root) {
    if (root == NULL) return;       // alap eset: üres csomópont
    free_huffman_tree(root->Left);  // bal ág felszabadítása
    free_huffman_tree(root->Right); // jobb ág felszabadítása
    free(root);                     // maga a csomópont felszabadítása
}

CharStat** make_pointer_array(CharStat *array, int size) {
    if (array == NULL || size <= 0) return NULL;

    // Pointer tömb létrehozása
    CharStat **ptr_array = malloc(size * sizeof(CharStat*));
    if (ptr_array == NULL) {
        perror("Memory allocation failed for pointer array");
        exit(EXIT_FAILURE);
    }

    // Feltöltjük pointerekkel
    for (int i = 0; i < size; i++) {
        ptr_array[i] = &array[i];
    }

    return ptr_array;  // pointer tömb visszaadása
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
    
    
 return 0;
    }