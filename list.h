#pragma once

#include <stdbool.h>

typedef struct node {
    int value;
    struct node *next;
} node_t;

typedef struct {
	int size;
    node_t *first;
} list_t;

// Creates a node
node_t* make_node(int value, node_t *next);

// Frees the node
void free_node(node_t *n);

// Creates a list
list_t* make_list(void);

// Frees the list
void free_list(list_t *l);

// Inserts an element to the front of the list
void insert_front(list_t *l, int value);

// Inserts an element to the front of the list
void insert_back(list_t *l, int value);

// Returns the list's size
// pre: l != NULL
int list_size(list_t *l);

// Prints the list
// pre: l != NULL
void print_list(list_t *l);

// Returns an element of the list based on the index
// pre: l != NULL, l is non-empty
int list_get(list_t *l, int index);

// Removes an element of the list based on the its value
// pre: l != NULL
bool list_remove(list_t *l, int value);

// Checks whether the list is in ascending order
// pre: l != NULL
bool is_list_ascending_order(list_t *l);