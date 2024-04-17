#ifndef __TYPES_H_
#define __TYPES_H_

typedef short int s_int;
typedef struct node
{
    s_int value;
    struct node* next;
} node_t;

typedef node_t* stack;
typedef stack list;

s_int pop(stack *S);

void push(stack* S, s_int value);

node_t *new_node(s_int val);

void debug_node(node_t *node);

void debug_stack(stack *S);

void debug_list(list *L);

int stack_empty(stack* S);

int list_len(list* L);

int in_list(list *L,s_int value);

void append(list *L,s_int value);

int remove_val(list *L,s_int value);


#endif


