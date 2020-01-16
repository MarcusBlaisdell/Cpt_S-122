#ifndef BLAISDELL_PA4_H
#define BLAISDELL_PA4_H

	// suppress warnings
#define _CRT_SECURE_NO_WARNINGS

	// include necessary libraries

#include <stdio.h>
#include <stdlib.h>
#include <time.h> // for random numbers

	// declare structs

typedef struct queueNode
{
	int customerNumber;
	int serviceTime;
	int totalTime;
	struct queueNode *pNext;
} QueueNode;

typedef struct queue
{
	QueueNode *pHead;
	QueueNode *pTail;
} Queue;

	// declare function prototypes

// *makeNode
QueueNode *makeNode (int *customerNumberPtr, int lineId);

// enQueue
void enQueue (Queue **theQueue, int *customerNumberPtr, int lineId);

// deQueue
void deQueue (Queue **theQueue);

// isEmpty
int isEmpty (Queue *theQueue);

// printQueue
void printQueue (Queue *theQueue, int lineId);

// run the simulation
void runSimulation (Queue *theExpress, Queue *theNormal, int *customerNumberPtr);

// update Nodes
void updateNodes (Queue **theQueue);

#endif