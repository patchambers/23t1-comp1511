// Program to demonstrate use of enums
// Patrick Chambers (z5264081), 23/9/22

#include <stdio.h>

// Defining the values that an 'enum opal_card_type' can take
enum opal_card_type {
    adult, 
    student, 
    concession
};

// We can include an enum in a struct just like any other kind of variable
struct person {
    int shoe_size;
    double height;
    char first_name_initial;
    enum opal_card_type card_type;
};


int main(void) {

    // The variable type here is 'enum opal_card_type' and the variable name 
    // is 'sashas_card'
    enum opal_card_type sashas_card = adult;
    if (sashas_card == adult) {
        printf("Sasha has to pay the full train fare\n");
    }

    // Declaring and initialising a struct person with enum opal_card_type
    struct person shrey;
    shrey.shoe_size = 44;
    shrey.height = 1.85;
    shrey.first_name_initial = 'S';
    shrey.card_type = student;

    if (shrey.card_type == student) {
        printf(
            "Shrey's going to have an adult opal card now that he's finally "
            "going to graduate!\n"
        );
        shrey.card_type = adult;
    }

    return 0;
}
