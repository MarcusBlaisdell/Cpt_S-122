#include "Blaisdell_PA3.h"

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment:
* Date: 02/16/2015
* Function: *makeNode
* Description: make a new node containing a single element of the expression
* Precondition: StackNode structure must be defined, "theElement" must be passed in as an argument
* Postcondition: a new node containing "theElement" as its data is created and returned
*********************************************************************************/
StackNode *makeNode (char theElement)
{
		// declare variables:

	StackNode *pMem = NULL;

		// initialize node with dynamic memory allocation

	pMem = (StackNode *) malloc (sizeof (StackNode));

		// load the data into the node and set it's pointer

	pMem -> theElement = theElement;
	pMem -> theNextElement = NULL;

	return pMem;

} // end *makeNode function

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment:
* Date: 02/16/2015
* Function: getInput
* Description: prompt the user for and read in a mathematical expression in 
*				infix notation to be converted to postfix notation
* Precondition: inFix must be declared
* Postcondition: inFix will be loaded with the infix expression
*********************************************************************************/

void *getInput (char *inFix)
{
		// prompt the user to enter a mathematical expression
	printf ("Enter a mathematical expression using infix notation: \n");
		
		// read the input from the user into the pointer passed in from the calling function

		// not sure why this doesn't work when I call this function from the 
		// switch-case function
	// gets (inFix); 

	scanf (" %s", inFix); // but this works just fine so I'm going with it

} // end getInput function

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment:
* Date: 02/16/2015
* Function: convertNotation
* Description: convert an infix expression to postfix notation
* Precondition: an infix notation expression entered by the user from getinput function, 
* passed in to the function via the inFix string pointer
* Postcondition: the expression in postfix notation form, postFix string is updated
*********************************************************************************/
void convertNotation (StackNode **convertStack, char *inFix, char *postFix)
{
		// declare necessary variables:

	int inFixIndex = 0, postFixIndex = 0;
	char temp = '\0';
		
		// begin by pushing a left paren onto the stack to note the end of the stack

	push (convertStack, '(');
		
		// append a right paren to the end of the infix notation array to note the end of the array

	inFix[strlen(inFix)] = ')';

		// while the stack is not empty, evaluate each character and perform the appropriate
		// action:

	while ((temp = stackTop (*convertStack)) != '\0')
	{
			// if the character at the current inFix index position is an integer, put it at 
			// the end of postFix

		if ((inFix[inFixIndex]) >= 48 && (inFix[inFixIndex] <= 57))
		{
			postFix[postFixIndex++] = inFix[inFixIndex++];
		} // end if integer
			
			// if the character at the current inFix index position is a left paren,
			// put it on the stack

		else if ((inFix[inFixIndex] == '('))
		{
			push (convertStack, inFix[inFixIndex++]);
		} // end if left paren

			// if operator is a high precedence, *, /, ^, or % and the operator on the stack is also
			// *, /, ^, or %

			// if the character at the current inFix index position is a *, /, ^, or %
			// operator, pop all operators from the top of the stack with equal precedence
			// and put them at the end of postFix, then put this one on the end of postFix

		else if (((inFix[inFixIndex] == '*') || (inFix[inFixIndex] == '/') || 
			(inFix[inFixIndex] == '^') || (inFix[inFixIndex] == '%')) &&
			((temp == '*') || (temp == '/') || (temp == '^') || (temp == '%')))
		{
			while ((temp == '*') || (temp == '/') || (temp == '^') || (temp == '%'))
			{
				temp = pop (convertStack);
				postFix[postFixIndex++] = temp;
				temp = stackTop (*convertStack);
			} // end keep popping from stack if equal or greater operator precedence (*, /, ^, %)

				// now put the current operator on the stack

			push (convertStack, inFix[inFixIndex++]);

		} // end if inFix[inFixIndex] is a *, /, ^, or % operator and last character on the stack is
		// also a *, /, ^, or % operator

			// if the operator is a + or a - and the operator on the stack is, well, anything,

		else if (((inFix[inFixIndex] == '+') || (inFix[inFixIndex] == '-')) &&
			((temp == '+') || (temp == '-') || 	(temp == '*') || (temp == '/') 
			|| (temp == '^') || (temp == '%')))
		{
				// while there is an operator on the top of the stack, keep going:

			while ((temp == '+') || (temp == '-') || (temp == '*') || 
				(temp == '/') || (temp == '^') || (temp == '%'))
			{
				temp = pop (convertStack);
				postFix[postFixIndex++] = temp;
				temp = stackTop (*convertStack);
			} // end keep popping from stack if equal or greater operator precedence (+, -, *, /, ^, %)
			push (convertStack, inFix[inFixIndex++]);
		} // end if inFix[inFixIndex] is a + or - operator and last character on the stack is
		// also a + or - or *, /, ^, or % operator
		
			// otherwise, the current operator is lower precedence than the one on the stack
			// so put it on the end of postFix

		else if (((inFix[inFixIndex] == '*') || (inFix[inFixIndex] == '/') || (inFix[inFixIndex] == '^') || 
			(inFix[inFixIndex] == '%') || (inFix[inFixIndex] == '+') || (inFix[inFixIndex] == '-')) && 
			((temp != '*') || (temp != '/') || (temp != '^') || (temp != '%') || (temp != '+') || 
			(temp != '-')))
		{
			push (convertStack, inFix[inFixIndex++]);
		} // end if operator is anything and there is no operator on the top of the stack


			// if inFix[inFixIndex] is a right paren:

		else if (inFix[inFixIndex] == ')')
		{
			while ((temp = stackTop (*convertStack)) != '(')
			{
				temp = pop (convertStack);
				postFix[postFixIndex++] = temp;
				temp = stackTop (*convertStack);
			} // end while not left paren
	
			if ((temp = stackTop (*convertStack)) == '(')
			{
				temp = pop (convertStack);
				temp = '\0';
				inFixIndex++;
			} // end pop and discard left paren if its at the top of the stack
		} // end if inFix[inFixIndex] is right paren ')'

	} // end while loop for converting

} // end convertNotation function

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment:
* Date: 02/16/2015
* Function: push
* Description: push a character onto the stack
* Precondition: theStack must be created and initialized
* Postcondition: the new character will be on the top of the stack
*********************************************************************************/
void push (StackNode **theStack, char theElement)
{
	StackNode *element = makeNode (theElement);

	element -> theNextElement = *theStack;
	*theStack = element;

} // end push function

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment:
* Date: 02/16/2015
* Function: pop
* Description: Removes the top element from the stack and returns it to the calling function
* Precondition: a character variable must be decalared to hold the result of the function
* theStack must exist and be initialized and must not be empty!
* Postcondition: the top element of the stack will be deleted and it's value returned
* to the calling function.
*********************************************************************************/
char pop (StackNode **theStack)
{
		// decalare necessary variables:

	StackNode *pTemp = NULL;
	char temp = '\0';

		// move the node to a temp node, move the pointer to the first node to the next node
		
	pTemp = *theStack;
	*theStack = (*theStack) -> theNextElement;

		// put the value of the top node into a temp variable

	temp = pTemp -> theElement;

		// free the temp node

	free (pTemp);

		// return the value of the character that was in the top node 

	return temp;

} // end pop function

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment:
* Date: 02/16/2015
* Function: printStack
* Description: Prints all of the values in the stack, I used this for debugging
* Precondition: The stack must be declared and initialized and not empty
* Postcondition: the contents of the stack will be printed to the screen
*********************************************************************************/
void printStack (StackNode *theStack)
{
		// use while nodes in stack are not null

	while (theStack != NULL)
	{
		printf ("%c", theStack -> theElement);
		theStack = theStack -> theNextElement;
	} // end while loop
	
		// put a newline for readability

	putchar ('\n');

} // end printStack function

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment:
* Date: 02/16/2015
* Function: stackTop
* Description: returns the value of the data in the top node of the stack
* Precondition: stack must be declared, initialized
* Postcondition: the value of the data in the node at the top of the stack is
* returned to the calling function.
*********************************************************************************/
char stackTop (StackNode *convertStack)
{
		// declare a temp variable
	char temp = '\0';

		// if the stack is not empty, store the value of the top node
	if (convertStack != NULL)
	{
		temp = convertStack -> theElement;
	}

		// return the value to the calling function

	return temp;
} // end stackTop function

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment:
* Date: 02/16/2015
* Function: evaluatePostFix
* Description: Evaluates the postFix notation expression
* Precondition: postFix array must exist and not be empty, convert stack must exist
* Postcondition: the value of the evaluated expression will be left in the top node
* of the convertStack and stored as an integer and returned to the calling function
*********************************************************************************/
int evaluatePostFix (StackNode **convertStack, char *postFix)
{
		// declare variables:

	int postFixIndex = 0, x = 0, y = 0, z = 0, theAnswer;
	char theOperator = '\0';

		// append \0 to end of postFix array to make it a string

	postFix[strlen(postFix)] = '\0';

		// while the string position is not null character

	while (postFix[postFixIndex] != '\0')
	{
			// if current character is an integer, put it on the stack:

		if ((postFix[postFixIndex] >= 48) && (postFix[postFixIndex] <= 57))
		{
			push (convertStack, postFix[postFixIndex++]);
		} // end if postFix[postFixIndex] is an integer

			// if current character is a operator, pop previous two integers into variables x & y
			// and evaluate x operator y and put the result back on the stack
		if ((postFix[postFixIndex] == '*') || (postFix[postFixIndex] == '/')
			|| (postFix[postFixIndex] == '^') || (postFix[postFixIndex] == '%') || 
			(postFix[postFixIndex] == '+') || (postFix[postFixIndex] == '-'))
		{
				// store previous two integers in temp variables as integers 
				// (convert from ascii characters to ascii integers by lowering
				// ascii value by 48)

			x = pop (convertStack) - 48;
			y = pop (convertStack) - 48;
				
				// put the operator into a variable we can work with:
				
			theOperator = postFix[postFixIndex];

				// use switch case to evaluate the expressions

			switch (theOperator)
			{
			case '+':
				z = y + x;
				break;
			case '-':
				z = y - x;
				break;
			case '*':
				z = y * x;
				break;
			case '/':
				z = y / x;
				break;
			case '^':
				z = exponent(y,x); // use custom exponent funtion
				break;
			case '%':
				z  = y % x;
				break;
			default:
				printf ("Invalid character\n");
				break;
			}
			
				// push the answer onto the stack
			push (convertStack, z + 48);

			postFixIndex++; // increment the index

		} // end if postFix[postFixIndex] is an operator

	} // end while postFix[postFixIndex] != 0
	
	theAnswer = pop (convertStack) - 48;

	return theAnswer;

} // end evaluatePostFix function

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment:
* Date: 02/16/2015
* Function: exponent
* Description: raises a number to a power
* Precondition: the number and the power must be passed in as variables
* Postcondition: the calculated value is returned as an integer
*********************************************************************************/
int exponent (int number, int exponent)
{
		// declare necessary variables;

	int loop = 0, answer = number;

		// loop as many times as the value of the exponent
		// multiply the answer by the number that many times

	for (loop = 0; loop < exponent; loop++)
	{
		answer = answer * number;
	}

	return answer;
} // end exponent function