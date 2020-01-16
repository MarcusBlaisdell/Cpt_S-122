#include "Blaisdell_PA4.h"

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA 4
* Date: 02/25/2015
* Function: *makeNode
* Description: this function takes a pointer to a customer number variable
*				and creates a new node for it
* Precondition: customerNumber variable must exist and be initialized, pointer to 
*				customerNumber must exist and be passed in as an argument, 
*				struct QueueNode type must exist
* Postcondition: A new node with the customer number will be created, the 
*				service time associated with this node will be assigned as a 
*				random number based on the line the node is being created for
*********************************************************************************/

QueueNode *makeNode (int *customerNumberPtr, int lineId)
{
		// declare a new node:

	QueueNode *pMem = NULL;

		// allocate memory for it:

	pMem = (QueueNode *) malloc (sizeof (QueueNode));

		// initialize the new node:

	pMem -> customerNumber = (*customerNumberPtr)++; // customer number is running total, use pointer to track
	
		// assign service time based on which line the node is being created for:

	if (lineId == 1)
	{
		pMem -> serviceTime = ((rand() % 5) + 1); // rand % 5 returns 0 - 4, I need 1 - 5 so I add 1 to value
	}
	else
	{
			pMem -> serviceTime = ((rand() % 6) + 3); // rand % 6 returns 0 - 5, I need 3 - 8 so I add 3 to value
	}

	pMem -> totalTime = 0; // initialize total time to zero
	pMem -> pNext = NULL;

		// return new node to the calling function

	return pMem;

} // end *makeNode function

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA 4
* Date: 02/25/2015
* Function: enQueue
* Description: This function adds a new node to a specified Queue
* Precondition: the Queue to be updated must exist, customer number must exist,
*				customer Number pointer must exist, the line ID number must be 
*				passed in as an argument
* Postcondition: The new node will be placed at the tail of the appropriate
*				Queue.
*				
*********************************************************************************/

void enQueue (Queue **theQueue, int *customerNumberPtr, int lineId)
{
		// declare variables:

	QueueNode *pMem = NULL, *pPrev = NULL, *pCur = NULL;

		// initialize the new node:

	pMem = makeNode (customerNumberPtr, lineId);

		// check if the queue is empty

	if (isEmpty ((*theQueue)) == 0)
	{
			// if it's empty, insert at head and set tail pointer to same node
		(*theQueue) -> pHead = pMem;
		(*theQueue) -> pTail = pMem;
	} // end if empty
	else // if it's not empty, insert at tail
	{
		(*theQueue) -> pTail -> pNext = pMem;
		(*theQueue) -> pTail = pMem;
	} // end if not empty


		// format the header appropriately for the line we are adding to:

	if (lineId == 1)
	{
		printf ("New customer in the Express line: ");
	}
	else 
	{
		printf ("New customer in the Normal line: ");
	}

		// print the data about the node we just added:

	printf ("Customer #: %d\n", (*theQueue) -> pTail -> customerNumber);
	printf ("Service Time: %d\n", (*theQueue) -> pTail -> serviceTime);

} // end enqueue function

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA 4
* Date: 02/25/2015
* Function: deQueue
* Description: This function removes a node from the head of the queue
* Precondition: The queue must exist and must not be empty
*				This function only gets called after an evaluation of the 
*				node so it will not get called if the queue is empty
* Postcondition: The head node will be removed and memory will be returned to 
*				the system as available
*				
*********************************************************************************/

void deQueue (Queue **theQueue)
{
		// declare variables:

	QueueNode *pTemp = NULL;

		// check if this is the only node, if it is, remove it appropriately:

	if ((*theQueue) -> pHead == (*theQueue) -> pTail)
	{
		pTemp = (*theQueue) -> pHead;
		free (pTemp);
		(*theQueue) -> pHead = NULL;
		(*theQueue) -> pTail = NULL;
	}
	else // if it is not the only node, remove the head node appropriately
	{
		pTemp = (*theQueue) -> pHead;
		(*theQueue) -> pHead = (*theQueue) -> pHead -> pNext;
		free (pTemp);
	}
} // end deQueue function

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA 4
* Date: 02/25/2015
* Function: runSimulation
* Description: This is the function that controls all of the program action
*				
* Precondition: Queues for the express line and the normal line must exist, 
*				customer number and customer number pointer must exist,
*				
* Postcondition: The simulation will be run, conditions will be evaluated and
*				actions will be taken
*				
*********************************************************************************/

