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
	int **twoDArray;
	printf("%p\t\t\n", twoDArray);
	int a[] = {1,2,3};
	int b[] = {2,3,4};
	int c[] = {3,4,5};
	int *myArr[] = {a, b, c};
	twoDArray = myArr;

	printf("%p\t\t\n", twoDArray);
	printf("%p\t\t\n", myArr);

	printf("a: \t\t%p\n", a);
	printf("b: \t\t%p\n", b);
	printf("c: \t\t%p\n", c);
	printf("%p\t\t\n", twoDArray);

	printf("twoDArray[0]: \t%p\n", twoDArray[0]);
	printf("twoDArray[1]: \t%p\n", twoDArray[1]);
	printf("twoDArray[2]: \t%p\n", twoDArray[2]);

	return 0;
}