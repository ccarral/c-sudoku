#include "types.h"
#include "constants.h"



#ifndef __SUDOKU_H_
#define __SUDOKU_H_

typedef struct missing{
    s_int i;
    s_int j;
    s_int current_value;
    stack candidates;
    stack tried;
    struct missing *next;
    struct missing *prev;
}missing_t;

typedef missing_t* missing_list;

missing_t* init_missing(s_int i,s_int j);

/**
 * Returns the intersection of horizontal, vertical and block candidates.
 */
stack get_candidates(s_int B[N][N],s_int i,s_int j);

/**
 * Returns a list of horizontal candidates
 */
stack get_candidates_h(s_int B[N][N],s_int i,s_int j);

/**
 * Returns a list of vertical candidates
 */
stack get_candidates_v(s_int B[N][N],s_int i,s_int j);

/**
 * Returns a list of block candidates
 */
stack get_candidates_b(s_int B[N][N],s_int i,s_int j);

/**
 * Fills a list of the missing values in a board
 */
void scan_missing(s_int B[N][N], missing_list* ML);

void debug_missing_list(missing_list *L);

#endif
