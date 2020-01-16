#ifndef BLAISDELL_PA1_3_H
#define BLAISDELL_PA1_3_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h> // for toupper()

// function prototypes

// encrypt function
void encrypt (char *theString, int shift);
// get String function
void getString (char *theString);
// get the shift level
int getShiftLevel (int shift);
// use a master function to get stuff out of main
void masterFunction (void);

// test driver function
void testDriverFunction (void);

#endif