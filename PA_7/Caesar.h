#ifndef CAESAR_H
#define CAESAR_H

#define _CRT_SECURE_NO_WARNINGS

#include "base.h"

// derive from base class:

class Caesar : public Base
{
public:
	// default constructor:
	Caesar ();
	// destructor:
	~Caesar ();

	// unique functions:
	void encode           (Caesar *theCaesar);
	void decodeWithKey    (Caesar *theCaesar);
	void decodeBruteForce (Caesar *theCaesar);

	// getters:
	string getMessage (void);

	// setters
	void setMessage (string theMessage);

private:
	int mKey;
};

#endif