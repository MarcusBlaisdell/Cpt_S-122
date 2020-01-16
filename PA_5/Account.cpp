#include "Account.h"

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA5, Basic Bank Application in C++
* Date: 03/06/2015
* Function: Default Constructor
* Description: This will create an empty account if no information is passed in.
* Precondition: The function must be called with no arguments
* Postcondition: a blank record will be created and an error message will be 
*				displayed to the user.
*********************************************************************************/

Account::Account ()
{
		// create a blank account

	mBalance = 0;
	mNumber  = 0;
	mName    = "None";
	mDate    = "None";

		// scold the user

	cout << "You have not provided any information. A blank record has been created." << endl;
}

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA5, Basic Bank Application in C++
* Date: 03/06/2015
* Function: Account constructor for passed in arguments
* Description: This function creates a new object with the passed in values
* Precondition: values must be passed in as arguments
* Postcondition: A new bank record will be created with the new information
*********************************************************************************/

Account::Account  (double newBalance, int newNumber, string newName, string newDate)
{
		// Check if balance is zero
	if (newBalance == 0)
	{
		cout << "Error: You have created an account with no money." << endl;
	}

		// use the passed in arguments to create a new account

	mBalance = newBalance;
	mNumber  = newNumber;
	mName    = newName;
	mDate    = newDate;
	mpNext   = NULL;
}

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA5, Basic Bank Application in C++
* Date: 03/06/2015
* Function: Account copy constructor
* Description: This function copies all of the variables of the object that is 
*				passed in by reference to the new object.
* Precondition: An object must exist to be copied
* Postcondition: A new object will be created that contains all of the information
*				of the other object.
*********************************************************************************/

Account::Account  (Account &copyAccount)
{
		// copy all variables of the passed in by reference object into the new object:

	this->mBalance = copyAccount.mBalance;
	this->mNumber  = copyAccount.mNumber;
	this->mName	   = copyAccount.mName;
	this->mDate    = copyAccount.mDate;
	this->mpNext   = NULL;
}

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA5, Basic Bank Application in C++
* Date: 03/06/2015
* Function: ~Account (Destructor)
* Description: This function gets called when an Account object is destroyed
* Precondition: An Account class object must have been created and is no longer needed
* Postcondition: The object will be removed
*********************************************************************************/

Account::~Account ()
{
	// Nothing goes in here
	// cout << "Destructor was called" << endl;
}

	// Getters:

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA5, Basic Bank Application in C++
* Date: 03/06/2015
* Function: getBalance getter
* Description: Accesses the private data members of class Accounts and returns 
*				the value of mBalance.
* Precondition: The function must be called with no arguments, the account
*				must exist, cooperative programming, not defensive!
* Postcondition: the value of mBalance for the selected Account will be returned 
*				
*********************************************************************************/

double Account::getBalance () const
{
	return mBalance;
} // end getBalance accessor

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA5, Basic Bank Application in C++
* Date: 03/06/2015
* Function: getNumber getter
* Description: Accesses the private data members of class Accounts and returns 
*				the value of mNumber (the account number).
* Precondition: The function must be called with no arguments, the account
*				must exist, cooperative programming, not defensive!
* Postcondition: the value of mNumber for the selected Account will be returned 
*
*********************************************************************************/

int Account::getNumber () const
{
	return mNumber;
} // end getNumber accessor

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA5, Basic Bank Application in C++
* Date: 03/06/2015
* Function: getName getter
* Description: Accesses the private data members of class Accounts and returns 
*				the value of mName
* Precondition: The function must be called with no arguments, the account
*				must exist, cooperative programming, not defensive!
* Postcondition: the value of mName for the selected Account will be returned 
*
*********************************************************************************/

string Account::getName  () const
{
	return mName;
} // end getName accessor

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA5, Basic Bank Application in C++
* Date: 03/06/2015
* Function: getDate getter
* Description: Accesses the private data members of class Accounts and returns 
*				the value of mDate (the date the account was opened).
* Precondition: The function must be called with no arguments, the account
*				must exist, cooperative programming, not defensive!
* Postcondition: the value of mDate for the selected Account will be returned 
*
*********************************************************************************/

string Account::getDate () const
{
	return mDate;
} // end getDate accessor

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA5, Basic Bank Application in C++
* Date: 03/06/2015
* Function: getmpNext getter
* Description: Accesses the private data members of class Accounts and returns 
*				the value of mpNext
* Precondition: The function must be called with no arguments, the account
*				must exist, cooperative programming, not defensive!
* Postcondition: the value of mpNext for the selected Account will be returned 
*
*********************************************************************************/

Account & Account::getmpNext () const
{
	return *mpNext;
} // end getmpNext accessor

	// Setters:

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA5, Basic Bank Application in C++
* Date: 03/06/2015
* Function: setBalance setter
* Description: Accesses the private data members of class Accounts and updates 
*				the value of mBalance
* Precondition: The function must be called with arguments, the value of mBalance
*				must be passed in as an argument. The account
*				must exist, cooperative programming, not defensive!
* Postcondition: the value of mBalance for the selected Account will be updated 
*
*********************************************************************************/

void Account::setBalance (double newBalance)
{
	mBalance = newBalance;
} // end setBalance mutator

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA5, Basic Bank Application in C++
* Date: 03/06/2015
* Function: setNumber setter
* Description: Accesses the private data members of class Accounts and updates 
*				the value of mNumber (the Account number)
* Precondition: The function must be called with arguments, the value of mNumber
*				must be passed in as an argument. The account
*				must exist, cooperative programming, not defensive!
* Postcondition: the value of mNumber for the selected Account will be updated 
*
*********************************************************************************/

void Account::setNumber (int newNumber)
{
	mNumber = newNumber;
} // end setNumber mutator

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA5, Basic Bank Application in C++
* Date: 03/06/2015
* Function: setName setter
* Description: Accesses the private data members of class Accounts and updates 
*				the value of mName
* Precondition: The function must be called with arguments, the value of mName
*				must be passed in as an argument. The account
*				must exist, cooperative programming, not defensive!
* Postcondition: the value of mName for the selected Account will be updated 
*
*********************************************************************************/

void Account::setName (string newName)
{
	mName = newName;
} // end setName mutator

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA5, Basic Bank Application in C++
* Date: 03/06/2015
* Function: setDate setter
* Description: Accesses the private data members of class Accounts and updates 
*				the value of mDate
* Precondition: The function must be called with arguments, the value of mDate
*				must be passed in as an argument. The account
*				must exist, cooperative programming, not defensive!
* Postcondition: the value of mDate for the selected Account will be updated 
*
*********************************************************************************/

void Account::setDate (string newDate)
{
	mDate = newDate;
} // end mDate mutator