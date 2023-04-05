// Malloc use and motivation
// Pat Chambers (z5264081), 5/4/23

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int *create_array();

int main(void) {
   
    int *array = create_array();

    for (int i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}

// Allocates memory for an array in the heap and initialises this array
// Returns: pointer to this array
int *create_array() {
    
    // This will allocate memory for this array in this function's local memory 
    // (in the stack), which will be destroyed after the function ends
    // Even if we return the array, we're just returning a pointer to the array 
    // (which is in the destroyed function memory)
    // int array[SIZE];

    // If we malloc the memory for the array, it will allocate it in the heap, 
    // where it will persist until we tell the program to free it. 
    int *array = malloc(SIZE * sizeof(int));
    for (int i = 0; i < SIZE; i++) {
        array[i] = 10 * i;
    }

    return array;
}
