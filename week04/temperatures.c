// Create a program that scans in temperatures for each day in a week
// Print out the largest temperature that was scanned in
// Pat Chambers (z5264081), 8/3/23
#include <stdio.h>

#define NUM_DAYS 7

int main(void) {

    // Create array
    int temperatures[NUM_DAYS];

    // Loop to scan in values
    int i = 0;
    while (i < NUM_DAYS) {
        scanf("%d", &temperatures[i]);
        i++;
    }

    // Find the maximum value
    int max = temperatures[0];
    int j = 0;
    while (j < NUM_DAYS) {
        if (temperatures[j] > max) {
            max = temperatures[j];
        }
        j++;
    }

    // Print out that maximum
    printf("%d\n", max);

    return 0;
}
