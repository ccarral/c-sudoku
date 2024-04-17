#include <stdio.h>
#include <assert.h>
#include <string.h>

int read_line_from_file(FILE *fp,short int L[9])
{
    for(int i=0;i<9;i++){
        fscanf(fp,"%hd,",&L[i]);
    }
    return 0;
}

int read_from_file(const char* filename,short int B[9][9])
{
    FILE *fp=NULL;
    int return_code=0;

    /*Open file in read mode */
    fp = fopen(filename,"r");
    assert(fp!=NULL);

    /*Iterate through file*/
    for(int i=0;i<9 && return_code==0;i++){
        return_code = read_line_from_file(fp,B[i]);
    }
    return return_code;
}
