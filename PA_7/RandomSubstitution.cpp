#include "RandomSubstitution.h"

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA7
* Date: 04/10/2015
* Function: RandomSubstitution class default constructor
* Description: This is the default constructor for the RandomSubstitution class
* Precondition: there must be an instantiation of the class
* Postcondition: Currently just prints a message, the member data is a 
*				2d array that will get initialized before it's used in the
*				member functions
*********************************************************************************/

RandomSubstitution::RandomSubstitution ()
{
	cout << "RandomSubstitution default constructor called" << endl;
} // end RandomSubstitution default constructor

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA7
* Date: 04/10/2015
* Function: RandomSubstitution class destructor
* Description: This is the destructor for the RandomSubstitution class
* Precondition: there must be an instantiation of the RandomSubstitution class 
*				that has gone out of scope.
* Postcondition: Since there is no dynamic memory, it just prints a message to the screen
*********************************************************************************/

RandomSubstitution::~RandomSubstitution ()
{
	cout << "RandomSubstitution default destructor called" << endl;
} // end RandomSubstitution destructor

	// getters

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA7
* Date: 04/10/2015
* Function: getMessage
* Description: This is the get message getter
* Precondition: must be an instantiation of RandomSubstitution, function must be called
* Postcondition: returns the value of mMessage to the calling function
*********************************************************************************/

string RandomSubstitution::getMessage ()
{
	return mMessage;
} // end getMessage

// setters

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA7
* Date: 04/10/2015
* Function: setMessage
* Description: setter, sets the value of mMessage to the passed in string
* Precondition: must be an instantiation of RandomSubstitution
* Postcondition: the value of mMessage will be set to the value passed in
*********************************************************************************/

void RandomSubstitution::setMessage (string theMessage)
{
	mMessage = theMessage;
} // end setMessage function

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA7
* Date: 04/10/2015
* Function: setKey
* Description: sets the value of member data mKey to the 2d array passed in
* Precondition: must be an instantiation of RandomSubstitution
* Postcondition: the value of theKey will be set to the value passed in
*********************************************************************************/

void RandomSubstitution::setKey (char theKey[2][27])
{
	mKey[2][27] = theKey[2][27];
} // end setMessage

	// functions:

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA7
* Date: 04/10/2015
* Function: encode
* Description: encodes the data by first generating a key at random then
*				substituting individual characters for the randomly selected ones
* Precondition: must be an instantiation of RandomSubstitution, must be a message
*				to encode
* Postcondition: the message will be encoded
*********************************************************************************/

