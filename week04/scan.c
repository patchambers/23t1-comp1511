// Using scanf in loops by making use of its return value
// Pat Chambers (z5264081), 8/3/23
#include <stdio.h>

int main(void) {
    
    int num;
    int num2;

    // scanf returns the number of elements that are successfully scanned in
    // If we don't scan in the correct number of inputs (or if ctrl-d) is 
    // entered, we should exit the loop
    while (scanf("%d %d", &num, &num2) == 2) {
        printf("Scanned in: %d %d\n", num, num2);
    }

    /*
    // This is equivalent to:

    int result = scanf("%d %d", &num, &num2);
    while (result == 2) {
        printf("Scanned in: %d %d\n", num, num2);
        result = scanf("%d %d", &num, &num2);
    }
    */

    return 0;
}
