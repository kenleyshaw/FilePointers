/*************************
 * Kenley Shaw           *
 * CPSC2310 PA 2         *
 * UserName: ckshaw      *
 *Lab Section: 1         *
*************************/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/*
 * parameters: int- the number of arguments
 * return: void
 * this function checks if there is a valid number of arguments
 */
void checkArg(int);

/*
 * parameters: file- the file being pointed to
 * return: void
 * this function checks if the file is opened
 */
void checkFile(FILE*);

/*
 * parameters: file- the file being pointed to
 * return: int- number of characters
 * this function gets the number of characters in the file
 */
int getFileCount(FILE*);

/*
 * parameters: file- the file being pointed to
 * return: void
 * this function sets the pointer to the beginning of the file
 */
void retFP(FILE* fp);

/*
 * parameters: char- the array that contains the data in the file,
 * 				file- the file being pointed to,
 * 				int- the number of characters
 * return: void
 * this function reads the file char by char
 */
void readFile(char*, FILE*, int);

/*
 * parameters: char- the array that contains the data in the file,
 * 				file- the file being pointed to,
 * 				int- the number of characters
 * return: void
 * this function converts the char array to ascii values
 */
void ASCII(char*, FILE*, int);

/*
 * parameters: char- the array that contains the data in the file,
 * 				file- the file being pointed to,
 * 				int- the number of characters
 * return: void
 * this function converts the char array to binary values
 */
void binary(char*, FILE*, int);

/*
 * parameters: char- the array that contains the data in the file,
 * 				file- the file being pointed to,
 * 				int- the number of characters
 * return: void
 * this function prints the ascii and binary values in a format to the output file
 */
void print(void (*fp)(char*, FILE*, int), char*, FILE*, int);

#endif
