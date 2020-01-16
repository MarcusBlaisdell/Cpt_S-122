#include "Blaisdell_PA1_3.h"

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA1, part 3
* Date: 01/28/2015
* Function: encrypt
* Description: This function will convert the characters to uppercase then
*				shift the characters by the specified amount.
*				A positive integer value shifts them to the right.
*				A negative integer value shifts them to the left.
* Precondition: A string must be initialized. A shift-level integer must be 
				initialize.
* Postcondition: The characters in the string will be shifted the specified level
*				all characters will be printed in uppercase
*
*********************************************************************************/
void encrypt (char *theString, int shift)
{
	// use an index variable to control movement through the array
	int index = 0;

	// first, convert to all uppercase using a while loop
	while (theString[index] != '\0')
	{
		// use ctype function toupper() to convert text
		*(theString + index++) = toupper(*(theString + index));
	} // end while loop to convert to all uppercase

	index = 0; // reset the index

	// encrypt / decrypt, using a while loop
	while (*(theString + index) != '\0')
	{
	*(theString + index) = (*(theString + index)) + shift;
	if (*(theString + index) < 'A')
	{
		*(theString + index) = (*(theString + index)) + 26;
	} // end if below A, move to end of alphabet

	if (*(theString + index) > 'Z')
	{
		*(theString + index) = (*(theString + index)) - 26;
	} // end if above Z, move to beginning of alphabet
	
	// since I'm checking for going beyond the A / Z limits after encrypting, 
	// I can't increment the counter until after evaluation is complete
	index++;
	} // end while encryption loop

} // end encrypt function

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA1, part 3
* Date: 01/28/2015
* Function: getString
* Description: This function prompts the user to enter a character string to 
*				encrypt / decrypt
* Precondition: Called from main, string "theArray" must exist
* Postcondition: string "theArray" will be loaded with a string of characters
*				entered by the user.
* 
*********************************************************************************/
void getString (char *theString)
{
	printf ("Enter a string of no more than 20 characters to encrypt: ");
	scanf ("%s", theString); // theString is already an address, don't need address-of operator
} // end getString function

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA1, part 3
* Date: 01/28/2015
* Function: getShiftLevel
* Description: Prompts the user to enter an integer to be used as a cypher level
*				the ascii values of the characters will be shifted by this level.
* Precondition: variable "shift" must be declared and passed in as a parameter
* Postcondition: shift level will be assigned and returned to main.
*********************************************************************************/
int getShiftLevel (int shift)
{
	printf ("Enter a level to shift the characters: ");
	scanf ("%d", &shift);

	return shift;
} // end getShiftLevel function

void masterFunction (void)
{
	// declare and initialize a character string
	char theString[21] = {""};
	// declare and initialize a shift level
	int shift = 0;

	// get character string from the user
	getString(theString);
	
	// get shift level (encryption/decryption level from the user
	shift = getShiftLevel (shift);

	// encrypt / decrypt the string using the shift (cypher) level
	encrypt (theString, shift);

	// print the result
	printf ("%s\n", theString);
} // end masterFunction

void testDriverFunction (void)
{
	// skip the get input from user, this will test encrypt, decrypt only:
	char theString[8] = "Testing", theStringDecrypt[8] = "XIWXMRK";
	int shift = 4, shiftDecrypt = -4;

	// print string before encryption:
	printf ("Before encryption: %s\n", theString);

	// call the function with the above parameters
	encrypt (theString, shift);

	// print the result:
	printf ("After encryption: %s\n", theString);

	// now, decrypt, just everything in reverse
	encrypt (theStringDecrypt, shiftDecrypt);

	// print the decrypted string
	printf ("After decryption: %s\n", theStringDecrypt);
} // end testDriverFunction