// Demo code to show some example arithmetic expressions in C.
// Patrick Chambers (z5264081), 07/06/22

#include <stdio.h>

int main(void) {
    
    printf("7 / 2 = %d\n", 7 / 2);
    printf("7 %% 2 = %d\n", 7 % 2);

    printf("(3.0 / 2) + 1 = %lf\n", (3.0 / 2) + 1); 
    printf("(3 / 2) + 1.0 = %lf\n", (3 / 2) + 1.0);

    // Printing ('a' + 5) as an integer and then a char
    printf("'a' + 5 = %d\n", 'a' + 5);
    printf("'a' + 5 = %c\n", 'a' + 5);

    // Printing ('F' - 'A' + 'a') as an integer and then a char
    printf("'F' - 'A' + 'a' = %d\n", 'F' - 'A' + 'a');
    printf("'F' - 'A' + 'a' = %c\n", 'F' - 'A' + 'a');

}
