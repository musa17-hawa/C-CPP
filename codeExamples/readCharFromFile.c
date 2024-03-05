// 206598146

/*******************************************************************
* Copyright         : 2024 Musa Abu Alhawa
* File Name         : Ex4.c
* Description       : 
*                    
* Revision History :
* 
* Date				Author    		Comments
* ---------------------------------------------------------------------------
* 05/03/2024		Musa Abu Alhawa		Created.
* 
*
/******************************************************************/


#include <stdio.h>
#include <stdlib.h>

struct Data {
    int num_of_lines;
    int ** the_data; 
    int * lines_len;
};

int main(int argc, char const *argv[])
{
    struct Data myData; 
    // file pointer
    FILE* fp;
 
    // creating file using fopen() access mode "w"
    fp = fopen("filename.txt", "r");
    // checking if file was loaded
    if(fp == NULL){
        printf("File does not exist\texiting ...\n");
        exit(0);
    }
    else{
        printf("file loaded.\n");
        int ch = getc(fp);
        int counter = 0;
        while(ch != EOF){
            printf("%d:", ++counter);
            if(ch == ' '){
                printf("SPACE\n");
                ch = getc(fp);
                continue;
            }else if(ch == '\n'){
                printf("NEW LINE\n");
                ch = getc(fp);
                continue;
            }else{
                putchar(ch);
                printf("\n");
                ch = getc(fp);
            }
        }
        if(feof(fp)){
            printf("End of File Reached.");
        }else{
            printf("Something went wrong.");
        }
        fclose(fp);
    }
    // Press any key to exit ...
    getchar();
	return 0;
}
