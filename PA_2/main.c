/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA2 Digital Music Manager
* Date: 02/04/2015
* Description: This program performs the following:
* load/stores music records from text files in to / from linked lists
* allows the user to edit existing records, display selected records,
* delete selected records, change a song rating
**********************************************************************************/

#include "Blaisdell_PA2.c"

int main (void)
{
		// declare necessary variables:

	Node *pHead = NULL;
	int menuSelect = 0, exitFlag = 0;

			// do-while loop to make operation of music player continuous until user chooses to stop

	do
	{
			// main menu
		system ("cls");
		printf ("\n1) Load records\n");
		printf ("2) Store Records\n");
		printf ("3) Display Records (search records)\n");
		printf ("4) Insert new records\n");
		printf ("5) Delete Records\n");
		printf ("6) Edit Records\n");
		printf ("7) Rate songs\n");
		printf ("8) exit program\n");

			// get the input from the user:

		printf ("Enter a number from 1 to 8 : ");
		scanf (" %d", &menuSelect);

		// evaluate user input and choose the correct function

		switch (menuSelect)
		{
		case 1:
			loadRecords (&pHead); // load records from file to a linked list
			break;
		case 2:
			storeRecords (&pHead); // store records from linked list to file
			break;
		case 3:
			displayRecordsMenu (pHead); // go to the display records menu
			break;
		case 4:
			insertRecords (&pHead); // insert new records into the linked list
			break;
		case 5:
			deleteRecords (&pHead); // delete records from the linked list
			break;
		case 6:
			editRecords (&pHead); // edit existing records in the linked list
			break;
		case 7:
			rateRecords (&pHead); // change the rating of a song in the linkd list
		case 8:
			storeRecords (&pHead); // write the contents of the current linked list to a file and then:
			exitFlag = 1; // exit the program by setting exit flag to 1
			break;
		default:
			printf ("Please enter a number between 1 & 8\n");
			break;
		} // end switch function

	} while (exitFlag != 1); // exit if flag is set to 1, continue if 0

	return 0;
} // end main function
