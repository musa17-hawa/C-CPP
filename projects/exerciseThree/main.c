// 206598146
#include <stdio.h>
#include "Polynom.h"

int main(int argc, char const *argv[])
{
	Polynom polynom;
	Polynom polynom1;
	
	polynom.numOfElements = 0; // Initialize the number of elements

	addMonom(&polynom, 3, 4);
	addMonom(&polynom, -1, 2);
	addMonom(&polynom, 4, 2);
	addMonom(&polynom, 5, 4);
	addMonom(&polynom, 4, -1);
	addMonom(&polynom, -2, 0);
	
	printMonom(polynom.monoms[0]);
	printf("\n");
	printPolynom(polynom); // Print the polynom

	polynom1.numOfElements = 0;

	addMonom(&polynom1, 4, 2); // 3x^4
	addMonom(&polynom1, 3, 3);
	addMonom(&polynom1, 2, 2); // 4x^3
	addMonom(&polynom1, -2, 3); // Add 5x^2, update existing monom to 8x^2
	printPolynom(polynom1); // Print the polynom1

	deletePolynom(polynom); // Clean up
	deletePolynom(polynom1); // Clean up
	return 0;
}