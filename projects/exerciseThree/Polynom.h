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

// SIZE => Max Polynom Size
#define SIZE 20

// Struct for Monom, with the below variables
typedef struct
{
	int coefficient;
	int power;
} Monom; // name

// Struct for Polynom => Multiple Monoms combined together in monoms arr
typedef struct
{
	// pointer
	Monom* monoms[SIZE];
	int numOfElements;
} Polynom; // name


// This function will take the below args and create a monom then returns it as a pointer
Monom* createMonom(int coefficient, int power);
// print the monom Example: 2x^5  
void printMonom(Monom* monom);
// add a Monom to the provided Polynom, using below args
void addMonom(Polynom* polynom, int coefficient, int power);
// print polynom Example: 2x^3 + 4x^2 + x + 5 (without space)
void printPolynom(Polynom polynom);
// Delete the provided Polynom aka, free()
void deletePolynom(Polynom polynom);