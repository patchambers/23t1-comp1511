// Various linked list exercises
// Pat Chambers (z5264081), 12/4/23

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;		// data item at this node
	struct node *next;		// pointer to the next node
};


struct node *add_last(struct node *head, int data);
void print_list(struct node *head);
struct node *copy(struct node *head);
void free_list(struct node *head);
struct node *list_append(struct node *first_list, struct node *second_list);
int identical(struct node *first_list, struct node *second_list);


int main(void) {

    // Test copy
    struct node *head = NULL;
    head = add_last(head, 10);
    head = add_last(head, 11);
    head = add_last(head, 12);

    struct node *copied = copy(head);

    printf("COPYING LIST\n");
    printf("------------------------------------------------------------\n");
    printf("Original list:         ");
    print_list(head);
    printf("Copy of original list: ");
    print_list(copied);
    printf("Changing the first node of copy to 42 ...\n");
    copied->data = 42;
    printf("After changing the copy, original list should be unchanged:\n");
    printf("Original list:         ");
    print_list(head);
    printf("Copy of original list: ");
    print_list(copied);

    // Test free_list
    free_list(head);
    free_list(copied);

    return 0;
}


// Print the linked list pointed to by `head` in the format:
// 1 -> 2 -> 3 -> X
void print_list(struct node *head) {
    struct node *curr = head;
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("X\n");
}

// Creates a new node with the given data and adds this node to the end of the 
// list pointed to by `head`
struct node *add_last(struct node *head, int data) {
    struct node *new = malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;

    // Return new if linked list is initially empty
    if (head == NULL) {
        return new;
    }

    // Otherwise, loop to end of list and add node.
    struct node *curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = new;

    // We are inserting at the end --> head will not change
    return head;
}

// Create a copy of the linked list pointed to by `list` and return a pointer 
// to the head of the copy
struct node *copy(struct node *list) {
    // Initialise new_head to NULL. If list is empty, the while loop doesn't run
    // so NULL is returned
    struct node *new_head = NULL;
    struct node *curr = list;
    while (curr != NULL) {
        // Use the add last function to make a node with the current node's data 
        // and add it to the end of the new list
        new_head = add_last(new_head, curr->data);
        curr = curr->next;
    }
    return new_head;
}

// Frees all the memory allocated for the linked list pointed to by `head`
void free_list(struct node *head) {
    struct node *prev = NULL;
    struct node *curr = head;
    while (curr != NULL) {
        prev = curr;
        curr = curr->next;
        free(prev);
    }
}

// Create a new list that consists of the second list appended to the first 
// Returns a pointer to the head of this appended list
struct node *list_append(struct node *first_list, struct node *second_list) {
    return NULL;
}

// Returns 1 if the first list and second list are identical, 
// otherwise returns 0
int identical(struct node *first_list, struct node *second_list) {
    return 5841;
}

