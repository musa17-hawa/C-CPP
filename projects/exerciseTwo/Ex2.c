// 206598146
// Musa Abu Alhawa
// 12-02-2024


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TERMS 20
#define MAX_STR 200

int checkIfLetter(char c){
	if(((c <= 122) && (c >= 97)) || ((c <= 90) && (c >= 65))){return 1;}else{return 0;}
}

char myEncode(char c, int offset){
	if(checkIfLetter(c) == 1){
		int tmp;
		c = toupper(c);
		tmp = c;
		if (tmp + offset > 90){
			tmp = tmp - 26;
		}
		return tolower(tmp + offset);
	}else{
		return tolower(c);
	}
}

void encode(char str[], char key[], char e[], char* terms[]){
	int keyLen = strlen(key);
	int strLen = strlen(str);
	int tmp[keyLen];
	int termsIndex = 1;
	if (checkIfLetter(str[0]) == 1){terms[0] = &e[0];}else{termsIndex = 0;}

	for(int i = 0; i < keyLen; i++){
		tmp[i] = (toupper(key[i]) - 65);
	}

	int k = 0;
	for(int j = 0; j < strLen; j++){
		if (k == keyLen){
			k = 0;
		}
		char result = myEncode(str[j], tmp[k]);
		if (j > 1 && e[j-1] == ' '){
			terms[termsIndex] = &(e[j]);
			termsIndex++;
		}
		if (checkIfLetter(str[j]) == 1){
			e[j] = result;
			k++;
		}
		else{
			e[j] = result;
		}
	}
	for (int i = termsIndex; i < MAX_TERMS; i++){terms[i] = NULL;}
}

void getIthElement(char e[], char* terms[], int i, char out[]){
	int counter = 0;
	int tmp = 0;
	if (terms[i] == NULL){
		strcpy(out, "");
	}else{
		while (terms[counter]){
			counter++;
		}
		while(*(&(*terms[i])+tmp) != ' ' && *(&(*terms[i])+tmp) != '\0'){
			out[tmp] = *(&(*terms[i])+tmp);
			tmp++;
		}
	}


	printf("word at %d is :%s\n", i, out);
}

int main(int argc, char const *argv[])

{
	char str[] = "we love c course";
	char key[] = "atlm";
	char e[MAX_STR];
	char myE[] = "lwx wavx n ooncee";
	char out[MAX_STR];
	char* terms[MAX_TERMS];

	encode(str, key, e, terms);

	printf("Original is: %s\n", str);
	printf("Key is: %s\n", key);
	printf("Encoded is: %s\n", e);
	printf("pointers values are: %p, %p, %p, %p\n", &(*terms[0]), &(*terms[1]), &(*terms[2]), &(*terms[3]));
	getIthElement(myE, terms, 3, out);
	// printf("starts at: %p, Encoded is: %p\n",);
	return 0;
}



