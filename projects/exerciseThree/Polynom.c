// 206598146

/*******************************************************************
* Copyright         : 2024 Musa Abu Alhawa
* File Name         : Polynom.c
* Description       : This file makes use of Polynom.h in which has the structs Monom and Polynom,
* 					  including all the necessary functions that must be used here in this file. 
*                    
* Revision History  :
* Date				Author    		Comments
* ---------------------------------------------------------------------------
* 20/02/2024		Musa Abu Alhawa		Created.
* 27/02/2024		Musa Abu Alhawa		Submitted.
*
/******************************************************************/


// Our costum header file
#include "Polynom.h"

// standard imports
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// insertionSort will be specified later
void insertionSort(Monom* monoms[], int n);

// Takes both args and created a monom with those args, returns Pointer to the created monom
Monom* createMonom(int coefficient, int power){
	// Allocating Memorry and creating a pointer
	Monom* myMonom = (Monom*)malloc(sizeof(Monom));
	// Edge case => Null
	if(coefficient == 0) return NULL;
	// else, creating a monom struct with args
	myMonom -> coefficient = coefficient;
	myMonom -> power = power;
	// returning the pointer created above
	return myMonom;

}

// see example in [Polynom.h]
// monom is a pointer, Thus we use [->] to access its variables
void printMonom(Monom* monom){
	// if Null do NOT do anything,
	// if NOT Null
	if (monom != NULL){
		// creating my own variables, for each monom struct variable using -> to access each.
		int currentCoefficient = monom -> coefficient;
		int currentPower = monom -> power;

		// sorting all the power rules for printing
		if(currentPower > 1){
			if(currentCoefficient == 1){
				printf("x^%d", currentPower);
			}else if(currentCoefficient == -1){
				printf("-x^%d", currentPower);
			}else{
				printf("%dx^%d", currentCoefficient, currentPower);
			}

		}else if(currentPower == 1){
			if(currentCoefficient == 1){
				printf("x");
			}else if(currentCoefficient == -1){
				printf("-x");
			}else{
				printf("%dx", currentCoefficient);
			}
		}else if(currentPower == 0){
			printf("%d", currentCoefficient);

		}else{
			printf("%dx^%d", currentCoefficient, currentPower);

		}// end of sorting the power rules
	}// else (monom is NULL) => Do not do anything
}

// Described in the header file.
void addMonom(Polynom* polynom, int coefficient, int power){
	// Sorting out the edge cases (if(polynom) means polynom is not NULLL)
	if (polynom && (coefficient != 0 && polynom -> numOfElements != SIZE)){
		// creating currentElemNum in order to add 1 to it later
		int currentElemNum = polynom -> numOfElements;
		// since we are adding, if currentElemNum is NULL, we make it zero (in case this happens)
		if(!currentElemNum){
			currentElemNum = 0;
		}

		// found flag set to zero
		int found = 0;
		// Looping through the arr, in case we find the same power as the one we are trying to add to the polynom
		// we of course, add both coefficient together without adding 1 to the numOfElem 
		for(int i = 0; i < currentElemNum; i++){
			if(power == polynom -> monoms[i] -> power){ // found same power
				polynom -> monoms[i] -> coefficient += coefficient;
				found = 1; // found flag is one
				break; // breaking out of the loop
			}
		}
		if (found == 0){ // did not find same power - found flag is Zero, add the monom, and add 1 to numOfElem
			polynom -> monoms[currentElemNum] = createMonom(coefficient, power);
			++polynom -> numOfElements;
		}
	}
}// end of addMonom

//  Print Polynom:
//		Sort the Polynoms in a descending order, Largest => Smallest
//		Loop through each Monom in the provided polynom
//			Not the first ? Coefficient is positive ?, not the last ? => print "+"
//			skip if otherwise
// 			Print Monom using printMonom Fucntion
//			got back to loop and repeat
//	Print a new Line
void printPolynom(Polynom polynom){
	int numberOfElements = polynom.numOfElements;
	insertionSort(polynom.monoms, numberOfElements);
	for(int i = 0; i < numberOfElements; i++){
		Monom *currentMonom = polynom.monoms[i];
		int currentCoefficient = currentMonom -> coefficient;
		int currentPower = currentMonom -> power;
		if(i > 0 && (currentCoefficient > 0 && i != numberOfElements)){
			printf("+");
		}
		printMonom(currentMonom);
	}
	printf("\n");

}
// freeing the allocated memory for each Monom, in the polynom arr provided.
void deletePolynom(Polynom polynom){
	for(int i=0; i < polynom.numOfElements; i++){
		free(polynom.monoms[i]);
	}
}

// Implemnting an insertion Sort for an Array of monoms pointers - 
// accroding to their power variable, in a decending order. (5, 4, 3, 2, 1)
void insertionSort(Monom* monoms[], int n)
{
	Monom* keyP;
    int i, j;
    for (i = 1; i < n; i++) 
    {
        keyP = monoms[i];
        j = i - 1;
 
        /* Move elements of arr[0..i-1], 
           that are greater than key, 
           to one position ahead of 
           their current position */
        while (j >= 0 && monoms[j] -> power < keyP -> power) 
        {
            monoms[j + 1] = monoms[j];
            j = j - 1;
        }
        monoms[j + 1]= keyP;
    }
}