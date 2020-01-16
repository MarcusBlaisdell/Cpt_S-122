#include "BankMain.h"

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA5, Basic Bank Application in C++
* Date: 03/06/2015
* Function: Default Constructor
* Description: This will create an empty BankMain if no information is passed in.
* Precondition: The function must be called with no arguments
* Postcondition: a blank instance will be created
*
*********************************************************************************/

BankMain::BankMain ()
{
		// set count of accounts variable to zero:

	countAccounts = 0;

		// set pHead to NULL

	pHead = NULL;

} // end default constructor

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA5, Basic Bank Application in C++
* Date: 03/06/2015
* Function: copy Constructor
* Description: This will copy the information from one instance to another
* Precondition: An instance of BankMain must exist, this is cooperative code,
*				not defensive
* Postcondition: The new instance will contain the information from the first 
*				instance
*
*********************************************************************************/

BankMain::BankMain (BankMain & copyObject)
{
		// set new variables to the values of existing variables:

	this -> countAccounts = copyObject.countAccounts;
	this -> pHead = copyObject.pHead;

} // end copy constructor

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA5, Basic Bank Application in C++
* Date: 03/06/2015
* Function: destructor
* Description: This will delete any nodes in the linked list 
* Precondition: The function must be called with no arguments
* Postcondition: all memory that was used will be freed
*
*********************************************************************************/

BankMain::~BankMain ()
{
		// delete all nodes to free up the memory we used:

		// declare Account variables for navigation and deletion:

	Account *pPrev = NULL, *pCur = NULL;

		// set pCur to pHead for navigation

	pCur = pHead;

		// use a while loop to delete all records:

	while (pCur != NULL)
	{
		pPrev = pCur;
		pCur = pCur -> mpNext;

			// delete the previous node:

		delete pPrev;

	} // end while loop

} // end destructor

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA5, Basic Bank Application in C++
* Date: 03/06/2015
* Function: makeNode
* Description: This will create a new node 
* Precondition: The values for the node must exist and be passed in as arguments
* Postcondition: A new node is created with the arguments and returned to the 
*				calling function
*********************************************************************************/

Account *BankMain::makeNode (double balance, int number, string name, string date)
{
		// declare a variable of type Account:

	Account *pMem = NULL;

		// allocate memory for the new node:

	pMem = new Account (balance, number, name, date);

		// return the node to calling function:

	return pMem;

} // end makeNode function


/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA5, Basic Bank Application in C++
* Date: 03/06/2015
* Function: insertNewAccount
* Description: This function inserts a new account into the linked list
* Precondition: Called from main, must be called by user
* Postcondition: will prompt for all values to create the account and then
*				create the account and then insert it into the linked list
*********************************************************************************/

bool BankMain::insertNewAccount ()
{
		// declare all variables

	Account *pMem = NULL, *pPrev = NULL, *pCur = NULL;
	bool success = false;
	double theBalance = 0.0;
	int theAccount = 0;
	string theName = "";
	string theDate = "";

		// prompt the user for and get input for all necessary variables

	cout << "Enter the initial balance: "; // the initial balance on the account
	cin >> theBalance;
	cout << endl;
	cout << "Enter the account number: "; // the account number, user specified? should be auto-generated
	cin >> theAccount;
	cout << endl;
	cout << "Enter the name: "; // name of account holder
	cin.ignore(); // from stack overflow, fixed my problem of skipping the read in of the next input
	getline (cin, theName); // from the book, reads in spaces (everything up to newline)
	cout << endl;
	cout << "Enter the date: "; // the date the account was created, user specified? shouldn't it be auto-generated?
	cin >> theDate;
	cout << endl;

		// create a new node with the provided information:

	pMem = makeNode (theBalance, theAccount, theName, theDate);

		// check if list is empty, if so, insert new node at pHead

	if (pHead == NULL)
	{
		pHead = pMem;
	} // end if list is empty

		// if the list is not empty, insert in order:

	else
	{
			// set pCur to pHead and use pCur to navigate the list

		pCur = pHead;
	
			// move to the correct position to insert the account

		while ((pCur != NULL) && ((pCur -> mName) < theName))
		{
			pPrev = pCur;
			pCur = pCur -> mpNext;
		} // end while loop to navigate to position (end of list)

			// insert the new account

				// check if we are at the front, if not, insert in order, if so, insert at front:

			if (pPrev != NULL) // not at front
			{
				pPrev -> mpNext = pMem;
				pMem -> mpNext = pCur;
			}

			else // insert at front
			{
				pMem -> mpNext = pHead;
				pHead = pMem;
			}

	} // end else, list is not empty

		// update the success flag:

	success = true;

	return success;

} // end insertNewAccount

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA5, Basic Bank Application in C++
* Date: 03/06/2015
* Function: deleteAccount
* Description: This function deletes an account from the linked list
* Precondition: The account must exist, there is no guard code, this is 
*				cooperative programming, not defensive!
* Postcondition: the selected record will be deleted from the linked list 
*				
*********************************************************************************/

