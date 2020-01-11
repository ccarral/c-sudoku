#include <stdio.h>
#include "types.h"

void display_array(s_int B[9][9])
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
