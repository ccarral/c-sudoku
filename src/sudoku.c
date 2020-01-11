#include "sudoku.h"
#include "types.h"
#include <stdio.h>
#include <stdlib.h>





void add_missing(missing_list *M,s_int i, s_int j);
list get_candidates_h(s_int B[9][9], missing_t* missingptr);
list get_candidates_v(s_int B[9][9], missing_t* missingptr);
list get_candidates_b(s_int B[9][9], missing_t* missingptr);

missing_list scan_missing(s_int A[9][9])
{
    missing_list M;

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(A[i][j]==0){
                add_missing(&M,i,j);

            }
        }
    }
    return M;
}

missing_t* init_missing(s_int i,s_int j)
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

    if((*M)==NULL) *M=init_missing(i,j);
    else{
        aux_missing = init_missing(i,j);
        aux_missing->next = *M;
        *M = aux_missing;
    }
}

stack get_candidates(s_int B[9][9], missing_t* missingptr)
{
    /*Returns the intersection of horizontal, vertical and block candidates.*/
    stack ret_stack = NULL;
    list vlist=NULL,hlist=NULL,blist=NULL;

    hlist = get_candidates_h(B,missingptr);
    vlist = get_candidates_v(B,missingptr);
    blist = get_candidates_b(B,missingptr);

    /*TODO: There's possibly a more efficient implementation of this*/
    for(int i=1;i<=9;i++){
        if(     in_list(&hlist,i)
            &&  in_list(&vlist,i)
            &&  in_list(&blist,i)) append(&ret_stack,i);
    }

    return ret_stack;

}

list get_candidates_h(s_int B[9][9], missing_t* missingptr)
{
    list possibles=NULL;
    s_int row = missingptr->i;

    for(s_int i=1;i<=9;i++){
        append(&possibles,i);
    }

    for(int j=0;j<9;j++){
        if(in_list(&possibles,B[row][j])) remove_val(&possibles,B[row][j]);
    }

    return possibles;
}

list get_candidates_v(s_int B[9][9], missing_t* missingptr)
{
    list possibles=NULL;
    s_int col = missingptr->j;

    for(s_int i=1;i<=9;i++){
        append(&possibles,i);
    }

    for(int i=0;i<9;i++){
        if(in_list(&possibles,B[i][col])) remove_val(&possibles,B[i][col]);
    }

    return possibles;
}

list get_candidates_b(s_int B[9][9], missing_t* missingptr)
{
    list possibles = NULL;
    int eqi,eqj;
    int spi,spj;
    eqi = missingptr->i%3;
    eqj = missingptr->j%3;

    spi = missingptr->i-eqi;
    spj = missingptr->j-eqj;

    for(s_int i=1;i<=9;i++){
        append(&possibles,i);
    }

    for(int i=spi;i<(spi+3);i++){
        for(int j=spj;j<(spj+3);j++){
            if(in_list(&possibles,B[i][j])) remove_val(&possibles,B[i][j]);
        }
    }

    return possibles;

}
