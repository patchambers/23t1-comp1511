// Procedures that demonstrate various array operations
// Pat Chambers (z5264081), 8/3/23

#include <stdio.h>

#define MAX_SIZE 10

// We need function prototypes here because our function implementations are 
// below the main function
void odd_only();
void copy_array();
void largest_character();

int main(void) {
    // This main function just calls all of the array procedures implemented
    // below
    odd_only();
    copy_array();
    largest_character();

    return 0;
}

// Initialises an array of ints, then adjusts the array to make every element 
// odd, before printing the array out
void odd_only() {

    int array[MAX_SIZE] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    
    // Loop through each value of the array by indexing it with i, which is
    // incremented from 0 to 9
    int i = 0;
    while (i < MAX_SIZE) {
        // If value is even, add 1 to it to make it odd
        if (array[i] % 2 == 0) {
            array[i] += 1;
        }
        i++;
    }
    // Print out the whole array using another while loop
    printf("Odd only array: ");
    int j = 0;
    while (j < MAX_SIZE) {
        printf("%d ", array[j]);
        j++;
    }
    printf("\n");
}

// Initialises 2 arrays of doubles (first of length 3, second of length 10). 
// Copies the values of the first array into the first 3 elements of the second
// array, then prints out the second array
void copy_array() {
    double original[3] = {1.1, 1.2, 1.3};
    double copy[MAX_SIZE] = {0.0};

    int i = 0;
    while (i < 3) {
        copy[i] = original[i];
        i++;
    }

    printf("Copied array: ");
    int j = 0;
    while (j < MAX_SIZE) {
        printf("%lf ", copy[j]);
        j++;
    }
    printf("\n");
}

// Finds the character with the largest ascii value in an array and prints out 
// this character
void largest_character() {
    char word[8] = {'e', 'f', 'g', 'h', 'a', 'b', 'c', 'd'};
    char largest_char = word[0];
    // Loop through the array so we can check each element
    for (int i = 0; i < 8; i++) {
        // If we come across a character that is larger than largest_char, then
        // update largest_char
        if (word[i] > largest_char) {
            largest_char = word[i];
        }
    }
    printf("Largest character: %d\n", largest_char);

}
