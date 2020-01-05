
load_from_file(const char* filename,int* B)
{
    f = fopen(filename,"r");
    string current_line;
    bool invalid_file_flag=False;

    Mientras(!EOF(f) || invalid_file_flag){
        current_line = readline(f);
        current_line_len = len(current_line);
        int current_int_len=0;
        string current_digit;
        Para(i=0;i<current_line_len;i++){
            Si(isdigit(current_line[i]){
                current_int_len++;

            }
            Si(current_int_len=1){
                current_digit = atoi(current_line[i]); 
            }Otro{
               invalid_file_flag=True;
               break;
            }

        }
    }

}