bool BankMain::deleteAccount ()
{
		// declare variables

	int theAccount = 0;
	Account *pPrev = NULL, *pCur = NULL;
	bool success = false;

		// prompt for the number of the account to delete

	cout << "Enter the number of the account you wish to delete: ";
	cin >> theAccount;
	cout << endl;

		// check if the record to be deleted is the first record:

	if ((pHead -> mNumber) == theAccount)
	{
			// set pCur to pHead, then set pHead to pHeads mpNext, 

		pCur = pHead;
		pHead = pHead -> mpNext;

			// and then delete pCur 

		delete pCur;
	}

	else // we are not at the beginning of the list
	{

			// set pCur to pHead to use for navigation
	
		pCur = pHead;
	
			// navigate to the correct node
	
		while (pCur -> mNumber != theAccount)
		{
			pPrev = pCur;
			pCur = pCur -> mpNext;
		} // end while loop to navigate to the correct node to remove
	
			// adjust pointers to prepare for removal:
	
		pPrev -> mpNext = pCur -> mpNext;
	
			// remove the node
	
		delete pCur;
	
	} // end else, not at beginning of list

		// update success flag
	success = true;

	return success;

} // end deleteAccount

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA5, Basic Bank Application in C++
* Date: 03/06/2015
* Function: creditAccount
* Description: This function adds funds to an account
* Precondition: The account must exist
* Postcondition: the user will be prompted for an account number and a 
*				deposit amount, that amount will be added to that accounts
*				balance.
*********************************************************************************/

bool BankMain::creditAccount ()
{
		// declare variables, need an account number and an amount

	int theAccount = 0, theDeposit = 0;
	Account *pCur = NULL;
	bool success = false;

		// set pCur to pHead for navigation purposes

	pCur = pHead;

		// prompt user for and read in necessary information

	cout << "Enter the account number: ";
	cin >> theAccount;
	cout << endl;
	cout << "Enter the amount of the deposit: ";
	cin >> theDeposit;
	cout << endl;

		// navigate to the correct Account:

	while (pCur -> mNumber != theAccount)
	{
		pCur = pCur -> mpNext;
	} // end while loop for navigation

		// Adjust the balance by the deposit amount

	pCur -> setBalance ((pCur -> mBalance) + theDeposit);

		// update the success flag

	success = true;

		// return success flag status

	return success;

} // end creditAccount

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA5, Basic Bank Application in C++
* Date: 03/06/2015
* Function: debitAccount
* Description: This function subtracts funds from an account
* Precondition: The account must exist
* Postcondition: the user will be prompted for an account number and a 
*				withdrawal amount, that amount will be subtracted from that
*				accounts balance.
*********************************************************************************/

bool BankMain::debitAccount ()
{
		// declare variables, need an account number and an amount

	int theAccount = 0, theDebit = 0;
	Account *pCur = NULL;
	bool success = false;

		// set pCur to pHead for navigation:

	pCur = pHead;

		// prompt user for and read in information

	cout << "Enter the account number: ";
	cin >> theAccount;
	cout << endl;
	cout << "Enter the amount of the debit: ";
	cin >> theDebit;
	cout << endl;

		// navigate to the correct Account:

	while (pCur -> mNumber != theAccount)
	{
		pCur = pCur -> mpNext;
	} // end while loop for navigation

		// check if there is sufficient funds, if so, perform the transaction

	if (pCur -> mBalance >= theDebit)
	{
			// Adjust the balance by the deposit amount

		pCur -> setBalance (pCur -> mBalance - theDebit);

			// update success flag

		success = true;

	} // end there is enough money

	else // there is insufficient funds
	{
		cout << "Insufficient funds to perform this transaction" << endl;
		cout << "Transaction Cancelled" << endl;
	} // end, there is not enough money, no need to update success flag, it's already false

		// return success status

	return success;
	
} // end debitAccount

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA5, Basic Bank Application in C++
* Date: 03/06/2015
* Function: displayAccounts
* Description: This function prints the information from all accounts in the 
*				linked list
* Precondition: Accounts must exist, this is cooperative, not defensive code
* Postcondition: The contents of each record will be printed to the screen 
*				
*********************************************************************************/

void BankMain::displayAccounts ()
{
		// declare a variable of type account to use for navigation:

	Account *pCur = NULL;
	
		// set pCur to pHead for navigation:

	pCur = pHead;

		// traverse the list and print the info as we go:

	while (pCur != NULL)
	{
			// use the nice formatting for easy readability:

		cout << "Account Name:       " << pCur -> mName    << endl;
		cout << "Account Number:     " << pCur -> mNumber  << endl;
		cout << "Account Balance:    " << pCur -> mBalance << endl;
		cout << "Account Start Date: " << pCur -> mDate    << endl;
		cout << endl;

			// advance to next node:

		pCur = pCur -> mpNext;

	} // end while loop to traverse and print

} // end displayAccounts