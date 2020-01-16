/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA7
* Date: 04/10/2015
* Description: This program performs the following:
* ciphers
* There are two options, Caesar shift cipher and random substitution cipher
* User can choose either option to encode a message
* and then attempt to decode that message either with a key or by a brute force
* attack.
* The random substitution will provide a best guess based on frequency analysis
* and provides a means of individually fine-tuning the cipher key to successfully
* decode the message.
*
**********************************************************************************/

#include "base.cpp"
#include "Caesar.cpp"
#include "RandomSubstitution.cpp"
#include "Menu.cpp"

int main (void)
{
	Menu theMenu;

	theMenu.mainMenu ();

	return 0;
}
