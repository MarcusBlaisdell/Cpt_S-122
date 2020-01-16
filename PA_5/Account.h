#ifndef BLAISDELL_PA5_H
#define BLAISDELL_PA5_H

#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <string>

	// use the standard cin, cout, endl and string operators:

using std::cin;
using std::cout;
using std::endl;
using std::string;

	// declare the class:

class Account
{
		// give the main banking function access to the Account private data members

	friend class BankMain;

public:
		// default constructor
	Account  ();
		// with arguments constructor
	Account  (double newBalance, int newNumber, string newName, string newDate); 
		// copy constructor
	Account  (Account &copyAccount);
		// destructor
	~Account ();

		// getters (accessors)

	double  getBalance  () const;
	int     getNumber   () const;
	string  getName     () const;
	string  getDate     () const;
	Account &getmpNext  () const;

		// setters (mutators)

	void setBalance (double newBalance);
	void setNumber  (int newNumber);
	void setName    (string newName);
	void setDate    (string newDate);

private:
	double  mBalance; // account balance
	int     mNumber;  // account number
	string  mName;    // name on account
	string  mDate;    // date acccount was opened
	Account *mpNext;  // pointer to next account (node)
};

#endif