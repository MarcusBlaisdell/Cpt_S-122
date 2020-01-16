#ifndef BLAISDELL_PA3_H
#define BLAISDELL_PA3_H

#define _CRT_SECURE_NO_WARNINGS

	// include libraries

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

	// declare structs:

typedef struct stacknode
{
	char theElement;
	struct stacknode *theNextElement;
} StackNode;

	// Function prototypes

// make a new node
StackNode *makeNode (char theElement);

// get an expression from the user

void *getInput (char *infix);

// convert expression from infix to postfix
void convertNotation (StackNode **convertStack, char *inFix, char *postFix);

// push a node onto the intStack

void push (StackNode **theStack, char theExpression);

// pop a node from the stack

char pop (StackNode **theStack);

// print the contents of a stack

void printStack (StackNode *theStack);

// read the top of the stack

char stackTop (StackNode *convertStack);

// evaluate the post-fix expression

int evaluatePostFix (StackNode **convertStack, char *postfix);

// exponent function

int exponent (int number, int exponent);

#endif