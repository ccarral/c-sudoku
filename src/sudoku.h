#include "types.h"


#define BOARD_DIMMENSIONS 9

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

stack get_candidates(s_int B[9][9], missing_t* missingptr);

stack get_candidates_h(s_int B[9][9], missing_t* missingptr);

stack get_candidates_v(s_int B[9][9], missing_t* missingptr);

stack get_candidates_b(s_int B[9][9], missing_t* missingptr);

void scan_missing(s_int B[9][9],missing_list* ML);

void debug_missing_list(missing_list *L);

#endif
