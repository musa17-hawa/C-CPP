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
	int *array;
	int *arrayPointer;
	int A[] = {1,2,3,4,5};
	arrayPointer = A;
	//printf("%p\t, %d\n", array, *(array+1));	
	printf("A (actual array) adress is:\t\t\t%p\n", A);
	printf("array adress is:\t\t\t\t%p\n", array);
	printf("arrayPointer (same as A) adress is:\t\t%p\n", arrayPointer);

	return 0;
}