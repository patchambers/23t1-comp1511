#include <stdio.h>

void increment_time(int *days, int *hours, int *minutes);

int main(void) {
    int days = 3;
    int hours = 4;
    int minutes = 59;

    printf("Time before incrementing: %d days, %d hours and %d minutes\n", 
        days, hours, minutes);
    increment_time(&days, &hours, &minutes);

    printf("Current time: %d days, %d hours and %d minutes\n", days, hours, 
        minutes);

    return 0;
}

// increments the time by 1 minute
void increment_time(int *days, int *hours, int *minutes) {
    // We use the asterisk to go to the variable at the address that 'minutes' 
    // points at
    *minutes += 1;
    if (*minutes == 60) {
        *minutes = 0;
        *hours += 1;
    }

    if (*hours == 24) {
        *hours = 0;
        *days += 1;
    }
}
