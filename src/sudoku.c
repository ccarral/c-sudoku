#include "sudoku.h"
#include "types.h"
#include <stdio.h>
#include <stdlib.h>





void add_missing(missing_list *M,s_int i, s_int j);
list get_candidates_h(s_int B[9][9], s_int i,s_int j);
list get_candidates_v(s_int B[9][9], s_int i,s_int j);
list get_candidates_b(s_int B[9][9], s_int i,s_int j);

void scan_missing(s_int A[9][9],missing_list* ML)
{

    for(s_int i=8;i>=0;i--){
        for(s_int j=8;j>=0;j--){
            if(A[i][j]==0) add_missing(ML,i,j);
        }
    }
}

missing_t *init_missing(s_int i,s_int j)
{
    missing_t* new;

    new = malloc(sizeof(missing_t));

    new->i = i;
    new->j = j;

    new->next = NULL;
    new->prev = NULL;
    new->candidates = NULL;
    new->tried = NULL;

    return new;
}

void add_missing(missing_list *M,s_int i, s_int j)
{
    missing_t *aux_missing;

    if(*M==NULL) *M=init_missing(i,j);
    else{
        aux_missing = init_missing(i,j);
        aux_missing->next = *M;
        (*M)->prev = aux_missing;
        *M = aux_missing;
    }
}

stack get_candidates(s_int B[9][9],s_int i,s_int j)
{
    /*Returns the intersection of horizontal, vertical and block candidates.*/
    stack ret_stack = NULL;
    list vlist=NULL,hlist=NULL,blist=NULL;

    hlist = get_candidates_h(B,i,j);
    vlist = get_candidates_v(B,i,j);
    blist = get_candidates_b(B,i,j);

    /*TODO: There's possibly a more efficient implementation of this*/
    for(int k=1;k<=9;k++){
        if(     in_list(&hlist,k)
            &&  in_list(&vlist,k)
            &&  in_list(&blist,k)) append(&ret_stack,k);
    }

    return ret_stack;

}

list get_candidates_h(s_int B[9][9], s_int i,s_int j)
{
    list possibles=NULL;
    s_int row = i;

    for(s_int k=1;k<=9;k++){
        append(&possibles,k);
    }

    for(int col=0;col<9;col++){
        if(in_list(&possibles,B[row][col]) && col!=j) remove_val(&possibles,B[row][col]);
    }

    return possibles;
}

list get_candidates_v(s_int B[9][9], s_int i,s_int j)
{
    list possibles=NULL;
    s_int col = j;

    for(s_int k=1;k<=9;k++){
        append(&possibles,k);
    }

    for(int row=0;row<9;row++){
        if(in_list(&possibles,B[row][col]) && row!=i) remove_val(&possibles,B[row][col]);
    }

    return possibles;
}

list get_candidates_b(s_int B[9][9], s_int i,s_int j)
{
    list possibles = NULL;
    int eqi,eqj;
    int spi,spj;
    eqi = i%3;
    eqj = j%3;

    spi = i-eqi;
    spj = j-eqj;

    for(s_int k=1;k<=9;k++){
        append(&possibles,k);
    }

    for(int row=spi;row<(spi+3);row++){
        for(int col=spj;col<(spj+3);col++){
            if(in_list(&possibles,B[row][col]) && row!=i && col!=j)
                remove_val(&possibles,B[row][col]);
        }
    }

    return possibles;

}

void debug_missing_list(missing_list *L)
{
    missing_t *aux_node_ptr;

    if(*L==NULL){
        printf("\n    ML-> NULL \n");
    }else{
        printf("\n    ML-> ");
        aux_node_ptr = *L;
        while(aux_node_ptr!=NULL){
            /*printf("\n        (%p)       ",aux_node_ptr);*/
            printf("\n(%hd,%hd)-> ",aux_node_ptr->i,aux_node_ptr->j);
            aux_node_ptr = aux_node_ptr->next;
        }
        printf("NULL\n");
    }
}
