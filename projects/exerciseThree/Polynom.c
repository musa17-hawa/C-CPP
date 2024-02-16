// 206598146 
#include "Polynom.h"

#include <stdio.h>
#include <stdlib.h>

Monom* createMonom(int coefficient, int power){
	Monom* myMonom = (Monom*)malloc(sizeof(Monom));
	if(coefficient == 0) return NULL;
	myMonom -> coefficient = Coefficient;
	myMonom -> power = Power;
	return myMonom;

}
void printMonom(Monom* monom){
	printf("printMonom\n");
}
void addMonom(Polynom* polynom, int coefficient, int power){
	if (!polynom || (coefficient == 0 || polynom -> numOfElements == SIZE)){
		return;
	}
	else{
		int currentElemNum = polynom -> numOfElements;
		if(!currentElemNum){
			currentElemNum = 0;
		}
		polynom -> monoms[currentElemNum] = createMonom(coefficient, power);
		++polynom -> numOfElements;
	}
}
void printPolynom(Polynom polynom){
	printf("printPolynom on %p\n", &polynom.monoms);
	int numberOfElements = polynom.numOfElements;
	for(int i = 0; i < numberOfElements; i++){
		Monom *currentMonom = polynom.monoms[i];
		int currentCoefficient = currentMonom -> coefficient;
		int currentPower = currentMonom -> power;
		printf("%dx^%d\t", currentCoefficient, currentPower);
	}
	printf("\n");

}
void deletePolynom(Polynom polynom){
	printf("deletePolynom\n");
}