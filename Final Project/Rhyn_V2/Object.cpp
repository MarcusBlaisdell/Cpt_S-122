#include "Object.h"

// default constructor
Object::Object ()
{
	this->mLocation.top    = 0;
	this->mLocation.left   = 0;
	this->mLocation.height = 0;
	this->mLocation.width  = 0;
} // end Object default constructor

// initialized constructor 1
Object::Object (int theTop, int theHeight, int theLeft, int theWidth)
{
	this->mLocation.top    = theTop;
	this->mLocation.height = theHeight;
	this->mLocation.left   = theLeft;
	this->mLocation.width  = theWidth;
} // end Object initialized constructor

// initialized constructor 2
Object::Object (sf::IntRect &theLocation)
{
	this->mLocation.top    = theLocation.top;
	this->mLocation.height = theLocation.height;
	this->mLocation.left   = theLocation.left;
	this->mLocation.width  = theLocation.width;
} // end Object initialized constructor 2

// copy constructor
Object::Object (Object &copyObject)
{
	this->mLocation.top    = copyObject.mLocation.top;
	this->mLocation.height = copyObject.mLocation.height;
	this->mLocation.left   = copyObject.mLocation.left;
	this->mLocation.width  = copyObject.mLocation.width;
} // end Object copy constructor

// destructor
Object::~Object ()
{
	cout << "Object Destructor called" << endl;
} // end Object destructor

// overloaded assignment operator
Object & Object::operator = (Object &rhs)
{
	this->mLocation.top    = rhs.mLocation.top;
	this->mLocation.height = rhs.mLocation.height;
	this->mLocation.left   = rhs.mLocation.left;
	this->mLocation.width  = rhs.mLocation.width;

	return *this;
} // end overloaded assignment operator