void RandomSubstitution::encode (RandomSubstitution *theRandomSubstitution)
{
		// variables:

	int theRandomNum = 0, index = 0, theNumArray[27], count = 0, index2 = 0, flag = 0;
	string theMessage;
	char theKey[2][27];

		// get the message from the user:

	cout << "Enter the message: " << endl;
	cin.ignore (); // prevent previous carriage return from sending us beyond this input
	getline (cin, theMessage); // cin >> theMessage;

	// convert the entire message to uppercase:

	while (theMessage[index] != '\0')
	{
		if (theMessage[index] >= 'a' && theMessage[index] <= 'z')
		{
			theMessage[index] = toupper (theMessage[index]);
		} // end if lowercase, convert to uppercase

		index++;

	} // end while loop to convert all to uppercase

	// reset index:

	index = 0;

		// create a randomly generated key:

	for (index = 0; index < 26; index++)
	{
		theKey[0][index] = 'A' + index;
	} // end initialize first dimension of array to regular alphabet

	theKey[0][26] = '\0';

	// reset the index

	index = 0;

	for (index = 0; index < 26; index++)
	{
		theKey[1][index] = '-';
	} // end initialize second dimension of array to the - character
	theKey[1][26] = '\0';

	index = 0;

	srand((unsigned)time (NULL)); // seed the random number generator
	
	// reset indexes

	index = 0;
	index2 = 0;

	// fill second dimension with randomly selected letters to map to regular alphabet:
	do
	{
		index2 = 0;
		flag = 0;
		char theLetter = '\0';
		theLetter = 'A' + rand () % 26;

			// read through the second dimension as is and look if the letter has already been assigned

		while ((theKey[1][index2] != '-') && (flag == 0))
		{
			if (theLetter == theKey[1][index2])
			{
				flag = 1;
			} // end if letter matches existing element, set flag
			else // if this position isn't the letter, move to the next position
			{
				index2++;
			}

		} // end while to check if letter has already been chosen
		
		// if we reach this point, we are in the clear, add this letter to this position
		
		if (flag == 0)
		{
			theKey[1][index] = theLetter;
			index++;
		} // end add if the flag is zero

	} while (index < 26);// end while loop to enter randomly assigned letters

	// terminate the second dimension:

	theKey[1][26] = '\0';

		// reset the index

	index = 0;

	// print the key to the screen:

	cout << "alphabet: " << endl;

	while (theKey[0][index] != '\0')
	{
		cout << " " << theKey[0][index++];
	} // end while loop to print the key
	cout << endl;
	index = 0;

	cout << "cipher:   " << endl;

	while (theKey[1][index] != '\0')
	{
		cout << " " << theKey[1][index++];
	} // end while loop to print the key
	cout << endl;
	index = 0;

		// store the key:

	setKey (theKey);

	// reset index2

	index2 = 0;

	// now that we have a key, do the encoding:

	// declare char of single letter: (taking advantage of C++ and declaring variables just before I use them)
	// This makes it harder to find them though so I likely will not use this option too much

	char theLetter = '\0';

	while (theMessage[index] != 0)
	{
		index2 = 0;

		theLetter = theMessage[index];
		while (theKey[0][index2] != '\0')
		{
			if (theKey[0][index2] == theLetter)
			{
				theMessage[index] = theKey[1][index2];
			} // end replace with cipher
			index2++;
		} // end while loop to find letter to substitute
		index++;
	} // end while loop to encode message

	// reset the index

	index = 0;
	
	// store the message:

	setMessage (theMessage);

		// print the encoded message to the screen:

	cout << "Encoded message:" << endl;
	cout << theMessage << endl;

} // end encode function

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA7
* Date: 04/10/2015
* Function: decodeWithKey
* Description: decode a message with a known key
* Precondition: must be an instantiation of the RandomSubstitution class, mMessage must contain a message
* Postcondition: the message will be decrypted with the provided key
*********************************************************************************/

void RandomSubstitution::decodeWithKey (RandomSubstitution *theRandomSubstitution)
{
		// declare variables:

	int index = 0, index2 = 0;
	char theKey[2][27], theKeyChar = '\0', theLetter = '\0';
	string theMessage;

	// initialize the first dimension of the array to the regular alphabet:

	for (index = 0; index < 26; index++)
	{
		theKey[0][index] = 'A' + index;
	} // end initialize first dimension
	
	// terminate the first dimension:

	theKey[0][index] = '\0';

	// reset the index;

	index = 0;

	// get the key from the user:

	cout << "Enter the key: " << endl;

	for (index = 0; index < 26; index++)
	{
		cout << theKey[0][index] << " = ";
		cin >> theKeyChar;
		theKey[1][index] = theKeyChar;
	} // end get the key from the user

	// terminate the second dimension:

	theKey[1][index] = '\0';

		// Decode the message:

	theMessage = getMessage ();

	while (theMessage[index] != 0)
	{
		index2 = 0;

		theLetter = theMessage[index];
		while (theKey[1][index2] != '\0')
		{
			if (theKey[1][index2] == theLetter)
			{
				theMessage[index] = theKey[0][index2];
			} // end replace with cipher
			index2++;
		} // end while loop to find letter to substitute
		index++;
	} // end while loop to decode message

	// print the message:

	cout << "Decoded: " << endl;
	cout << theMessage << endl;

} // end decodeWithKey function

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA7
* Date: 04/10/2015
* Function: decodeFrequencyAnalysis
* Description: Decode using frequency analysis, this one gets pretty long
* Precondition: must be an instantiation of the RandomSubstitution class
* Postcondition: This function will analyze the number of occurrences of each letter
* in the message and generate a key based on established letter frequency charts
*********************************************************************************/

