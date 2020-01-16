#include "Blaisdell_PA1_1.h"

/*******************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA1, part 1
* Date: 01/28/2015
* Function: sort
* Description: This function sorts the records in order selected
*				by the user
* Precondition: Order must be selected
* Postcondition: Records will be sorted in chosen order
********************************************************************/
void sort (char *list[], char *pointerArray[], int n, int sortOrder)
{
	// variable declarations
	char *temp[] = {""};
	int index = 0, Unsorted = n - 1, Count = 0; // instructions say to use U and C, I opted for Unsorted and Count, easier to follow
	
	// bubble sort

	for (Count = 0; Count < Unsorted; Count++)
	{
		// index = 0; 
		for (index = 0; index < Unsorted - Count; index++)
		{
		// if sortOrder is 1, sorts ascending, if -1, sorts descending
		if (strcmp(pointerArray[index], pointerArray[index + 1]) == sortOrder) 
		{
			// swap current index position with last unsorted position
			*temp = pointerArray[index];
			pointerArray[index] = pointerArray[index + 1];
			pointerArray[index + 1] = *temp;
		} // end if value to the right is lower than value on left
		} // end inner loop
	} // end outer loop, end bubble sort
}

/*******************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA 1, part 1
* Date: 01/28/2015
* Function: getSortOrder
* Description: This function prompts the user to enter the order
*				in which to sort the strings, ascending or 
*				descending
* Precondition: sortOrder integer must be declared
* Postcondition: The value to use as the sort order will be 
*				returned to the calling function to be passed to 
*				the sorting function
********************************************************************/
int getSortOrder (int sortOrder)
{
	// prompt user to determine sort order
	printf ("Sort Order:\n");
	printf ("Type 1 for Ascending, 2 for Descending :> ");
	// error checking, only 1 or 2 is acceptable
	while ((sortOrder != 1) && (sortOrder != 2))
	{
		scanf ("%d", &sortOrder);
	}
	// if 2 is selected, set to -1 to let strcmp evaluate as descending (if it's 1, it's ascending)
	if (sortOrder == 2)
	{
		sortOrder = -1; 
	}

	// return the correct sortOrder to the function that called this function
	return sortOrder;
} // end getSortOrder function

void assignArrayPointerElements (char *list[], char *pointerArray[], int n)
{
	int count = 0;

	// assign array element addresses to pointerArray elements
	for (count = 0; count < n; count++)
	{
		*(pointerArray + count) = *(list + count);
	} // end for loop to load pointer array addresses into the array of pointers
} // end assignArrayPointerElements function

/*******************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA 1, part 1
* Date: 01/28/2015
* Function: printStrings
* Description: This function prints the records in the array
* Precondition: pointerArray must be loaded with addresses from
*				list
* Postcondition: the values pointerArray points to will be printed
*				to the screen in the order they have been placed
*				into pointerArray
********************************************************************/
void printStrings (char *pointerArray[], int n)
{
	// variable declaration
	int index = 0;

	// for loop to print each string in the array
	for (index = 0; index < n; index++)
	{
		printf ("%s\n", *(pointerArray + index));
	} // end for loop
} // end printStrings

/*******************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA 1, part 1
* Date: 01/28/2015
* Function: driverTestSort
* Description: This function tests the functions
* Precondition: pointerArray must be loaded with addresses from
*				list, list must be intialized
* Postcondition: the pointerArray will be sorted in the order 
*				specified by the user then 
*				the values pointerArray points to will be printed
*				to the screen in the order they have been placed
*				into pointerArray
********************************************************************/
void driverTestSort(char *list[], char *pointerArray[], int n, int sortOrder)
{
	// print list before sort
	printf ("Before sort:\n");
	printStrings (pointerArray, n); // print the original list

	// call sort function:
	sort (list, pointerArray, n, sortOrder); // sort the list

	// print the list after sort
	printf ("\nAfter sort:\n");
	printStrings (pointerArray, n); // print the sorted list

} // end driverTestSort