// Procedures that demonstrate various array operations
// Pat Chambers (z5264081), 8/3/23

#include <stdio.h>

#define MAX_SIZE 10

void odd_only();
void copy_array();
void largest_character();

int main(void) {

    odd_only();
    copy_array();
    largest_character();

    return 0;
}


void odd_only() {

    int array[MAX_SIZE] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    
    int i = 0;
    while (i < MAX_SIZE) {
        if (array[i] % 2 == 0) {
            array[i] += 1;
        }
        i++;
    }

    printf("Odd only array: ");
    int j = 0;
    while (j < MAX_SIZE) {
        printf("%d ", array[j]);
        j++;
    }
    printf("\n");
}

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

void largest_character() {
    char word[8] = {'e', 'f', 'g', 'h', 'a', 'b', 'c', 'd'};
    char largest_char = word[0];
    for (int i = 0; i < 8; i++) {
        if (word[i] > largest_char) {
            largest_char = word[i];
        }
    }
    printf("Largest character: %d\n", largest_char);

}
