#include "Blaisdell_PA1.h"

/*******************************************************************
* Programmer: Marcus Blaisdell                                     *
* Student ID: 097868639                                            *
* Class: CptS 122, Spring 2015; Lab Section x                      *
* Programming Assignment:                                          *
* Date: 01/26/2015                                                 *
* Function: sortAscending                                          *
* Description: This function sorts the records in ascending order  *
* Precondition: Ascending order must be selected as the sort order *
* Postcondition: Records will be sorted in ascending order         *
********************************************************************/
void sortAscending (char list[][6], int n)
{
	char *pointerArray[10], *temp[6] = {""};
	int count = 0, endIndex = n - 1, passes = 0, printCount = 0;

	for (count = 0; count < n; count++)
	{
		pointerArray[count] = list[count];
	} // end for loop to load pointer array addresses into the array of pointers
	count = 0; // reset count

	
	// print before
	for (printCount = 0; printCount < n; printCount++)
	{
		printf ("before: %s\n", pointerArray[printCount]);
	}
	printCount = 0;
	

	for (passes = 0; passes < endIndex; passes++)
	{
		count = 0;
		for (count = 0; count < endIndex - passes; count++)
		{
		if (strcmp(pointerArray[count], pointerArray[count + 1]) == 1)
		{
			*temp = pointerArray[count];
			pointerArray[count] = pointerArray[count + 1];
			pointerArray[count + 1] = *temp;
		} // end if value to the right is lower than value on left
		} // end inner loop
	} // end outer loop
	
	printCount = 0;
	printf ("Test\n");
	// print after
	for (printCount = 0; printCount < n; printCount++)
	{
		printf ("After: %s\n", pointerArray[printCount]);
	}
	
}

/*******************************************************************
* Programmer: Marcus Blaisdell                                     *
* Student ID: 097868639                                            *
* Class: CptS 122, Spring 2015; Lab Section x                      *
* Programming Assignment:                                          *
* Date: 01/26/2015                                                 *
* Function: printStrings                                           *
* Description: This function prints the records in the array       *
* Precondition:  *
* Postcondition:  *
********************************************************************/
void printStrings (char list[][6], int n)
{
	int count = 0;

	for (count = 0; count < n; count++)
	{
		printf ("%s\n", list[count]);
	}
}