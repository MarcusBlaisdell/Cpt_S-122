/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA4
* Date: 02/25/2015
* Description: This program performs the following:
* This is a grocery store line simulator
* This program models two lines at a grocery store, one express line, one
* normal line. It uses random variables to place customers in line and
* simulates how long they will be in line.
*
**********************************************************************************/

#include "Blaisdell_PA4.c"

int main (void)
{
		// declare variables:

	int mainClock = 0, customerNumber = 1, *customerNumberPtr, emptyOrNot = 0;
	Queue theExpress = {NULL, NULL}, theNormal = {NULL, NULL}; // using Andy's method

		// use a pointer to customer number to keep a running increment
		// that can be accessed by all functions:

	customerNumberPtr = &customerNumber;

		// seed the random variable using the system clock

	srand ((unsigned int) time (NULL));

		// run the simulation:

	runSimulation (&theExpress, &theNormal, customerNumberPtr);

	return 0;
}
