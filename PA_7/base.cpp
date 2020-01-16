#include "base.h"

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA7
* Date: 04/10/2015
* Function: Base default constructor
* Description: gets called when Base object is instantiated
* Precondition: base class must be instantiated from somewhere
* Postcondition: an instantiation of the base class will exist
*
*********************************************************************************/

Base::Base ()
{
	cout << "Base default constructor called" << endl;
} // end Base default constructor

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA7
* Date: 04/10/2015
* Function: Base class copy constructor
* Description: tells the system how to properly copy this object
* Precondition: Base class must be being copied 
* Postcondition: a copy of the Base class will be created with the data 
* properly assigned
*
*********************************************************************************/

Base::Base (Base &copyObject)
{
	this -> mCipher = copyObject.mCipher;
	this -> mMessage = copyObject.mMessage;
} // end copy constructor

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA7
* Date: 04/10/2015
* Function: Base class destructor
* Description: called when Base class goes out of scope, 
* Precondition: An instantiation of base class must go out of scope
* Postcondition: currently a message is displayed, if dynamic memory is 
* allocated, we will delete it here
*
*********************************************************************************/

Base::~Base ()
{
	cout << "Base destructor called" << endl;
} // end Base destructor

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA7
* Date: 04/10/2015
* Function: Base class overloaded assignment operator
* Description: tells the system how to handle assignment operators for this class
* Precondition: an instantiation of the Base class must be getting assigned to 
* something
* Postcondition: the data will be properly assigned to the new variable
*
*********************************************************************************/

Base & Base::operator = (Base &rhs)
{
	this -> mCipher = rhs.mCipher;
	this -> mMessage = rhs.mMessage;

	return *this;
} // end overloaded assignment operator

	// functions:

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA7
* Date: 04/10/2015
* Function: encode
* Description:  currently not being used, only displays a message, if we were to
* use this, we would have to define how to encode the information
* Precondition: must be called from some instantiation of the Base class
* Postcondition: a message is displayed to the screen
*
*********************************************************************************/

void encode (void)
{
	cout << "Base class encode function called" << endl;
} // end encode function

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA7
* Date: 04/10/2015
* Function: decode
* Description: currently not being used, only displays a message, if we were to
* use this, we would have to define how to decode the information
* Precondition: must be caled from an instantiation of the Base clss
* Postcondition: displays a message to the screeen
*
*********************************************************************************/

void decode (void)
{
	cout << "Base class decode function called" << endl;
} // end decode function

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA7
* Date: 04/10/2015
* Function: getMessage
* Description: Getter for private member mMessage
* Precondition: There must be an instantiation of the Base class
* Postcondition: The value of mMessage will be returned to the calling function
*
*********************************************************************************/

string Base::getMessage ()
{
	return mMessage;
}