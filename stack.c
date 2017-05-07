#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "stack.h"


stack_t* make_stack(void) {
    return make_list();
}

void free_stack(stack_t *st) {
    free_list(st);
}

int stack_size(stack_t *st) {
    return list_size(st);
}

void stack_print(stack_t *st) {
    print_list(st);
}

void stack_push(stack_t *st, int v) {
    insert_front(st, v);
}

int stack_pop(stack_t *st) {
    assert(stack_size(st) > 0);
    int ret = list_get(st, 0);
    list_remove(st, ret);
    return ret;
}

int stack_peek(stack_t *st) {
    assert(stack_size(st) > 0);
    return list_get(st, 0);
}

bool is_stack_ascending_order(stack_t *st) {
    return is_list_ascending_order(st);
}