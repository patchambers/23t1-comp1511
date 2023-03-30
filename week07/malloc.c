#include <stdio.h>
#include <stdlib.h>

struct pet {
    int age;
    int weight;
    char name[100];
};

int main(void) {

    // int i;
    int *i = malloc(sizeof(int));
    // double d;
    double *d = malloc(sizeof(double));
    // int array1[10];
    int *array1 = malloc(10 * sizeof(int));
    // char array2[4];
    char *array2 = malloc(4 * sizeof(char));
    // struct pet coco;
    struct pet *coco = malloc(sizeof(struct pet));
    // struct pet class_pets[5];
    struct pet *class_pets = malloc(5 * sizeof(struct pet));

}
