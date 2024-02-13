// 206598146
// Musa Abu Alhawa
// 12-02-2024

// All relevant Lib's
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Global static variables init
#define MAX_TERMS 20
#define MAX_STR 200

// Checks if the provided Char is a letter by checking its ascii values
int checkIfLetter(char c){
	if(((c <= 122) && (c >= 97)) || ((c <= 90) && (c >= 65))){return 1;}else{return 0;}
}

// if it is a letter, it returns the char with the offset of the co-responding key char
// else returns the same inputed letter
char myEncode(char c, int offset){
	if(checkIfLetter(c) == 1){
		int tmp; // making my own tmp for c
		c = toupper(c); // converting c to its upper state
		tmp = c;
		// if the letter+offset is bigger than 90 which means that
		// it is no longer a letter,
		if (tmp + offset > 90){
			// I substract 26 so that it goes back to the letter ascii values
			tmp = tmp - 26;
		}
		// returns lower case char + its shift from the key provided
		return tolower(tmp + offset);
	}else{
		// not a letter ? return the char provided
		return tolower(c);
	}
}

// encode function takes
//(string to encode, the key to use, e is the encoded output, *terms is a pointer array to each encoded word)
void encode(char str[], char key[], char e[], char* terms[]){
	// setting up arr length and tmp(containes offset numbers co-responding to each key value)
	// exmpl: key = "atlm", tmp = {0, 19, 11, 12}
	int keyLen = strlen(key);
	int strLen = strlen(str);
	int tmp[keyLen];
	int termsIndex = 1;
	// if the first char in str is space, we re-set termsIndex to be zero
	// if the first char in str is a char, we set up terms first value to be the first char in str.
	if (checkIfLetter(str[0]) == 1){terms[0] = &e[0];}else{termsIndex = 0;}

	// setting up tmp to contain keys offset value
	for(int i = 0; i < keyLen; i++){
		tmp[i] = (toupper(key[i]) - 65);
	}


	int k = 0;
	// loop through all str chars
	for(int j = 0; j < strLen; j++){
		// k is tmp index, if we got to len of key, we reset it back to zero
		if (k == keyLen){
			k = 0;
		}
		// encoding each char
		char result = myEncode(str[j], tmp[k]);
		// check if letter, if it is we add it to e and inc k(key index)
		if (checkIfLetter(str[j]) == 1){
			e[j] = result;
			k++;
		}
		// else (not letter) we add it to e only without incrementing k(key index)
		else{
			e[j] = result;
		}
		// word pointers are located as follows:
		// if the previous char is space, and the current one is not space, we add its pointer to terms arr.
		// if not, we do not add it.
		if ((j > 1 && e[j-1] == ' ' && e[j] !=' ')){
			terms[termsIndex] = &(e[j]);
			termsIndex++;
		}

	}
	// filling up the rest of terms in NULL values
	for (int i = termsIndex; i < MAX_TERMS; i++){terms[i] = NULL;}
}


void getIthElement(char e[], char* terms[], int i, char out[]){
	int tmp = 0;
	// if i is bigger than the terms len, meaning we found NULL, we return empty string.
	if (terms[i] == NULL){
		strcpy(out, "");
	// other wise, we loop through until we hit a space or the end of the string
	// and then we add each char found to out.
	// please note that here we check the char found in the address saved in terms.
	}else{
		while(*(&(*terms[i])+tmp) != ' ' && *(&(*terms[i])+tmp) != '\0'){
			out[tmp] = *(&(*terms[i])+tmp);
			tmp++;
		}
		// clearing out the rest of the out arr. 
		for(int j = tmp; j < strlen(out); j++){
			out[j] = 0;
		}
	}
}



