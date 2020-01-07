#include "../src/loader.h"
#include "../src/types.h"
#include "../src/display.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init_dummy_board(short int B[9][9]);
void test_msg(const char* msg);
void display_board(short int B[9][9]);
short int generate_random_number();

const char* TEST_FILE = "tests/test_file.txt";

int main(void)
{
    int return_code=0;
    short int test_board[9][9];
    stack test_stack;
    list test_list=NULL;

    srand(time(0));

    test_msg("Running tests...");

    /*Fill dummy board*/
    init_dummy_board(test_board);

    /*Display Filled Dummy Board*/
    test_msg("Display Test");
    display_board(test_board);

    /*Read from file*/
    loader_test_fn();
    return_code = read_from_file(TEST_FILE,test_board);
    assert(return_code==0);

    test_msg("Display board loaded from file");
    display_board(test_board);

    test_msg("Stack tests");

    test_msg("Stack creation");

    test_stack = new_node(1);
    assert(test_stack!=NULL);
    assert(test_stack->value==1);

    test_msg("Testing push");
    push(&test_stack,2);
    assert(test_stack->value==2);

    push(&test_stack,3);
    push(&test_stack,4);
    push(&test_stack,5);

    test_msg("Testing pop");
    assert(pop(&test_stack)==5);
    assert(test_stack->value==4);
    assert(pop(&test_stack)==4);
    assert(test_stack->value==3);
    assert(pop(&test_stack)==3);
    assert(test_stack->value==2);

    test_msg("Testing stack_empty");
    assert(!stack_empty(&test_stack));
    pop(&test_stack); /*2*/
    pop(&test_stack); /*1*/
    assert(stack_empty(&test_stack));

    assert(pop(&test_stack)==-1);
    assert(stack_empty(&test_stack));
    assert(pop(&test_stack)==-1);

    test_msg("Testing list operations");
    test_msg("Testing append");
    append(&test_list,10);
    debug_list(&test_list);
    append(&test_list,20);
    append(&test_list,30);
    append(&test_list,40);
    debug_list(&test_list);

    test_msg("Testing in_list and append");
    assert(in_list(&test_list,10));
    assert(in_list(&test_list,20));
    assert(in_list(&test_list,40));
    assert(in_list(&test_list,50)==0);
    assert(in_list(&test_list,23)==0);
    assert(in_list(&test_list,27)==0);

    test_msg("Testing remove_val");
    assert(remove_val(&test_list,23)==-1);
    test_msg("Removing (40)");
    assert(remove_val(&test_list,40)==0);
    debug_list(&test_list);
    test_msg("Removing (20)");
    assert(remove_val(&test_list,20)==0);
    debug_list(&test_list);
    test_msg("Removing (10)");
    assert(remove_val(&test_list,10)==0);
    debug_list(&test_list);


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
