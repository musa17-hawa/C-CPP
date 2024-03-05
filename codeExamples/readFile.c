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


int main(int argc, char const *argv[])
{
	char buff[100];
    // file pointer
    FILE* fptr;
 
    // creating file using fopen() access mode "w"
    fptr = fopen("filename.txt", "r");
 
    // checking if the file is created
    if (fptr == NULL) {
        printf("The file was not found. The program will "
               "make a new one named filename.txt\n creating file ...\n");
        fptr = fopen("filename.txt", "w");
        fptr = fopen("filename.txt", "r");
        if (fptr == NULL) {
        	printf("The file is not opened. Could not make a new one, \tExiting ...\n");
        	exit(0);
        }
        else{
        	printf("The file is created Successfully.\n");
        }
    }else{
    	int ch = getc(fptr);
    	printf("File Opened\nReading File ...\n\n");
    	while (ch != EOF){
    		putchar(ch);
    		ch = getc(fptr);
    	}

    	// Check if the end-of-file indicator is
	    // set for the file
	    if (feof(fptr))
	        printf("\nEnd of file reached.");
	    else
	        printf("\n Something went wrong.");
	 
	    // Close the file
	    fclose(fptr);
    	getchar();
    }

	return 0;
}
