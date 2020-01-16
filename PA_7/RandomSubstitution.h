#ifndef RANDOMSUBSTITUTION_H
#define RANDOMSUBSTITUTION_H

#define _CRT_SECURE_NO_WARNINGS

#include "Caesar.h"
#include <stdio.h>
#include <time.h>

// derive from base class:

class RandomSubstitution : public Base
{
public:
	// default constructor:
	RandomSubstitution ();
	// destructor:
	~RandomSubstitution ();

	// functions:
	void encode                  (RandomSubstitution *theRandomSubstitution);
	void decodeWithKey           (RandomSubstitution *theRandomSubstitution);
	void decodeFrequencyAnalysis (RandomSubstitution *theRandomSubstitution);

	// getters
	string getMessage ();

	// setters
	void setMessage (string theMessage);
	void setKey     (char theKey[2][27]);

private:
	char mKey[2][27];
};

#endif