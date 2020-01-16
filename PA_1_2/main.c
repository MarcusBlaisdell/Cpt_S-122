/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA1 part 2
* Date: 01/26/2015
* Description: This program performs the following:
* Uses recursion to determine if a string is a palindrome.
* Punctuation is removed before evaluation
*
**********************************************************************************/

#include "Blaisdell_PA1_2.c"

int main (void)
{
	// variable declarations
	char theString[16] = {"Madam, I'm Adam"}, theString2[16] = {"Georgie Porgie"},
		theString3[20] = {"Rise to vote, sir!"}, theString4[18] = {"Madam, I'm a damn"};

	// use test drivers to test the strings
	testDriver (theString);

	testDriver (theString2);

	testDriver (theString3);

	testDriver (theString4);

	return 0;
}
