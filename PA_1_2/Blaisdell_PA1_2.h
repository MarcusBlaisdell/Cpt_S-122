#ifndef BLAISDELL_PA1_2
#define BLAISDELL_PA1_2

#define _CRT_SECURE_NO_WARNINGS

// include libraries
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// function prototypes
// primary function that handles everything
void isPalindrome (char *theString);
// removePunct, remove punctuation, spaces, etc., anything that isn't an alpha character
void removePunct (char *theString);
// evaluate the string using recursion
int recursiveEvaluate (char *theString, int beginIndex, int endIndex);

// test driver functions
void testDriver (char *theString);

#endif