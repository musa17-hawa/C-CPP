// 206598146 
#include "Polynom.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertionSort(Monom* monoms[], int n);
Monom* createMonom(int coefficient, int power){
	Monom* myMonom = (Monom*)malloc(sizeof(Monom));
	if(coefficient == 0) return NULL;
	myMonom -> coefficient = coefficient;
	myMonom -> power = power;
	return myMonom;

}
void printMonom(Monom* monom){
	if (monom != NULL){
		int currentCoefficient = monom -> coefficient;
		int currentPower = monom -> power;

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

		}
	}
}
void addMonom(Polynom* polynom, int coefficient, int power){
	if (polynom && (coefficient != 0 && polynom -> numOfElements != SIZE)){
		int currentElemNum = polynom -> numOfElements;
		if(!currentElemNum){
			currentElemNum = 0;
		}
		int found = 0;
		for(int i = 0; i < currentElemNum; i++){
			if(power == polynom -> monoms[i] -> power){
				polynom -> monoms[i] -> coefficient += coefficient;
				found = 1;
				break;
			}
		}
		if (found == 0){
			polynom -> monoms[currentElemNum] = createMonom(coefficient, power);
			++polynom -> numOfElements;
		}
	}
}
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
void deletePolynom(Polynom polynom){
	for(int i=0; i < polynom.numOfElements; i++){
		free(polynom.monoms[i]);
	}
}

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