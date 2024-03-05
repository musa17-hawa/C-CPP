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
        int num;
        fscanf(fp, "%d", &num);
        char ch = getc(fp);
        int counter = 0;
        while(ch != EOF){
            myData.num_of_lines = counter == 0 ? num : myData.num_of_lines;
            printf("%d\n",num);
            fscanf(fp, "%d", &num);
            counter++;
            ch = getc(fp);
        }
        if(feof(fp)){
            printf("End of File Reached.\n");
        }else{
            printf("Something went wrong.\n");
        }
        fclose(fp);
    }
    printf("num_of_lines is: \t%d\n",myData.num_of_lines);
	return 0;
}