void RandomSubstitution::decodeFrequencyAnalysis (RandomSubstitution *theRandomSubstitution)
{
			// declare variables:

	int index = 0, index2 = 0, theAlphaArray[26], messageLength = 0, max = 0, theAlphaArrayNum[26], tempNum = 0, 
		manualFlag = 0, swapCipherIndex1 = 0, swapCipherIndex2 = 0;
	
	double theAlphaPercentages[26];
	
	char theKey[2][27], theKey2[2][27], theKey3[2][27], tempKey[1][1], theAlphaArrayChar[26], tempChar = '\0', 
		swapCipher1 = '\0', swapCipher2 = '\0', tempCipher = '\0', correct = '\0';
	
	string theMessage, newMessage;

	// get a copy of the message to work locally without constantly using the getters:

	theMessage = theRandomSubstitution -> getMessage ();

	// initialize theAlphaArrayNum & theAlphaArrayChar:

	for (index = 0; index < 26; index++)
	{
		theAlphaArrayNum[index] = 0;
		theAlphaArrayChar[index] = 'A' + index; 
	} // end for loop to initialize theAlphaArray

	// reset the index:

	index = 0;

	// initialize the first dimension of the 2-d array theKey:

	for (index = 0; index < 26; index++)
	{
		theKey[0][index] = 'A' + index;
	} // end initialize first dimension of array to regular alphabet
	
	// terminate the string:

	theKey[0][26] = '\0';

	// reset the index

	index = 0;

	// reset the index:

	index = 0;

		// Frequency Analysis
		// count the occurrences of each letter

	while (theMessage[index] != '\0')
	{
		if (theMessage[index] == 'A')
		{
			theAlphaArrayNum[0]++;
		} // end if A

		if (theMessage[index] == 'B')
		{
			theAlphaArrayNum[1]++;
		} // end if 

		if (theMessage[index] == 'C')
		{
			theAlphaArrayNum[2]++;
		} // end if 

		if (theMessage[index] == 'D')
		{
			theAlphaArrayNum[3]++;
		} // end if 

		if (theMessage[index] == 'E')
		{
			theAlphaArrayNum[4]++;
		} // end if 

		if (theMessage[index] == 'F')
		{
			theAlphaArrayNum[5]++;
		} // end if 

		if (theMessage[index] == 'G')
		{
			theAlphaArrayNum[6]++;
		} // end if 

		if (theMessage[index] == 'H')
		{
			theAlphaArrayNum[7]++;
		} // end if 

		if (theMessage[index] == 'I')
		{
			theAlphaArrayNum[8]++;
		} // end if 

		if (theMessage[index] == 'J')
		{
			theAlphaArrayNum[9]++;
		} // end if 

		if (theMessage[index] == 'K')
		{
			theAlphaArrayNum[10]++;
		} // end if 

		if (theMessage[index] == 'L')
		{
			theAlphaArrayNum[11]++;
		} // end if 

		if (theMessage[index] == 'M')
		{
			theAlphaArrayNum[12]++;
		} // end if 

		if (theMessage[index] == 'N')
		{
			theAlphaArrayNum[13]++;
		} // end if 

		if (theMessage[index] == 'O')
		{
			theAlphaArrayNum[14]++;
		} // end if 

		if (theMessage[index] == 'P')
		{
			theAlphaArrayNum[15]++;
		} // end if 

		if (theMessage[index] == 'Q')
		{
			theAlphaArrayNum[16]++;
		} // end if 

		if (theMessage[index] == 'R')
		{
			theAlphaArrayNum[17]++;
		} // end if 

		if (theMessage[index] == 'S')
		{
			theAlphaArrayNum[18]++;
		} // end if 

		if (theMessage[index] == 'T')
		{
			theAlphaArrayNum[19]++;
		} // end if 

		if (theMessage[index] == 'U')
		{
			theAlphaArrayNum[20]++;
		} // end if 

		if (theMessage[index] == 'V')
		{
			theAlphaArrayNum[21]++;
		} // end if 

		if (theMessage[index] == 'W')
		{
			theAlphaArrayNum[22]++;
		} // end if 

		if (theMessage[index] == 'X')
		{
			theAlphaArrayNum[23]++;
		} // end if 

		if (theMessage[index] == 'Y')
		{
			theAlphaArrayNum[24]++;
		} // end if 

		if (theMessage[index] == 'Z')
		{
			theAlphaArrayNum[25]++;
		} // end if 

		index++;
	} // end count occurrences (Frequency Analysis)
	
	// reset the index:

	index = 0;

	// reset index to 0:

	index = 0;

	// sort the counts:

	// bubble sort by frequency of occurrence, greatest to least:

	index2 = 0;

	for (index = 0; index < 26; index++)
	{
		for (index2 = 0; index2 < 26; index2++)
		{
			if (theAlphaArrayNum[index2] < theAlphaArrayNum[index2 + 1] )
			{
				tempNum = theAlphaArrayNum[index2];
				tempChar = theAlphaArrayChar[index2];

				theAlphaArrayNum[index2] = theAlphaArrayNum[index2 + 1];
				theAlphaArrayChar[index2] = theAlphaArrayChar[index2 + 1];

				theAlphaArrayNum[index2 + 1] = tempNum;
				theAlphaArrayChar[index2 + 1] = tempChar;

			} // end if index + 1 is greater than index, swap
		} // end inner loop

	} // end outer loop
	
	// reset the indexes:

	index = 0;
	index2 = 0;

		// print the frequency analysis to the screen:

	cout << "Sorted: " << endl;

	for (index = 0; index < 26; index++)
	{
		cout << " " << theAlphaArrayNum[index];
	}
	cout << endl;
	index = 0;

	for (index = 0; index < 26; index++)
	{
		cout << " " << theAlphaArrayChar[index];
	}
	cout << endl;
	index = 0;

		// now do character assignment based on number of occurrences:

	// find max of theAlphaArray, make that letter E
	// find next largest number, make that T
	// etc.

	// assign the cipher to the key

	theKey[1][4]  = theAlphaArrayChar[0];  // most common gets set to 'E'
	theKey[1][19] = theAlphaArrayChar[1];  // next most common gets set to 'T'
	theKey[1][0]  = theAlphaArrayChar[2];  // next most common gets set to 'A'
	theKey[1][14] = theAlphaArrayChar[3];  // next most common gets set to 'O'
	theKey[1][8]  = theAlphaArrayChar[4];  // next most common gets set to 'I'
	theKey[1][13] = theAlphaArrayChar[5];  // next most common gets set to 'N'
	theKey[1][18] = theAlphaArrayChar[6];  // next most common gets set to 'S'
	theKey[1][7]  = theAlphaArrayChar[7];  // next most common gets set to 'H'
	theKey[1][17] = theAlphaArrayChar[8];  // next most common gets set to 'R'
	theKey[1][3]  = theAlphaArrayChar[9];  // next most common gets set to 'D'
	theKey[1][2]  = theAlphaArrayChar[10]; // next most common gets set to 'C'
	theKey[1][20] = theAlphaArrayChar[11]; // next most common gets set to 'U'
	theKey[1][12] = theAlphaArrayChar[12]; // next most common gets set to 'M'
	theKey[1][11] = theAlphaArrayChar[13]; // next most common gets set to 'L'
	theKey[1][22] = theAlphaArrayChar[14]; // next most common gets set to 'W'
	theKey[1][5]  = theAlphaArrayChar[15]; // next most common gets set to 'F'
	theKey[1][6]  = theAlphaArrayChar[16]; // next most common gets set to 'G'
	theKey[1][24] = theAlphaArrayChar[17]; // next most common gets set to 'Y'
	theKey[1][15] = theAlphaArrayChar[18]; // next most common gets set to 'P'
	theKey[1][1]  = theAlphaArrayChar[19]; // next most common gets set to 'B'
	theKey[1][21] = theAlphaArrayChar[20]; // next most common gets set to 'V'
	theKey[1][10] = theAlphaArrayChar[21]; // next most common gets set to 'K'
	theKey[1][9]  = theAlphaArrayChar[22]; // next most common gets set to 'J'
	theKey[1][23] = theAlphaArrayChar[23]; // next most common gets set to 'X'
	theKey[1][16] = theAlphaArrayChar[24]; // next most common gets set to 'Q'
	theKey[1][25] = theAlphaArrayChar[25]; // next most common gets set to 'Z'

	// use the key to decode the message:

	char theLetter = '\0';

	while (theMessage[index] != '\0')
	{
		index2 = 0;

		theLetter = theMessage[index];
		while (theKey[1][index2] != '\0')
		{
			if (theKey[1][index2] == theLetter)
			{
				theMessage[index] = theKey[0][index2];
			} // end replace with cipher

			index2++;

		} // end while loop to find letter to substitute

		index++;

	} // end while loop to decode message

	// print the message:

	cout << "Decoded: " << endl;
	cout << theMessage << endl;

	// now, let's fine tune it:

	// reset our indexes:

	index = 0;
	index2 = 0;

	cout << "Current key:" << endl;
	cout << "Alphabet: ";
	for (index = 0; index < 26; index++)
	{
		cout << theKey[0][index] << ":";
	} // end print the current key

	cout << endl;

	cout << "Cipher  : ";
	for (index2 = 0; index2 < 26; index2++)
	{
		cout << theKey[1][index2] << ":";
	}
	cout << endl;

	// reset our indexes:

	index = 0;
	index2 = 0;

		// manually decode:************************************************************************

		// make a copy of the message for comparisons
		// What we are doing here is modifying the frequency analysis key
		// we are hoping that it gave us a head start on decoding the message

	newMessage = theMessage;

	while (manualFlag != 1)
	{
		cout << "Is the decoded message correct? (y/n)" << endl;
		cin >> correct;

		if (correct == 'n')
		{

					// reset our indexes:

			index = 0;
			index2 = 0;

			cout << "Alphabet: ";
			for (index = 0; index < 26; index++)
			{
				cout << theKey[0][index] << ":";
			} // end print the current key
			cout << endl;

			cout << "Cipher  : ";
			for (index2 = 0; index2 < 26; index2++)
			{
				cout << theKey[1][index2] << ":";
			}
			cout << endl << endl;

			cout << "What CIPHER letter would you like to change: " << endl;
			cin >> swapCipher1;

			cout << "What would you like to change it to? " << endl;
			cin >> swapCipher2;

			// reset indexes
			index = 0;
			index2 = 0;

			while (theKey[1][index] != '\0')
			{
				if (theKey[1][index] == swapCipher1)
				{
					swapCipherIndex1 = index;
				}
				if (theKey[1][index] == swapCipher2)
				{
					swapCipherIndex2 = index;
				}

				index++;
			}

			// swap the two indexes:

				tempCipher = theKey[1][swapCipherIndex1];
				theKey[1][swapCipherIndex1] = theKey[1][swapCipherIndex2];
				theKey[1][swapCipherIndex2] = tempCipher;

			// reset the indexes
			index = 0;
			index2 = 0;

			// reset our indexes:

			index = 0;
			index2 = 0;

			// print the new key:

			cout << "Alphabet: ";
			for (index = 0; index < 26; index++)
			{
				cout << theKey[0][index] << ":";
			} // end print the current key
			cout << endl;

			cout << "Cipher  : ";
			for (index2 = 0; index2 < 26; index2++)
			{
				cout << theKey[1][index2] << ":";
			}
			cout << endl;

			// reset the indexes:
			index = 0;
			index2 = 0;

			// redo the decode:
			// reset the decoded message back to original coded message and try again

			newMessage = theMessage;

			while (newMessage[index] != '\0')
			{
				index2 = 0;

				theLetter = newMessage[index];
				while (theKey[0][index2] != '\0')
				{
					if (theKey[0][index2] == theLetter)
					{
						newMessage[index] = theKey[1][index2];
					} // end replace with cipher
					index2++;
				} // end while loop to find letter to substitute
				index++;
			} // end while loop to decode message
	
			// print the message:

			cout << "Encoded: " << endl;
			cout << theMessage << endl;
			cout << "Decoded: " << endl;
			cout << newMessage << endl;

	} // end if message is not correct
	else if (correct == 'y')
	{
		manualFlag = 1;
	} // end else message is correct, set manualFlag to 1 to break out of while loop

	} // end while still manipulating data

} // end decodeFrequencyAnalysis function 