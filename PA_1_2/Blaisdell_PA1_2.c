#include "Blaisdell_PA1_2.h"

/*******************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA1, part 2
* Date: 01/26/2015
* Function: isPalindrome
* Description: passes the string to removePunct to strip any punctuation
*				then calls x to use recursion to determine if it is a palindrome
* Precondition: string must be initialized 
* Postcondition: returns 1 if the string is a palindrome, 0 if not
********************************************************************/
void isPalindrome (char *theString)
{
	// variable declaration, a beginning index, ending index and an "is it or isn't it" flag
	int beginIndex = 0, endIndex = 0, isItPalindrome = 0;
	
	// remove punctuation
	removePunct (theString);

	// set endIndex to string length minus 1 for zero start array indexing
	endIndex = strlen(theString) - 1;

	// evaluate the string as a palindrome, set "is it or isn't it flag" appropriately
	isItPalindrome = recursiveEvaluate (theString, beginIndex, endIndex);

	// print the result of the evaluation
	if (isItPalindrome == 1)
	{
		printf ("Is a palindrome!\n");
	}
	else
	{
		printf ("Is not a palindrome\n");
	}

} // end isPalindrome function

/*******************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA1, part 2
* Date: 01/26/2015
* Function: removePunct
* Description: remove any non-alpha character, make all lower-case
*				
* Precondition: theString must be initialized
* Postcondition: theString will contain just alpha characters
********************************************************************/
void removePunct (char *theString)
{
	// variables declarations, 
	int index = 0, index2 = 0;
	char temp = '\0';

	// remove non-alpha characters, read the array until a non-alpha character is encountered
	// when a non-alpha char is encountered, shift all remaining characters one space to the left
	// and then continue reading the array from the same point and continue evaluating
	// all remaining characters

	while (theString[index] != '\0')
	{
		// check if character at current position is alpha
		if ((theString[index] >= 'A') && (theString[index] <= 'Z') || 
			(theString[index] >= 'a') && (theString[index] <= 'z'))
		{
			index++;
		}  // only increment the first index if a character is alpha
		else
		{
			// shift all remaining characters in the array one space to the left, overwriting
			// the non-alpha character
			index2 = index; // set second index to current position and run through the end of the string
			while (*(theString + index2) != '\0')
			{
				*(theString + index2) = *(theString + index2 + 1);
				index2++;
			} // end shift characters left one position
		} // end remove non-alpha
	} // end while loop to run through the string looking for non-alpha characters

	// convert all remaining characters to lower-case for direct comparison
	for (index = 0; index < strlen(theString); index++)
	{
		theString[index] = tolower(theString[index]);
	} // end for loop to check each position in the string
}

/*******************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA1, part 2
* Date: 01/26/2015
* Function: recursiveEvaluate
* Description: This function evaluates the string as a palindrome
*				by comparing the first character and last character,
*				if they are the same, it checks the next to first
*				character and the next to last and so on until 
*				the indexs are either equal or only 1 apart 
* Precondition: theString must be declared and initialized, 
*				theString must be stripped of non-alpha chars
*				theString must be converted to all lower case
* Postcondition: if the string is a palindrome, returns a 1, if not
*				returns a 0
********************************************************************/
int recursiveEvaluate (char *theString, int beginIndex, int endIndex)
{
	// variable declarations
	int isItPalindrome = 1;

	// base case is indexes are either equal or only one integer value apart
	// check if base case, if not, evaluate indexes, if yes, finish out
	if (endIndex <= beginIndex)
	{
		// we're done, there's really nothing to do in this statement
	}
	else
	{
		// compare characters at each of the indexes
		if (theString[beginIndex] == theString[endIndex])
		{
			isItPalindrome = recursiveEvaluate (theString, ++beginIndex, --endIndex);
		} // end if characters at each index match evaluation
		else // if not a match, fail out
		{
			// set isItPalindrome flag to 0 to indicate the string is not a palindrome and no point in 
			// continuing
			isItPalindrome = 0;
		} // end else, string is not a palindrome
	} // end base case else

	return isItPalindrome; 
}

/*******************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA1, part 2
* Date: 01/26/2015
* Function: testDriver
* Description: This function tests the passed in strings
* Precondition: theString must be declared and initialized, 
*				theString must be stripped of non-alpha chars
*				theString must be converted to all lower case
* Postcondition: if the string is a palindrome, it will inform you of such
*				if not, it will let you know that as well
********************************************************************/
void testDriver (char *theString)
{
	// print the string before we strip the characters
	printf ("%s\n", theString);

	// run the functions that will do all the stripping, lower-casing and evaluating
	isPalindrome (theString);
} // end testDriver function