/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA1 part 1
* Date: 01/28/2015
* Description: This program performs the following:
* Sorts strings into ascending or descending order as determined by the user
* using an array of strings without using strcpy, manipulating the pointers only
*
**********************************************************************************/

#include "Blaisdell_PA1_1.c"

int main (void)
{
	// variable declarations, instructions say to use "n" so ...
	char *list[10] = {"one", "two", "three", "four", "five", "six", 
		"seven", "eight", "nine", "ten"}, *pointerArray[10];
	// char *list[10], *pointerArray[10];
	int n = 10, count = 0, sortOrder = 0;

	// let the user decide what order to sort the strings in, ascending or descending
	sortOrder = getSortOrder (sortOrder);

	// assign pointer elements to array elements
	assignArrayPointerElements (list, pointerArray, n);

	// run test driver
	driverTestSort (list, pointerArray, n, sortOrder);

	return 0;
}
