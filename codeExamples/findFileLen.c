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
* 05/03/2024		Musa Abu Alhawa		Commit ID "a8d8fbc".
*
/******************************************************************/

#include <stdlib.h>
#include <stdio.h>


int main(int argc, char const *argv[])
{
	FILE* fp;
	fp = fopen("filename.txt", "r"); // Open the file 
	fseek(fp, 0L, SEEK_END); // Find the end 
	int file_len = ftell(fp); // Get the length 
	printf("%d\n", file_len);

	int * A = (int*)malloc(file_len*sizeof(int));

	rewind(fp);
    int num;
    fscanf(fp, "%d", &num);
    char ch = getc(fp);
    int counter = 0;
    while(ch != EOF){
        printf("%d",num);
        *(A+counter) = num;
        fscanf(fp, "%d", &num);
        counter++;
        ch = getc(fp);
    }
    printf("\n");
    for(int i = 0; i < counter; i++){
    	printf("\t%d\n", *(A+i));

    }
    if(feof(fp)){
        printf("End of File Reached.\n");
    }else{
        printf("Something went wrong.\n");
    }
	return 0;
}
