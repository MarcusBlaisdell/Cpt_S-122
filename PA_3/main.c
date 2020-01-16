/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA3
* Date: 02/11/2015
* Description: This program performs the following:
* Converts math expressions from infix to postfix and then evaluates the postfix
* expression
*
**********************************************************************************/

#include "Blaisdell_PA3.c"

int main (void)
{
	// declare necessary variables
	int theAnswer = 0, menuSelection = 0;
	char inFix[100] = "", postFix[100] = "";
	StackNode *convertStack = NULL;

		// use a menu to test / run the program:

	system ("cls"); // clear the screen to make it readable

		// use do-while loop

	do
	{
			// print the menu

		printf ("\n\n1) Get input from the user and convert an infix expression to postfix\n");
		printf ("   then evaluate the postfix expression\n");
		printf ("2) Use pre-determined function \"9*(5-4)+2/6\" to evaluate the program\n");
		printf ("3) Use pre-determined function \"(6+2)*5-8/4\" to evaluate the program\n");
		printf ("4) Quit\n");
		printf ("Enter a choice between 1 & 4 : ");

			// get input from user
		scanf ("%d", &menuSelection);

			// use switch case to perform requested actions:

		switch (menuSelection)
		{
		case 1:
			getInput (inFix);
			printf ("theExpression: \"%s\"\n", inFix);
			convertNotation (&convertStack, inFix, postFix);
			printf ("postFix: \"%s\"\n", postFix);
			theAnswer = evaluatePostFix (&convertStack, postFix);
			printf ("The answer is: %d\n", theAnswer);
			break;
		case 2:
			strcpy (inFix, "9*(5-4)+2/6");
			printf ("theExpression: \"%s\"\n", inFix);
			convertNotation (&convertStack, inFix, postFix);
			printf ("postFix: \"%s\"\n", postFix);
			theAnswer = evaluatePostFix (&convertStack, postFix);
			printf ("The answer is: %d\n", theAnswer);
			break;
		case 3:
			strcpy (inFix, "(6+2)*5-8/4");
			printf ("theExpression: \"%s\"\n", inFix);
			convertNotation (&convertStack, inFix, postFix);
			printf ("postFix: \"%s\"\n", postFix);
			theAnswer = evaluatePostFix (&convertStack, postFix);
			printf ("The answer is: %d\n", theAnswer);
			break;
		case 4:
			printf ("Thank you!\n");
			break;
		default:
			printf ("Please enter a valid number between 1 & 4\n");
		} // end switch case function

	} while ((menuSelection != 4));

	return 0;
}
