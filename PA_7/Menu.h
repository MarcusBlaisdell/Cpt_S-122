#ifndef MENU_H
#define MENU_H

#define _CRT_SECURE_NO_WARNINGS

#include "RandomSubstitution.h"

class Menu
{
public:
	// default constructor:
	Menu ();
	// copy constructor:
	Menu (Menu &copyObject);
	// destructor:
	~Menu ();

	// functions:
	void mainMenu  (void);
	void subCaesar (Caesar *theCaesar);
	void subRandom (RandomSubstitution *theRandomSubstitution);

private:
	// this class has no private members
};

#endif