void runSimulation (Queue *theExpress, Queue *theNormal, int *customerNumberPtr)
{
		// declare variables:

	int expressTime = 0, normalTime = 0, masterClock = 0, runTime = 0;

		// initialize expressTime and normalTime to appropriate random numbers

	expressTime = (rand () % 5 + 1);
	normalTime = (rand () % 6 + 3);

		// get run time from user (in minutes)

	printf ("Enter a time interval in minutes for this simulation to fun for: "); // yeah, me talk english good, change this!!
	scanf ("%d", &runTime); // Matt said he doesn't like scanf, try this with gets

		/* This is the heart of this function, the master clock.
		   This for loop runs until the clock reaches the user specified
		   maximum run time.
		   Inside this, we:
		      - print the contents of each queue every ten minutes,
		      - evaluate each minute if the line has customers and if so, updates the stats on 
			     each node in that queue
			  - evaluate if a new customer has entered the line, if so, print that info to the screen
			  - evaluate if a customer has left a line, if so, print that info to the screen
			  - if no customer has entered the line and no customers are currently in line, we 
			     decrement the variables that control when a customer enters a line
		*/

	for (masterClock = 0; masterClock < runTime; masterClock++)
	{
			// if masterClock mod 10 == 0 then we are at a ten minute interval, time to print the queues

		if ((masterClock != 0) && (masterClock % 10 == 0))
		{
				// if the express queue is not empty, print it out
			if (isEmpty (theExpress) == 1)
			{
				printQueue (theExpress, 1);
			}
			else
			{
				printf ("\n\nThe express line is currently empty\n\n");
			}
				// if the normal queue is not empty, print it out
			if (isEmpty (theNormal) != 0)
			{
				printQueue (theNormal, 2);
			}
			else
			{
				printf ("\n\nThe normal line is currently empty\n\n");
			}
		} // end print contents of each queue every ten minutes

			// if we reach 24 hours, reset the customer number back to 1:

		if (masterClock == 1440)
		{
			*customerNumberPtr = 1;
		} // end reset customer number back to 1 after 24 hours

			// if there is data in a queue, update all of the nodes in that queue

		if (isEmpty (theExpress) != 0)
		{
			updateNodes (&theExpress);

			if (theExpress -> pHead -> serviceTime == 0)
			{
				printf ("Customer has left the Express line: ");
				printf ("Customer #: %d : ", theExpress -> pHead -> customerNumber);
				printf ("Total Time in line: %d\n", theExpress -> pHead -> totalTime);
				deQueue (&theExpress);
			} // end if service time is now zero, initiate a dequeue
		} // end if normal queue is not empty, update all of its nodes

		if (isEmpty(theNormal) != 0)
		{
			updateNodes (&theNormal);

			if (theNormal -> pHead -> serviceTime == 0)
			{
				printf ("Customer has left the Normal line: ");
				printf ("Customer #: %d :", theNormal -> pHead -> customerNumber);
				printf ("Total Time in line: %d\n", theNormal -> pHead -> totalTime);
				deQueue (&theNormal);
			} // end if service time is now zero, initiate a dequeue
		} // end if normal queue is not empty, update all of its nodes

			// if there is nobody in line, evaluate the line variables to see if 
			// we need to put someone in line or decrement the time until we need
			// to put someone in line:

		if (expressTime == 0)
		{
			enQueue (&theExpress, customerNumberPtr, 1);
			expressTime = (rand () % 5 + 1);
		}
		else
		{
			expressTime--; // decrement the express clock
		}
		if (normalTime == 0)
		{
			enQueue(&theNormal, customerNumberPtr, 2);
			normalTime = (rand () % 6 + 3);
		}
		else
		{
			normalTime--; // decrement the normal clock
		}
	} // end for loop to run simulation for user specified n minutes

} // end runSimulation function

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA 4
* Date: 02/25/2015
* Function: updateNodes
* Description: This function updates the variables in each node in a queue
*				
* Precondition: The queue must exist and must not be empty though this function 
*				will only get called if there is data in a queue so we don't need
*				to check if it's empty
* Postcondition: for each node in the queue, the service time will decrement by 1,
*				the total time in line will increment by 1
*				
*********************************************************************************/


void updateNodes (Queue **theQueue)
{
		// declare variables:

	QueueNode *pMem = (*theQueue) -> pHead;

		// loop through the queue until each node has been updated:

	while (pMem != NULL)
	{
		pMem -> serviceTime--; // decrement service time
		pMem -> totalTime++; // increment total time in line
		pMem = pMem -> pNext; // advance to next node
	}

} // end updateNodes function

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA 4
* Date: 02/25/2015
* Function: printQueue
* Description: this function prints the data in all of the nodes in a queue
*				
* Precondition: the queue must exist but this function will only get called if 
*				a queue has data so no need to check, accepts as an argument the
*				id of the line to display information correctly
* Postcondition: All of the pertinent data from each node is printed to the screen
*				
*				
*********************************************************************************/

void printQueue (Queue *theQueue, int lineId)
{
		// use line ID to format the text appropriately

	if (lineId == 1)
	{
		printf ("\n\nExpress Line: ");
	}
	else
	{
		printf ("\n\nNormal Line: ");
	}

	printf ("Current Queue: ");

		// print the contents of each node of the queue

	while (isEmpty (theQueue) != 0)
	{
		printf ("Customer #: %d : ", theQueue -> pHead -> customerNumber);
		printf ("Remaining service time: %d : ", theQueue -> pHead -> serviceTime);
		printf ("Total Time in line: %d -> ", theQueue -> pHead -> totalTime);

		theQueue -> pHead = theQueue -> pHead -> pNext; // advance to the next node
	}

	printf ("\nEnd Current Queue\n\n");

} // end printQueue function

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA 4
* Date: 02/25/2015
* Function: isEmpty
* Description: This function evaluates whether or not a queue is empty
*				
* Precondition: the queue must exist,
* Postcondition: If the queue is empty, it returns a zero, if it is not empty,
*				it returns a one
*				
*********************************************************************************/

int isEmpty (Queue *theQueue)
{
		// declare a flag variable

	int isIt = 0;

		// evaluate if the queue head is pointing to anything, if not, it is empty
		// if so, it is not empty and the flag will be updated.

	if (theQueue -> pHead != NULL)
	{
		isIt = 1;
	}

	return isIt;
} // end isEmpty function