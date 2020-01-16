#include "Menu.h"

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA7
* Date: 04/10/2015
* Function: Menu class default constructor
* Description: default constructor for the menu class
* Precondition: must be an instantiation of the menu class
* Postcondition: currently prints a helpful message to the screen
*********************************************************************************/

Menu::Menu ()
{
	cout << "Menu default constructor called" << endl;
} // end Menu default constructor

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA7
* Date: 04/10/2015
* Function: Menu class copy constructor
* Description: copy constructor for the menu class
* Precondition: must be an instantiation of the menu class
* Postcondition: prints a helpful message to the screen
*********************************************************************************/

Menu::Menu (Menu &copyObject)
{
	cout << "Menu copy constructor called" << endl;
	// no private members to copy
} // end Menu copy constructor

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA7
* Date: 04/10/2015
* Function: Menu class destructor
* Description: destructor for the menu class
* Precondition: must be an instantiation of the menu class that is going out of scope
* Postcondition: prints a helpful message to the screen
*********************************************************************************/

Menu::~Menu ()
{
	cout << "Menu destructor called" << endl;
} // end Menu destructor

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA7
* Date: 04/10/2015
* Function: mainMenu
* Description: This displays the main menu for the program
* Precondition: must be an instantiation of the menu class
* Postcondition: menu will be displayed, individual functions will be called 
* based on menu selection
*********************************************************************************/

void Menu::mainMenu (void)
{
		// instantiate an object of each of the cipher classes:
	
	Caesar theCaesar;
	RandomSubstitution theRandomSubstitution;
	
		// declare necessary variables:

	int exitFlag = 0, menuChoice = 0;

		// use a while loop to control the menu function:

	while (exitFlag != 1)
	{
			// display the menu:

		cout << "Main Menu:" << endl;
		cout << "1) Use Caesar shift cipher" << endl;
		cout << "2) Use Random Substitution cipher" << endl;
		cout << "3) exit" << endl;

		// get the menu choice from the user
		cin >> menuChoice;

			// use switch to validate menu input

		switch (menuChoice)
		{
		case 1:
			subCaesar (&theCaesar);
			break;
		case 2:
			subRandom (&theRandomSubstitution);
			break;
		case 3:
			exitFlag = 1;
			break;
		default:
			cout << "You should not be seeing this" << endl;
			break;
		};

	} // end while loop

	cout << "Goodbye!" << endl;

} // end mainMenu function

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA7
* Date: 04/10/2015
* Function: subCaesar
* Description: The Caesar shift sub menu, provides options related to Caesar shift
* Precondition: must be an instantiation of Caesar class, called from main menu
* function of menu class
* Postcondition: the desired Caesar shift function will be called.
*********************************************************************************/

void Menu::subCaesar (Caesar *theCaesar)
{
		// declare variables:

	int exitFlag = 0, menuChoice = 0;

	// use a while loop to run the sub-menu

	while (exitFlag != 1)
	{
		cout << "Choose an operation:" << endl;
		cout << "1) encode" << endl;
		cout << "2) decode with key" << endl;
		cout << "3) decode by brute force" << endl;
		cout << "4) return to previous menu" << endl;

		// get input from user:
		cin >> menuChoice;

			// evaluate user response:

		switch (menuChoice)
		{
		case 1:
			theCaesar -> encode (theCaesar);
			break;
		case 2:
			theCaesar -> decodeWithKey (theCaesar);
			break;
		case 3:
			theCaesar -> decodeBruteForce (theCaesar);
			break;
		case 4:
			exitFlag = 1;
			break;
		default:
			cout << "Enter a valid choice" << endl;
			break;
		}; // end switch statement

	} // end while loop
} // end subCaesar function

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA7
* Date: 04/10/2015
* Function: subRandom
* Description: The RandomSubstitution shift sub menu, provides options related to 
*				RandomSubstitution shift
* Precondition: must be an instantiation of RandomSubstitution class, called from main menu
* function of menu class
* Postcondition: the desired RandomSubstition function will be called.
*********************************************************************************/

void Menu::subRandom (RandomSubstitution *theRandomSubstitution)
{
		// declare variables:

	int exitFlag = 0, menuChoice = 0;

		// use a while loop to control the sub-menu

	while (exitFlag != 1)
	{
		cout << "Choose an operation:" << endl;
		cout << "1) encode" << endl;
		cout << "2) decode with key" << endl;
		cout << "3) decode by brute force" << endl;
		cout << "4) return to previous menu" << endl;

		// get input from user:
		cin >> menuChoice;

			// evaluate user response

		switch (menuChoice)
		{
		case 1:
			theRandomSubstitution -> encode (theRandomSubstitution);
			break;
		case 2:
			theRandomSubstitution -> decodeWithKey (theRandomSubstitution);
			break;
		case 3:
			theRandomSubstitution -> decodeFrequencyAnalysis (theRandomSubstitution);
			break;
		case 4:
			exitFlag = 1;
			break;
		default:
			cout << "Enter a valid choice" << endl;
			break;
		}; // end switch statement

	} // end while loop
} // end subRandom function