/*************************
 * Kenley Shaw           *
 * CPSC2310 PA 2         *
 * UserName: ckshaw      *
 *Lab Section: 1         *
*************************/

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(int argc, char *argv[])
{
	// checking number of arguments
	checkArg(argc);

	// opening input file
	FILE* inputPtr = fopen(argv[1], "r");
	// checking input file
	checkFile(inputPtr);
	// getting number of chars in input file
	int inputCharCount = getFileCount(inputPtr);

	// creating char array to store data of input file in
	char *charArray;
	charArray = malloc(inputCharCount * sizeof(char*));

	// reading the input file
	readFile(charArray, inputPtr, inputCharCount);

	// opening the output file
	FILE *outputPtr = fopen(argv[2], "w");
	// check output file
	checkFile(outputPtr);

	// creating function pointer that points to ascii
	void (*funcPtr)(char*, FILE*, int) = &ASCII;
	//calling print using the pointer
	print(funcPtr, charArray, outputPtr, inputCharCount);
	// setting it to binary now
	funcPtr = binary;
	// calling print using pointer again
	print(funcPtr, charArray, outputPtr, inputCharCount);

	// closing files
	fclose(inputPtr);
	fclose(outputPtr);

	// freeing memory
	free(charArray);
}
