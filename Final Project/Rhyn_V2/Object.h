#ifndef OBJECT_H
#define OBJECT_H

#define _CRT_SECURE_NO_WARNINGS

#include "SFML\Graphics.hpp"
#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

class Object
{
public:
		// default constructor
	Object ();

		// initialized constructor 1
	Object (int theTop, int theHeight, int theLeft, int theWidth);

		// initialized constructor 2
	Object (sf::IntRect &theLocation);

		// copy constructor
	Object (Object &copyObject);

		// destructor
	~Object ();

		// overloaded assignment operator
	Object &operator = (Object &rhs);
	
private:
	sf::IntRect mLocation;
};

#endif