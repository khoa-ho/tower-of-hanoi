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

node_t* make_node(int value, node_t *next);

void free_node(node_t *n);

list_t* make_list(void);

void free_list(list_t *l);

void insert_front(list_t *l, int value);

void insert_back(list_t *l, int value);

int list_size(list_t *l);

void print_list(list_t *l);

int list_get(list_t *l, int index);

bool list_remove(list_t *l, int value);

bool is_ordered_list(list_t *l);