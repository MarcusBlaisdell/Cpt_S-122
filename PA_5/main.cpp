/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PAx
* Date: 03/06/2015
* Description: This program performs the following:
* Creates a class for Accounts and another for the main banking functions
* Allows a user to add accounts, delete accounts, add and subract funds
* and print the records to the screen
*
**********************************************************************************/

#include "BankMain.cpp"
#include "Account.cpp"

int main (void)
{
		// declare an instance of the BankMain class to use to control the program

	BankMain theBankMain; // I now have an instance of the BankMain class, an object

		// use an int for the menu;

	int theChoice = 0;

		// use a do-while loop for the main menu:

	do
	{
		// display the menu:

	cout << "Main Menu"                << endl; // I must admit,
	cout << "1) Add an acccount"       << endl; // aligning the
	cout << "2) Delete an account"     << endl; // lines does
	cout << "3) Credit acccount"       << endl; // make this
	cout << "4) Debit account"         << endl; // a lot easier
	cout << "5) Display Accounts"      << endl; // to read
	cout << "6) Exit"                  << endl; // (saw Travis Lane do it)

		// read in the user entry

	cin >> theChoice;

		// use a switch statement for the menu:

	switch (theChoice)
	{
	case 1:
		theBankMain.insertNewAccount ();
		break;
	case 2:
		theBankMain.deleteAccount ();
		break;
	case 3:
		theBankMain.creditAccount ();
		break;
	case 4:
		theBankMain.debitAccount ();
		break;
	case 5:
		theBankMain.displayAccounts ();
		break;
	case 6:
		cout << "Goodbye!" << endl;
	default:
		break;
	} // end switch statement

	} while (theChoice != 6); // end do-while loop to run the menu

	return 0;
}
