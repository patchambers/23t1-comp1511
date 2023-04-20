// Linked list revision
// Pat Chambers (z5264081), 12/4/23

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;		// data item at this node
	struct node *next;		// pointer to the next node
};

struct split_list {
    struct node *first;
    struct node *second;
};


struct node *create_node(int data);
struct node *add_last(struct node *head, int data);
void print_list(struct node *head);
struct split_list *split(struct node *head);


int main(void) {

    struct node *head = NULL;
    head = add_last(head, 10);
    head = add_last(head, 11);
    head = add_last(head, 12);
    head = add_last(head, 0);
    head = add_last(head, 13);
    head = add_last(head, 14);
    print_list(head);
    struct split_list *new_split = split(head);
    print_list(new_split->first);
    print_list(new_split->second);
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

// Given a list with at least one node, and exactly one 0,
// split the list into a list with everything before the 0,
// and a list with the 0 and everything after.
// Return a malloced split_list struct with each of these lists.
struct split_list *split(struct node *head) {
    struct split_list *new_split = malloc(sizeof(struct split_list));
    new_split->first = NULL;
    new_split->second = NULL;

    // first node is 0
    if (head->data == 0) {
        new_split->second = head;
        return new_split;
    }

    // Loop through to find 0
    struct node *prev = NULL;
    struct node *curr = head;
    while (curr->data != 0) {
        prev = curr;
        curr = curr->next;
    }

    // curr->data = 0
    new_split->first = head;
    new_split->second = curr;
    prev->next = NULL;

    return new_split;

}




