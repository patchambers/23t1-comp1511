// Tutorial 2 programming exercise with procedures
// Pat Chambers (z5264081), 22/02/23

#include <stdio.h>

void print_error() {
    // function code goes here
    printf("Error: invalid input\n");
}

int main(void) {

    // Scan in a and b
    int a;
    int b;
    scanf("%d", &a);
    scanf("%d", &b);

    if (a < b) {
        // if a < b print error using procedure
        print_error();
    } else if (b == 0) {
        // if b == 0 print error using procedure
        // These two conditions could also be combined into one 
        // using a logic operator!
        print_error();
    } else {
        // Print out a / b
        printf("As an integer: a / b = %d\n", a / b);
        printf("As a double:   a / b = %d\n", a * 1.0 / b);
    }

    return 0;
}
