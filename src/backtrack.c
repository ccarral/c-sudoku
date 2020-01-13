/*
 *File name: backtrack.c
 *Author: Carlos Carral C.
 *Last Modified: 10/01/20 09:21:18
 *Description:
    Backtracking implementation of sudoku solving algorithm.
    Takes as input a 9x9 short int array.
 */

#include "types.h"
#include "sudoku.h"
#include <stdio.h>

int backtrack(s_int B[9][9], missing_t* missingptr);
int backtrack_main_algorithm(s_int B[9][9], missing_list* M);

int backtrack_main_algorithm(s_int B[9][9], missing_list* M)
{
    missing_t* current_missing = *M;
    s_int backtrack_retcode=0;
    s_int i,j;

    /*
     *This loops the missing list until the last missing node has
     *succesfully been assigned a valid value.
     */
    while(current_missing->next!=NULL){

        /*Get candidates for current_missing*/

        /*TODO Maybe just store the return value of get_candidates 
         * directly in current_missing?*/
        while(
            (current_missing->candidates = get_candidates(B,current_missing))
            ==NULL
            ){
            backtrack_retcode = backtrack(B,current_missing->prev);
            /*
             * If all previous backtracking recursive calls 
             * were unsuccesful,then a solution couldn't be reached.
             * Then backtrack_retcode should equal -1
             */
            if(backtrack_retcode!=0) return backtrack_retcode;
        }

        /*Get an untried candidate from candidates list*/
        current_missing->current_value = pop(&(current_missing->candidates));
        i = current_missing->i;
        j = current_missing->j;
        B[i][j]=current_missing->current_value;

        /*Add selected candidate to tried list*/
        push(&(current_missing->tried),current_missing->current_value);

        /*Move forward*/
        current_missing = current_missing->next;
    }

    return 0;

}

int backtrack(s_int B[9][9], missing_t* missingptr)
{

    s_int i=-1,j=-1;

    i = missingptr->i;
    j = missingptr->j;

    /*
     *If missingptr->candidates is empty, then the candidates for
     *the current node have already been exhausted and
     *we need to backtrack further.
     */
    if(stack_empty(&(missingptr->candidates))){

        /*
         *If missingptr->prev == NULL, then the beginning of the 
         *list has been reached and we cannot backtrack any further.
         * A valid combination of values could not be figured out 
         * and the function returns an error code
         */
        if(missingptr->prev == NULL) return -1;

        /*
         *Otherwise, make recursive call to try another candidate
         *and try to return to main function
         */
        else (backtrack(B,missingptr->prev));

        /* TODO Memory leak right here
         * Should be calling a destructor */

        /*After backtracking, recalculate available candidates*/
        missingptr->candidates = get_candidates(B,missingptr);

        /* TODO Memory leak right here
         * Should be calling a destructor */
        
        /*Reset tried list*/
        missingptr->tried = NULL;

        /*TODO: Pop a candidate , put in board and push it to the tried list*/
        missingptr->current_value = pop(&(missingptr->candidates));
        push(&(missingptr->tried),missingptr->current_value);

        B[i][j]=missingptr->current_value;


    }else{

        /*Push current value to already tried stack, try with next*/
        /*CHANGELOG Changed places next two lines, as a value already in tried stack was being doubly pushed*/
        missingptr->current_value = pop(&(missingptr->candidates));
        push(&(missingptr->tried),missingptr->current_value);

        /*Change actual value in board*/
        B[i][j]=missingptr->current_value;
        
    }


    return 0;
}
