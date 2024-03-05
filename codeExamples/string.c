// Created 9 years ago by jonathanyip on github

#include <stdio.h>
#include <stdlib.h>

char *getWord(FILE *fin) {
	// Static string (char *) and size, so we can allocate more space later if needed.
	// When you're done, you MUST free this pointer.
	static char *string = NULL;
	static int size = 10;
	
	// Temporary variables
	// ptr = used for realloc
	// pos = used to hold position in string
	// c   = used to hold character at current position
	char *ptr;
	int pos;
	char c;

	// If we called this function and the string is not init yet,
	// allocate some space for it
	if(string == NULL) {
		string = (char *) malloc(sizeof(char) * size);

		if(string == NULL) {
			fprintf(stderr, "Error! Malloc failed to allocate memory!");
			exit(1);
		}
	}

	// Reset position to zero
	pos = 0;

	// While we can get chars that are not EOF
	while((c = fgetc(fin)) != EOF) {

		// If our position is (size - 1), to take in account null byte
		// Reallocate 2x the space in the heap
		if(pos == (size - 1)) {
			ptr = (char *) realloc(string, sizeof(char) * size * 2);
			
			if(ptr == NULL) {
				fprintf(stderr, "Error! Realloc failed to allocated memory!");
				exit(1);
			}

			string = ptr;
			size *= 2;
		}

		// If is alpha, add to the string
		if(isalpha(c)) {
			string[pos++] = c;
		
		// If it is not alpha, and we haven't read anything
		// we can just continue to look for a word
		} else if(pos == 0) {
			continue;
		
		// Else, break out and return the string
		} else {
			break;
		}
	}

	// If we got an EOF and we haven't read anything yet,
	// return NULL.
	// (It is possible to get an EOF and have read something,
	// if this happens, we still need to return the string)
	if(c == EOF && pos == 0) return NULL;

	// Terminate the string
	string[pos] = '\0';

	// Return the string
	return string;
}

int main() {
	char *string = NULL;

	while((string = getWord(stdin)) != NULL) {
		printf(">> %s\n\n", string);
	}
	
	return 0;
}
