#include "../src/loader.h"
#include "../src/types.h"
#include "../src/display.h"
#include "../src/sudoku.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init_dummy_board(short int B[9][9]);
void test_msg(const char* msg);
void display_array(short int B[9][9]);
short int generate_random_number();

const char* TEST_FILE = "tests/test_file.txt";

int main(void)
{
    int return_code=0;
    s_int test_array[9][9];
    stack test_stack=NULL;
    list test_list=NULL;
    stack candidates=NULL;
    missing_t* missing_test=NULL;
    missing_list missing_l = NULL;

    srand(time(0));

    test_msg("Running tests...");

    /*Read from file*/
    loader_test_fn();
    return_code = read_from_file(TEST_FILE,test_array);
    assert(return_code==0);

    test_msg("Display board loaded from file");
    display_array(test_array);

   test_msg("Stack tests");

    test_msg("Stack creation");

    push(&test_stack,1);
    assert(test_stack!=NULL);
    assert(test_stack->value==1);
    debug_list(&test_stack);
    push(&test_stack,2);
    push(&test_stack,3);
    push(&test_stack,4);
    debug_list(&test_stack);

    /*test_msg("Testing push");*/
    /*push(&test_stack,2);*/
    /*assert(test_stack->value==2);*/

    /*push(&test_stack,3);*/
    /*push(&test_stack,4);*/
    /*push(&test_stack,5);*/

    /*test_msg("Testing pop");*/
    /*assert(pop(&test_stack)==5);*/
    /*assert(test_stack->value==4);*/
    /*assert(pop(&test_stack)==4);*/
    /*assert(test_stack->value==3);*/
    /*assert(pop(&test_stack)==3);*/
    /*assert(test_stack->value==2);*/

    /*test_msg("Testing stack_empty");*/
    /*assert(!stack_empty(&test_stack));*/
    /*pop(&test_stack); [>2<]*/
    /*pop(&test_stack); [>1<]*/
    /*assert(stack_empty(&test_stack));*/

    /*assert(pop(&test_stack)==-1);*/
    /*assert(stack_empty(&test_stack));*/
    /*assert(pop(&test_stack)==-1);*/

    /*test_msg("Testing list operations");*/
    /*test_msg("Testing append");*/
    /*append(&test_list,1);*/
    /*append(&test_list,2);*/
    /*append(&test_list,3);*/
    /*append(&test_list,4);*/
    /*append(&test_list,5);*/
    /*append(&test_list,6);*/
    /*append(&test_list,7);*/
    /*append(&test_list,8);*/
    /*append(&test_list,9);*/
    /*debug_list(&test_list);*/

    /*test_msg("Testing in_list");*/
    /*assert(in_list(&test_list,1));*/
    /*assert(in_list(&test_list,2));*/
    /*assert(in_list(&test_list,3));*/
    /*assert(in_list(&test_list,4));*/
    /*assert(in_list(&test_list,5));*/
    /*assert(in_list(&test_list,6));*/
    /*assert(in_list(&test_list,7));*/
    /*assert(in_list(&test_list,8));*/
    /*assert(in_list(&test_list,9));*/
    /*assert(in_list(&test_list,50)==0);*/
    /*assert(in_list(&test_list,23)==0);*/
    /*assert(in_list(&test_list,27)==0);*/

    /*test_msg("Testing remove_val");*/
    /*assert(remove_val(&test_list,23)==-1);*/
    /*test_msg("Removing (6)");*/
    /*assert(remove_val(&test_list,6)==0);*/
    /*assert(!in_list(&test_list,6));*/
    /*debug_list(&test_list);*/
    /*assert(in_list(&test_list,7));*/
    /*test_msg("Removing (9)");*/
    /*assert(remove_val(&test_list,9)==0);*/
    /*debug_list(&test_list);*/
    /*test_msg("Removing (1)");*/
    /*assert(remove_val(&test_list,1)==0);*/
    /*debug_list(&test_list);*/

    /*test_msg("Testing get_candidates");*/
    /*missing_test = init_missing(0,1);*/
    /*assert(missing_test->i==0);*/
    /*assert(missing_test->j==1);*/
    /*test_msg("Testing get_candidates_h");*/
    /*candidates = get_candidates_h(test_array,missing_test);*/
    /*debug_list(&candidates);*/
    /*test_msg("Testing get_candidates_v");*/
    /*candidates = get_candidates_v(test_array,missing_test);*/
    /*debug_list(&candidates);*/
    /*test_msg("Testing get_candidates_b");*/
    /*candidates = get_candidates_b(test_array,missing_test);*/
    /*debug_list(&candidates);*/
    /*test_msg("Testing get_candidates");*/
    /*candidates = get_candidates(test_array,missing_test);*/
    /*debug_list(&candidates);*/

    test_msg("Testing scan_missing");
    scan_missing(test_array,&missing_l);
    debug_missing_list(&missing_l);
    

    return return_code;
}

void init_dummy_board(short int B[9][9])
{
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            B[i][j]= generate_random_number();
        }
    }

}

short int generate_random_number()
{
    short int random;
    random = rand()%9;

    return random;
}

void test_msg(const char*  msg)
{
    printf("\n  ->  %s\n",msg);
}
