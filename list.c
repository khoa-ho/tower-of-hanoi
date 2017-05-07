#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "list.h"


node_t* make_node(int value, node_t *next) {
    node_t *ret = (node_t*) malloc(sizeof(node_t));
    ret->value = value;
    ret->next  = next;
    return ret;
}

void free_node(node_t *n) {
    free(n);
}

list_t* make_list(void) {
    list_t *ret = (list_t*) malloc(sizeof(list_t));
    ret->first = NULL;
    ret->size = 0;
    return ret;
}

void free_list(list_t *l) {
    node_t *cur = l->first;
    while (cur != NULL) {
        node_t *t = cur->next;
        free_node(cur);
        cur = t;
    }
    free(l);
}

void insert_front(list_t *l, int value) {
    l->first = make_node(value, l->first);
    l->size += 1;
}

void insert_back(list_t *l, int value) {
    if (l->first == NULL) {
        insert_front(l, value);
    } else {
        node_t *cur = l->first;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = make_node(value, NULL);
    }
    l->size += 1;
}

int list_size(list_t *l) {
    return l->size;
}

void print_list(list_t *l) {
    printf("[");
    if (l->first != NULL) {
        printf("%d", l->first->value);
        node_t *cur = l->first->next;
        while (cur != NULL) {
            printf(", %d", cur->value);
            cur = cur->next;
        }
    }
    printf("]\n");
}

int list_get(list_t *l, int index) {
    assert((list_size(l) > index) & (index >= 0));
    node_t *cur = l->first;
    for (int i = 0; i < index; i++) {
        cur = cur->next;
    }
    return cur->value;
}

bool list_remove(list_t *l, int value) {
    node_t *cur = l->first;
    if (cur == NULL) { return false; }
    else if (cur->value == value) {
        node_t *to_del = cur;
        l->first = cur->next;
        l->size -= 1;
        free_node(to_del);
        return true;
    } else {
        while (cur->next != NULL) {
            if (cur->next->value == value) {
                node_t *to_del = cur->next;
                cur->next = cur->next->next;
                l->size -= 1;
                free_node(to_del);
                return true;
            }
            cur = cur->next;
        }
        return false;
    }
}

bool is_list_ascending_order(list_t *l) {
    node_t *cur = l->first;
    if (cur == NULL) { return true; }
    while (cur->next != NULL) {
        if (cur->value > cur->next->value) {
            return false;
        }
        cur = cur->next;
    }
    return true;
}
