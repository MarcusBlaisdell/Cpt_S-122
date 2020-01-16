/*********************************************************************************
* Programmer: Marcus Blaisdell                                                   *
* Student ID: 097868639                                                          *
* Class: CptS 122, Spring 2015; Lab Section x                                    *
* Programming Assignment: PA1                                                    *
* Date: 01/26/2015                                                               *
* Description: This program performs the following:                              *
* Sorts strings into ascending or descending order as determined by the user     *
* using an array of strings without using strcpy, manipulating the pointers only *
*                                                                                *
**********************************************************************************/

#include "Blaisdell_PA1.c"

int main (void)
{
	char list[10][6] = {"one", "two", "three", "four", "five", "six",
		"seven", "eight", "nine", "ten"};
	int n = 10;

	// printStrings (list, n);
	sortAscending (list, n);
	// printStrings (list, n);

	return 0;
}
