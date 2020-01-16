#ifndef BANKMAIN_H
#define BANKMAIN_H

#include "Account.h"

	// class BankMain to handle main banking functions:

class BankMain
{
public:
	BankMain ();                      // default constructor
	BankMain (BankMain & copyObject); // copy constructor
	~BankMain ();                     // destructor

		// make node
	Account *makeNode (double balance, int number, string name, string date);

		// insert a new account
	bool insertNewAccount ();

		// delete an account
	bool deleteAccount ();

		// credit an account
	bool creditAccount ();

		// debit an account
	bool debitAccount ();

		// display all accounts
	void displayAccounts ();

private:
	int countAccounts; // not yet implemented!!
	Account *pHead;
};

#endif
