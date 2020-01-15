/*
 *File name: backtrack.c
 *Author: Carlos Carral C.
 *Last Modified: 15/01/2020 
 *Description:
    Backtracking implementation of sudoku solving algorithm.
    Takes as input a NxN short int array.
 */

#include "types.h"
#include "sudoku.h"
#include <stdio.h>
#include "display.h"
#include "constants.h"

int backtrack_solve(s_int B[N][N],missing_t* missingptr);
int backtrack_main(s_int B[N][N]);

int backtrack_main(s_int B[N][N])
{
    missing_list M=NULL ;
    missing_t* missingptr=NULL;
    int retcode=-1;
    s_int i,j;


    /*Scan missing*/
    scan_missing(B,&M);
    missingptr = M;
    i = missingptr->i;
    j = missingptr->j;

    missingptr->candidates = get_candidates(B,i,j);

    do{
        /*Iterate through candidates*/
        missingptr->current_value = pop(&(missingptr->candidates));
        B[i][j]=missingptr->current_value;

        if(DEBUG) display_array(B);

        /*Try current branch*/
        retcode = backtrack_solve(B,missingptr->next);
        if(retcode==-1) B[i][j]=0;

    }while(!stack_empty(&(missingptr->candidates)) && retcode!=0);

    return retcode;
}

int backtrack_solve(s_int B[N][N],missing_t* missingptr)
{
    s_int i,j;
    int retcode = -1;

    i = missingptr->i;
    j = missingptr->j;

    /*Get candidates*/
    missingptr->candidates = get_candidates(B,i,j);

    /*If empty, return -1*/
    if(stack_empty(&(missingptr->candidates))){
        B[i][j]=0;
        return -1;
    }

    else{
        /*Else, iterate through candidates*/
        do{
                /*Iterate through candidates*/
                missingptr->current_value = pop(&(missingptr->candidates));
                B[i][j]=missingptr->current_value;

                if(DEBUG) display_array(B);

                /*If next==NULL, we have reached the end of the missing list succesfully
                and we need not do anything else*/

                if(missingptr->next==NULL) return 0;
                else{
                    /*Try current branch*/
                    retcode = backtrack_solve(B,missingptr->next);
                    if(retcode == -1){
                        B[i][j]=0;
                    }
                }

            }while(!stack_empty(&(missingptr->candidates)) && retcode==-1);
    }

    return retcode;
}
