

// Merge two sorted subarrays: left part of length left_length, right part of length right_length
void merge(CharStat *array, int left_length, int right_length){
    CharStat *Left = (CharStat*)malloc(left_length * sizeof(CharStat));
    CharStat *Right = (CharStat*)malloc(right_length * sizeof(CharStat));
    // Error handling 
    if (Left == NULL || Right == NULL) {
        perror("Memory allocation error in merge");
        exit(EXIT_FAILURE);
    }

    // Copy data to temporary arrays
    //simple copy, elemently
    for (int i = 0; i < left_length; i++) {
        Left[i] = array[i];
    }
    for (int i = 0; i < right_length; i++) {
        Right[i] = array[left_length + i];
    }
    
    // initializeing
    int leftcount = 0, rightcount = 0, overwrite = 0;

    // Merge elements back into original array
    // check if they are in the range
    while (leftcount < left_length && rightcount < right_length) {
        // Smaller goes first and if equal the abc order matter
        if (Left[leftcount].count > Right[rightcount].count || (Left[leftcount].count == Right[rightcount].count && Left[leftcount].character >= Right[rightcount].character)) {
        
            // operate than add one
            array[overwrite++] = Left[leftcount++];
        
        // other case
    } else {
            // same as above
            array[overwrite++] = Right[rightcount++];
        }
    }

    // Copy any remaining elements from Left
    while (leftcount < left_length) {
        array[overwrite++] = Left[leftcount++];
    }

    // Copy any remaining elements from Right
    while (rightcount < right_length) {
        array[overwrite++] = Right[rightcount++];
    }

    // Free up the memory
    free(Left);
    free(Right);
}

// Recursive merge sort function
void merge_sort(CharStat *array, int length){
    // check if it's too short, if is, we dont have to change anyting.
    if (length <= 1) return;
    // calculates the left and right half of the array
    int left_length = length / 2;
    int right_length = length - left_length;

    // recursive part
    // we will be in the array all the time but now we have to take parts of that 
    //the left side is basically just the first some elemets till left  
    merge_sort(array, left_length);
    // right part's pointer is just shifted with the length of the left part ( Black magic :) ) 
    merge_sort(array + left_length, right_length);
    // this will do the hard work.
    merge(array, left_length, right_length);
}

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