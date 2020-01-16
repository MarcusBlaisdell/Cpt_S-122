#ifndef BLAISDELL_PA1_1_H
#define BLAISDELL_PA1_1_H

#define _CRT_SECURE_NO_WARNINGS

// include libraries
#include <stdio.h>
#include <string.h>

// function prototypes:
// sort the array according to the users selection
void sort (char *list[], char *pointerArray[], int n, int sortOrder);
// print the strings in the order set in the pointer array
void printStrings (char *pointerArray[], int n);
// get the sortOrder
int getSortOrder (int sortOrder);
// assign array elements to pointer array elements
void assignArrayPointerElements (char *list[], char *pointerArray[], int n);

// test / driver functions
void driverTestSort(char *list[], char *pointerArray[], int n, int sortOrder);

#endif