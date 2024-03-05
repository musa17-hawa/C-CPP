// 206598146

/*******************************************************************
* Copyright         : 2024 Musa Abu Alhawa
* File Name         : Ex4.c
* Description       : 
*                    
* Revision History :
* 
* Date              Author          Comments
* ---------------------------------------------------------------------------
* 05/03/2024        Musa Abu Alhawa     Created.
* 05/03/2024        Musa Abu Alhawa     Commit ID "a8d8fbc".
*
/******************************************************************/


#include <stdio.h>
#include <stdlib.h>

struct Data {
    int num_of_lines;
    int ** the_data; 
    int * lines_len;
};

// this is for dynamic string length, expands allocated string len value
char *inputString(FILE* fp, size_t size){
//The size is extended by the input with the value of the provisional
    char *str;
    int ch;
    size_t len = 0;
    str = realloc(NULL, sizeof(*str)*size);//size is start size
    if(!str)return str;
    while(EOF!=(ch=fgetc(fp)) && ch != '\n'){
        str[len++]=ch;
        if(len==size){
            str = realloc(str, sizeof(*str)*(size+=16));
            if(!str)return str;
        }
    }
    int i=0;
    int result = 0;
    while(str[i]!='\0') {
        result +=str[i];
        i++;
    }
    printf("%d", result);
    str[len++]='\0';
    return realloc(str, sizeof(*str)*len);
}


int get_num_of_lines(FILE* fp){
    rewind(fp);
    int num;
    fscanf(fp, "%d", &num);
    return num;
}

void get_lines_len(FILE* fp, int *ptr){
    rewind(fp);
    int local_num_of_lines = get_num_of_lines(fp);
    
    printf("\n%d is the local numOfLines\n\n", local_num_of_lines);
    int num;
    char ch = getc(fp);
    int counter = 0;
    while(ch != EOF){
        if (ch == '\n'){
            counter++;
            if (counter > local_num_of_lines) break;
            fscanf(fp, "%d", &num);
            printf("%d\n", num);
            printf("pointer value is%d\n", *ptr);
            ch = getc(fp);
            
        }
        else{
            ch = getc(fp);
            continue;
        }
    }
}

int main(int argc, char const *argv[])
{
    struct Data myData; 
    // file pointer
    FILE* fp;
    // creating file using fopen() access mode "w"
    fp = fopen("filename.txt", "r");
    inputString(fp, 10);
    // checking if file was loaded
    if(fp == NULL){
        printf("File does not exist\texiting ...\n");
        exit(0);
    }
    else{
        printf("file opened.\n");

        int my_num_of_lines = get_num_of_lines(fp);
        printf("Num of elem using function is: %d\n", my_num_of_lines);
        myData.num_of_lines = my_num_of_lines;

        myData.lines_len = (int*)malloc(myData.num_of_lines*sizeof(int));
        get_lines_len(fp, myData.lines_len);
        printf("output is: %d\n", *myData.lines_len);
        // int num;
        // fscanf(fp, "%d", &num);
        // char ch = getc(fp);
        // int counter = 0;
        // while(ch != EOF){
        //     myData.num_of_lines = counter == 0 ? num : myData.num_of_lines;
        //     printf("%d\n",num);
        //     fscanf(fp, "%d", &num);
        //     counter++;
        //     ch = getc(fp);
        // }
        // if(feof(fp)){
        //     printf("End of File Reached.\n");
        // }else{
        //     printf("Something went wrong.\n");
        // }
        fclose(fp);
        printf("file closed.\n");
    }
    free(myData.lines_len);
	return 0;
}
