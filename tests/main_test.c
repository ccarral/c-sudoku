#include "../src/loader.h"
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

/*Move to display.c*/
void display_board(short int B[9][9])
{
    printf("\n");
    for(int i=0;i<9;i++){
        if(i==0 || i%3==0) printf("______________________________\n");

        for(int j=0;j<9;j++){

            if(j==0 || j%3==0) printf("|");

            printf(" %d ",B[i][j]);


        }
        printf("\n");
    }
    printf("\n");
    
}
