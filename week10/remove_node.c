// Linked list revision
// Pat Chambers (z5264081), 12/4/23

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;		// data item at this node
	struct node *next;		// pointer to the next node
};


struct node *create_node(int data);
struct node *add_last(struct node *head, int data);
void print_list(struct node *head);
struct node *remove_node(struct node *head, int value);


int main(void) {

    struct node *head = NULL;
    head = add_last(head, 10);
    head = add_last(head, 11);
    head = add_last(head, 12);
    print_list(head);
    head = remove_node(head, 12);
    print_list(head);
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

// Create node with the given data and returns a pointer to it
struct node *create_node(int data) {
    struct node *new = malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;
    return new;
}

// Creates a new node with the given data and adds this node to the end of the 
// list pointed to by `head`
struct node *add_last(struct node *head, int data) {
    struct node *new = create_node(data);
    if (head == NULL) {
        return new;
    }

    struct node *curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = new;

    return head;
}

// Delete node with specified value from the list pointed at by `head`
// Frees memory for this node
struct node *remove_node(struct node *head, int value) {

    // Empty list
    if (head == NULL) {
        return NULL;
    }

    // Removing at head of list
    if (head->data == value) {
        struct node *new_head = head->next;
        free(head);
        return new_head;
    }
    
    // General case
    struct node *prev = NULL;
    struct node *curr = head;
    while (curr != NULL && curr->data != value) {
        prev = curr;
        curr = curr->next;
    }
    // If we didn't find correct value
    if (curr == NULL) {
        printf("ERROR :(\n");
        return head;
    }
    prev->next = curr->next;
    free(curr);
    return head;
}











