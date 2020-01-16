#include "Caesar.h"

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA7
* Date: 04/10/2015
* Function: Caesar class default constructor
* Description: This is the default constructor for the Caesar class
* Precondition: There must be an instantiation of the class
* Postcondition: The private data members of the class will be initialized
*
*********************************************************************************/

Caesar::Caesar ()
{
	mCipher  = false;
	mMessage = "";
	mKey     = 0;
} // end default constructor

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA7
* Date: 04/10/2015
* Function: Caesar class destructor
* Description:  this is called when an object of this class goes out of scope
* Precondition: an instantiation of the Caesar class must have existed and 
*				gone out of scope
* Postcondition: Since no dynamic memory is being allocated, it just prints a 
*				helpful message to the screen.
*
*********************************************************************************/

Caesar::~Caesar ()
{
	cout << "Caesar destructor called" << endl;
} // end destructor

	// getters & setters:

// getters:

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA7
* Date: 04/10/2015
* Function: getMessage
* Description:  returns the value of mMessage to the calling function
* Precondition: There must be an instantiation of the Caesar class, 
*				the getter must have been called
* Postcondition: returns the value of mMessage to the calling function
*
*********************************************************************************/

string Caesar::getMessage (void)
{
	return mMessage;
} // end getMessage function

	//setters

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA7
* Date: 04/10/2015
* Function: setMessage
* Description:  sets the value of mMessage for an instantiation of the Caesar class
* Precondition: There must be an instantiation of the Caesar class, the message
*				should contain a value though could be set to null
* Postcondition: the value of mMessage for an instantiation of the class
*				will be set to the message string that is passed in
*
*********************************************************************************/

void Caesar::setMessage (string theMessage)
{
	mMessage = theMessage;
} // end setMessage function

// unique functions:

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA7
* Date: 04/10/2015
* Function: encode
* Description: shifts the level of the ascii characters of the message 
*				by a specified amount
* Precondition: theMessage needs to have data
* Postcondition: characters in theMessage will be shifted
*********************************************************************************/

void Caesar::encode (Caesar *theCaesar)
{
		// declare variables:

	string theMessage;
	int shiftLevel = 0, index = 0;

		// prompt for and read in the message from the user:

	cout << "Enter the message: " << endl;
	cin.ignore (); // prevent previous carriage return from sending us beyond this input
	getline (cin, theMessage); // cin >> theMessage;

		// prompt for and read in the shift level:

	cout << "Enter a shift level: " << endl;
	cin >> shiftLevel;
	char temp;

	// convert to uppercase:
	while (theMessage[index] != '\0')
	{
		if (theMessage[index] >= 'a' && theMessage[index] <= 'z')	
		{
			temp = toupper (theMessage[index]);
			theMessage[index] = temp;
		} // end convert to uppercase
		index++;
	} // end while loop to read through the full message

	// reset index:
	index = 0;

	// encode message: // works!
	
	while (theMessage[index] != '\0')
	{
		if (theMessage[index] >= 'A' && theMessage[index] <= 'Z')
		{
			theMessage[index] = theMessage[index] + shiftLevel;

				// if the shift puts us past 'Z', adjust it back to the other end of the alphabet
			if (theMessage[index] > 'Z')
			{
				theMessage[index] = (theMessage[index] - 26);
			} // end if we go beyond 'Z', adjust it
			
				// if the shift puts us before 'A', adjust it back to the other end of the alphabet
			if (theMessage[index] < 'A')
			{
				theMessage[index] = (theMessage[index] + 26);
			} // end if we go beyond 'Z', adjust it

		} // end only convert if it is a letter
		index++;
	} // end convert the message

		// store the encrypted message 

	setMessage (theMessage);

		// print to the screen:

	cout << "Encrypted Message: " << endl;
	cout << theMessage << endl;

} // end encode function

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA7
* Date: 04/10/2015
* Function: decodeWithKey
* Description:
* Precondition: 
* Postcondition: 
*********************************************************************************/

void Caesar::decodeWithKey (Caesar *theCaesar)
{
		// declare variables:

	int theKey = 0, index = 0;

		// prompt for and read in the key:

	cout << "Enter the key: ";
	cin >> theKey;

	// decode message
	while (theCaesar -> mMessage[index] != '\0')
	{
		if (theCaesar -> mMessage[index] >= 'A' && theCaesar -> mMessage[index] <= 'Z')
		{
			theCaesar -> mMessage[index] = theCaesar -> mMessage[index] - theKey;
				// if this puts us past 'Z', adjust back to the other end of the alphabet
			if (theCaesar -> mMessage[index] > 'Z')
			{
				theCaesar -> mMessage[index] = theCaesar -> mMessage[index] - 26;
			}
				// if this puts us before 'A', adjust back to the other end of the alphabet
			if (theCaesar -> mMessage[index] < 'A')
			{
				theCaesar -> mMessage[index] = theCaesar -> mMessage[index] + 26;
			}
		}
		index++;

	} // end while loop to decode message

	cout << "Decrypted message: " << endl;
	cout << theCaesar -> mMessage << endl;

} // end decodeWithKey function

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA7
* Date: 04/10/2015
* Function: decodeBruteForce
* Description:
* Precondition: 
* Postcondition: 
*********************************************************************************/

void Caesar::decodeBruteForce (Caesar *theCaesar)
{
		// declare variables:

	int theKey = 1, index = 0, continueDecoding = 0;
	char correct = 'n';
	string decoded[1000];

	// decode message using each of the 25 possible shift levels
	// allow user to specify that a key is correct and break out of the loop

	while (theKey < 26)
	{
		while (theCaesar -> mMessage[index] != '\0')
		{
			if (theCaesar -> mMessage[index] >= 'A' && theCaesar -> mMessage[index] <= 'Z')
			{
				// decoded[index] = theCaesar -> mMessage[index] - theKey;
				theCaesar -> mMessage[index] = theCaesar -> mMessage[index] - theKey;
					// if this puts us past 'Z', adjust back to the other end of the alphabet
				if (theCaesar -> mMessage[index] > 'Z')
				{
					theCaesar -> mMessage[index] = theCaesar -> mMessage[index] - 26;
				}
					// if this puts us past 'Z', adjust back to the other end of the alphabet
				if (theCaesar -> mMessage[index] < 'A')
				{
					theCaesar -> mMessage[index] = theCaesar -> mMessage[index] + 26;
				}
			}
			index++;
		} // end while loop to decode message
		
		// reset index

		index = 0;

			// print our current level and it's decryption

		cout << "Shift Level : " << theKey << endl;
		cout << "Decrypted message: " << endl;
		cout << theCaesar -> mMessage << endl;

			 // prompt user for evaluation

		cout << "Does this look correct? (y/n)";
		cin >> correct;

		if (correct != 'y')
		{
			cout << "moving on to next shift level" << endl;
			theKey++;
		} // end if not correct
		else
		{
			theKey = 27; // set the key greater than 26 to break out of while loop
		} // end if correct

	} // end outer while loop

} // end decodeBruteForce function