#pragma once

#include <stdbool.h>
#include "list.h"

/**
 * A basic stack implementation utilizing a list.
 * The type of the stack is `stack_t` since stack_t conflicts with
 * a pre-existing type on certain OS X setups.
 */

typedef list_t stack_t;

// Creates a stack
stack_t* make_stack(void);

// Frees a stack
void free_stack(stack_t *st);

// Returns the stack's size
// pre: st != NULL
int stack_size(stack_t *st);

// Prints the stack
// pre: st != NULL
void stack_print(stack_t *st);

// Pushes an element onto the stack
// pre: st != NULL
void stack_push(stack_t *st, int v);

// Pops an element off the stack
// pre: st != NULL, st is non-empty
int stack_pop(stack_t *st);

// Returns the top of the stack without popping it
// pre: st != NULL, st is non-empty
int stack_peek(stack_t *st);

bool is_ordered_stack(stack_t *st);