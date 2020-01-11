/*
 *File name: backtrack.c
 *Author: Carlos Carral C.
 *Last Modified: 10/01/20 09:21:18
 *Description:
    Backtracking implementation of sudoku solving algorithm.
    Takes as input a 9x9 int array.
 */

#include "types.h"
#include "sudoku.h"
#include <stdio.h>

int backtrack_main_algorithm(s_int B[9][9], missing_list* M)
{
    missing_t* current_missing = *M;
    s_int backtrack_retcode=0;

    while(current_missing->next!=NULL){
        /*Get candidates for current_missing*/
    }

}
