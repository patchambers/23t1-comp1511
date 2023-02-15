// Program to print a cat face and demonstrate printing backslashes
// Pat Chambers (z5264081), 15/2/23

#include <stdio.h>

int main (void) {

    // We need to use a backslash to 'escape' the backslash, otherwise the 
    // compiler will think we're trying to print a special character
    printf(" /\\___/\\\n");
    printf("(=' w '=)\n"); 

    return 0;
}
