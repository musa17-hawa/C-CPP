// 206598146
#include <stdio.h>
#include "Polynom.h"

int main(int argc, char const *argv[])
{
	Polynom polynom;
	Polynom polynom1;
	
	polynom.numOfElements = 0; // Initialize the number of elements
	printf("address of polynom is  %p\n", &polynom);

	addMonom(&polynom, 3, 4); // 3x^4
	addMonom(&polynom, 1, 4);
	addMonom(&polynom, 4, 3); // 4x^3
	addMonom(&polynom, 5, 2); // Add 5x^2, update existing monom to 8x^2
	printPolynom(polynom); // Print the polynom

	polynom1.numOfElements = 0;
	printf("address of polynom1 is  %p\n", &polynom1);

	addMonom(&polynom1, 4, 5); // 3x^4
	addMonom(&polynom1, 3, 4);
	addMonom(&polynom1, 2, 3); // 4x^3
	addMonom(&polynom1, 2, 2); // Add 5x^2, update existing monom to 8x^2
	printPolynom(polynom1); // Print the polynom1

	deletePolynom(polynom); // Clean up
	deletePolynom(polynom1); // Clean up
	return 0;
}