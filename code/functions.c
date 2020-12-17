/*************************
 * Kenley Shaw           *
 * CPSC2310 PA 2         *
 * UserName: ckshaw      *
 *Lab Section: 1         *
*************************/

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void checkArg(int numArgs) {
	// if number of args is not 3 then error is printed
	if (numArgs != 3) {
		fprintf(stderr, "%s", "Not enough command line arguments! \n");
		return;
	}
}

void checkFile(FILE* ptr) {
	ptr = fopen("input.txt", "r");
	// if pointer is null then error is printed
	if (ptr == NULL) {
		fprintf(stderr, "fopen() failed in file %s at line # %d, of function %s \n", __FILE__, __LINE__, __FUNCTION__);
	}
}

int getFileCount(FILE* file) {
	// gets each char from file
	char c = getc(file);
	int charCount = 0;
	// while char is not equal to the end of file, add to count
	while (c != EOF) {
		charCount++;
		c = getc(file);
	}
	// call return function pointer function
	retFP(file);
	return charCount;
}

void retFP(FILE* fp) {
	// getting pointer position before fseek is called
	long int pos = ftell(fp) - 1;
	fprintf(stderr, "Pointer position before fseek() is called: %ld \n", pos);
	// if setting pointer to the front of the file is not successful, error is printed
	if (fseek(fp, 0, SEEK_SET) != 0) {
		fprintf(stderr, "fseek() failed. \n");
	}
	else {
		// sets pointer to front and gets position
		fseek(fp, 0, SEEK_SET);
		long int pos = ftell(fp);
		fprintf(stderr, "Pointer position after fseek() is called: %ld \n", pos);
	}
}

void readFile(char* arr, FILE* ptr, int size) {
	// sets pointer to front
	fseek(ptr, 0, SEEK_SET);
	// reads the size of the data
	int count = fread(arr, sizeof(char), size, ptr);
	// if size is not equal to the original char count, error is printed
	if (count != size) {
		fprintf(stderr, "%s", "fread() failed \n");
		return;
	}
	else {
		// call return pointer function
		retFP(ptr);
	}
}

void ASCII(char* arr, FILE* ptr, int count) {
	// creates array to store values
	int ascii[count];
	// loops through count of characters
	for (int i = 0; i < count; i++) {
		// assigns int value from char array to ascii array
		ascii[i] = (int)arr[i];
	}
	int line = 1;
	fprintf(ptr, "ASCII: \n");
	for (int i = 0; i < count; i++) {
		// prints the line
		fprintf(ptr, "\n%d: ", line);
		// loops through the possible values
		for (int j = 0; j < 9; j++) {
			if (ascii[i] != 0) {
				fprintf(ptr, "%d", ascii[i]);
				i++;
			}
		}
		// loops through each line
		line++;
	}
}

void binary(char* arr, FILE* ptr, int count) {
	int line = 0;
	fprintf(ptr, "\n Binary: \n");
	// loops through count of characters
	for (int i = 0; i < count; i++) {
		fprintf(ptr, "%d: ", line);
		// loops through 8 bits
			for (int j = 7; j >= 0; j--) {
				// bit shifts however many positions the bit is
				int mask = arr[i] >> j;
				// assigns to 1
				if (mask & j) {
					fprintf(ptr, "1 ");
				}
				// assigns to 0
				else {
					fprintf(ptr, "0 ");
				}
			}
		fprintf(ptr, "\n");
		// loops through each line
		line++;
	}
	fprintf(ptr, "\n\n");
}

void print(void (*fp)(char*, FILE*, int), char* c, FILE* ptr, int count) {
	fp(c, ptr, count);
}
