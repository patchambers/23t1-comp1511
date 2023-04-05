// Basic linked lists and functions
// Pat Chambers (z5264081), 5/4/23

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *create_node(int data);
struct node *add_last(struct node *head, int data);
struct node *insert_node(struct node *head, int data, int n);
void print_list(struct node *head);

int main(void) {

    // Creates a linked list and inserts a node into the middle of it
    struct node *list = create_node(10);
    list = add_last(list, 30);
    list = add_last(list, 40);
    list = insert_node(list, 20, 1);
    print_list(list);

    return 0;
}


// Allocates memory for and initialises a new struct node
// Args:
//      data    data to initialise the new node with
// Returns: pointer to the new node
struct node *create_node(int data) {
    // malloc this memory so it isn't deleted when the function ends
    struct node *new = malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;
    return new;
}

// Adds a node to the end of a linked list. If the list is empty, the new node 
// is returned as the head of the list
// Args:
//      head    pointer to the start of the linked list
//      data    data to initialise the new node with
// Returns:     head of the new linked list
struct node *add_last(struct node *head, int data) {
    struct node *new_node = create_node(data);
    struct node *curr = head;
    // If curr is NULL, it means the list is empty, so we can return the new 
    // node as the new head of the list
    if (curr == NULL) {
        return new_node;
    }
    // Loop until curr is pointing at the last node in the list (which is the 
    // node with a next pointer pointing to NULL
    while (curr->next != NULL) {
        curr = curr->next;
    }
    // Make the last node's next pointer point at the new node
    curr->next = new_node;
    return head;
}

// Insert a new node into a linked list after the nth node. If n is larger than 
// the length of the linked list, adds this new node at the end of the list.
// Args:
//      head    pointer to the start of the linked list
//      data    data to initialise the new node with
//      n       position to insert the node at (0 will insert it at the start of 
//              the list, 1 will insert it after the first node, etc)
// Returns:     head of the new list (this will be different if the new node was 
//              inserted at the start of the list)
struct node *insert_node(struct node *head, int data, int n) {
    struct node *new_node = create_node(data);
    // If list is empty, return new_node as the head of the list
    if (head == NULL) {
        return new_node;
    }

    struct node *curr = head;

    // If n is 0, we need to make new_node point at the head and then 
    // return new_node as the head of the list
    if (n == 0) {
        new_node->next = head;
        return new_node;
    }

    // Loop until we reach the nth node in the list (or the end of the list)
    int i = 1; 
    while (i < n && curr->next != NULL) {
        curr = curr->next;
        i++;
    }
    // Set new_node->next to point at the (n+1)th node and get the nth node's 
    // next to point at the new_node
    new_node->next = curr->next;
    curr->next = new_node;

    return head; 
}

// Prints a linked list in a nice format
// Args:
//      head    pointer to the start of the linked list
void print_list(struct node *head) {
    struct node *curr = head;
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("X\n");
}
