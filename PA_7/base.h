#ifndef BASE_H
#define BASE_H

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

	// define the Base class:

class Base
{
public:
	// default constructor:
	Base ();
	// copy constructor:
	Base (Base &copyObject);
	// destructor:
	~Base ();

	// overloaded assignment operator:
	Base & operator = (Base &rhs);

	// functions:
	void encode (void);
	void decode (void);

	// getters
	string getMessage ();

protected:
	bool mCipher;
	string mMessage;
};

#endif