#include "types.h"
#include <stdio.h>
#include <stdlib.h>

s_int pop(stack *S);

void push(stack *S, s_int value);

node_t *new_node(s_int val);

void debug_node(node_t *node);

void debug_msg(const char* msg);

int stack_empty(stack *S);

void append(list *L,s_int value);

int remove_val(list *L,s_int value);

s_int pop(stack *S)
{
    s_int ret_val;
    node_t *aux_node = NULL;

    /*Empty Stack*/
    if(*S==NULL) return -1;
    else{
        ret_val=(*S)->value;
        aux_node = *S;
        *S = (*S)->next;
        free(aux_node);

        return ret_val;
    }
    
}

void push(stack* S,s_int value)
{
    node_t *aux_node;

    if(*S==NULL) *S=new_node(value);
    else{
        aux_node = new_node(value);
        aux_node->next = *S;
        *S = aux_node;
    }
}

int stack_empty(stack *S)
{
    if(*S==NULL) return 1;
    else return 0;
}


int in_list(list *L,s_int value)
{

    node_t *aux_node;
    int ret_val=0;

    if(stack_empty(L)) return 0;
    else
    {
        aux_node = *L;

        while(aux_node!=NULL)
        {
            if(aux_node->value == value){
                ret_val = 1;
                break;
            } 
            else{
                aux_node = aux_node->next;
            }

        }

    }

    return ret_val;
}

void append(list *L, s_int value)
{
    push(L,value);
}

int remove_val(list *L, s_int value)
{
    node_t *current_node_ptr=NULL;
    node_t *aux_next=NULL;
    node_t *last_ptr=NULL;

    if(!in_list(L,value)) return -1;
    else{
        current_node_ptr = *L;
        if(current_node_ptr->value==value){
            *L = current_node_ptr->next;
            free(current_node_ptr);
        }else{
            aux_next = current_node_ptr->next;
            while(current_node_ptr->value!=value){
                last_ptr = current_node_ptr;
                current_node_ptr = current_node_ptr->next;
            }
            *last_ptr = *(current_node_ptr->next);
            free(current_node_ptr);
        }
    }
    return 0;
}

node_t *new_node(s_int val)
{
    node_t* new;

    new = malloc(sizeof(node_t));
    new->next = NULL;
    new->value = val;

    return new;
}

void debug_node(node_t *node)
{
    if(node==NULL) printf("Null ptr");
    else{
        printf("\nNode value: %hd\n",node->value);
        if(node->next!=NULL) printf("Previous: %hd\n", node->next->value);
        else printf("Previous: NULL\n");
    }
}

void debug_list(list *L){

    node_t *aux_node_ptr;

    if(*L==NULL){
        printf("\n    L-> NULL \n");
    }else{
        printf("\n    L-> ");
        aux_node_ptr = *L;
        while(aux_node_ptr!=NULL){
            printf("%hd -> ",aux_node_ptr->value);
            aux_node_ptr = aux_node_ptr->next;
        }
        printf("NULL\n");
    }
}

void debug_msg(const char* msg){
    printf("\nDEBUG: %s\n",msg);
}
