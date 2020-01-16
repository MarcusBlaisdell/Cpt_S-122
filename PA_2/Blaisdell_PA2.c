#include "Blaisdell_PA2.h"

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment:
* Date: mm/dd/2015
* Function: makeNode
* Description: make a new Node
* Precondition: must be called from another function that has already declared a 
*				Node type variable, the data to be placed in the node must be 
*				passed in as a parameter
* Postcondition: Returns a pointer to a Node with the parameter data stored in it
*********************************************************************************/

Node *makeNode (Record newEntry)
{
	// declare a new node
	Node *pMem = NULL;

	// allocate dynamic memory for pMem
	pMem = (Node *) malloc (sizeof(Node));

	// if pMem was created successfully, assign values to pMem:

		pMem -> entry = newEntry;
		pMem -> pNext = NULL;
		pMem -> pPrev = NULL;

	return pMem;

} // end makeNode function

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment:
* Date: mm/dd/2015
* Function: loadRecords
* Description: load records from a file in to dynamic doubly-linked list
* Precondition: Node pHead must be declared
* Postcondition: pHead Linked List will be loaded with the data from the text file
*********************************************************************************/
void loadRecords (Node **pHead)
{
	// declare variables to store values read in from file before moving to the struct
	// I used arrays because I couldn't get pointers to work, I tried going to the ACM
	// after Hackathon but there were no TA's there.

	char artist[100] = {""}, albumTitle[100] = {""}, songTitle[100] = {""}, genre[100] = {""}, 
		eatspace = '\0';
	SongLength lengthOfSong;
	int minutes = 0, seconds = 0, numberTimesPlayed = 0, rating = 0, testCount = 0;
	Record newRecord;

	// declare a pointer to a file to open for streaming
	FILE *infile = NULL;
	
	// declare navigation nodes (to traverse the list)
	Node *pPrev = NULL, *pCur = NULL, *pNext = NULL, *pMem = NULL;

	// open file for reading
	infile = fopen("records.txt", "r");

	// use a while loop to read the entire contents of the file and 
	// load them into separate nodes in a linked list

 	while (!feof (infile))
 	{
		// read each entry from the file into a node
		// use of [^\n] found on stackoverflow.net,
		// it tells scanf to read until a newline (\n) is encountered

		// I used fscanf instead of fgets because fgets needed a fixed number of positions to 
		// read and that was causing me issues, I could have filtered it but honestly, I focused
		// more on figuring out the pointers and didn't feel I could devote any time to other 
		// things on this project.

		fscanf(infile, "%[^\n]s", artist); 
		fscanf(infile, "%c", &eatspace); // take care of pesky new-line character
		fscanf(infile, "%[^\n]s", albumTitle);
		fscanf(infile, "%c", &eatspace);
		fscanf(infile, "%[^\n]s", songTitle);
		fscanf(infile, "%c", &eatspace);
		fscanf(infile, "%[^\n]s", genre);
		fscanf(infile, "%c", &eatspace);
		fscanf(infile, "%d", &minutes); // minutes and seconds are stored as separate values
		fscanf(infile, "%c", &eatspace);
		fscanf(infile, "%d", &seconds);
		fscanf(infile, "%c", &eatspace);
		fscanf(infile, "%d", &numberTimesPlayed);
		fscanf(infile, "%c", &eatspace);
		fscanf(infile, "%d", &rating);
		fscanf(infile, "%c", &eatspace);

		// store the read-in variables into the struct 

		strcpy (newRecord.artist, artist);
		strcpy (newRecord.albumTitle, albumTitle);
		strcpy (newRecord.songTitle, songTitle);
		strcpy (newRecord.genre, genre);
		newRecord.lengthOfSong.minutes = minutes;
		newRecord.lengthOfSong.seconds = seconds;
		newRecord.numberTimesPlayed = numberTimesPlayed;
		newRecord.rating = rating;
		
		// insert the new record at the front of the list

		pMem = makeNode (newRecord);
		insertAtFront (pHead, pMem);
		
	} // end while loop to read until end of file

	// close the input file
	fclose (infile);

} // end loadRecords function

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment:
* Date: mm/dd/2015
* Function: storeRecords
* Description: store records to a file from doubly-linked list
* Precondition: Linked list must exist and contain at least one node
* Postcondition: the contents of the linked list will be written to a 
*				formatted text file, records2.txt
*********************************************************************************/

void storeRecords (Node **pHead)
{
	// declare a file streaming variable

	FILE *outfile = NULL;

	// initialize file streaming variable

	outfile = fopen ("records2.txt", "w");

	// use a while loop to print each line of each node of the linked list 
	// to the text file

	while (*pHead != NULL)
	{
		fprintf (outfile, "Artist: %s\n", (*pHead) -> entry.artist);
		fprintf (outfile, "Album: %s\n", (*pHead) -> entry.albumTitle);
		fprintf (outfile, "Song: %s\n", (*pHead) -> entry.songTitle);
		fprintf (outfile, "Genre: %s\n", (*pHead) -> entry.genre);
		fprintf (outfile, "Length: %dm %ds\n", (*pHead) -> entry.lengthOfSong.minutes,
			(*pHead) -> entry.lengthOfSong.seconds); // store minutes and seconds as "joined" variables
		fprintf (outfile, "Play count: %d\n", (*pHead) -> entry.numberTimesPlayed);
		fprintf (outfile, "Rating: %d\n", (*pHead) -> entry.rating);
		fprintf (outfile, "\n"); // add blank line between records, make it readable
		
		// advance to the next node
		// navigation only, no need to adjust pPrev, if we want to go backwards 
		// through the list, we can use the pPrev pointer but moving forward is 
		// all that is necessary for this function

		*pHead = (*pHead) -> pNext;
	} // end while pHead is NULL

	// close the output file (good programming practice)

	fclose (outfile);
} // end storeRecords function

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment:
* Date: mm/dd/2015
* Function: displayRecordsMenu
* Description: Uses a menu to determine what record attribute to search
*				and the search criteria
* Precondition: pHead must exist, display must have been selected from the main menu
* Postcondition: all records that match a criteria will be displayed
*********************************************************************************/
void displayRecordsMenu (Node *pHead)
{
	// declare an int variable for the menu 

	int searchType = 0;

		// print the menu:
	system ("cls");
	printf ("1) Artist\n");
	printf ("2) Album\n");
	printf ("3) Song title\n");
	printf ("4) Genre\n");
	printf ("5) Song length\n");
	printf ("6) Number of times played\n");
	printf ("7) Song rating\n");
	printf ("8) show all records\n\n");

	// use do-while to loop through the menu if a user chooses an invalid entry
	do
	{
		// get input from user
		scanf ("%d", &searchType);

		// evaluate user input and choose correct display function

		switch (searchType)
		{
		case 1:
			displayRecordsArtist (pHead);
			break;
		case 2:
			displayRecordsAlbum (pHead);
			break;
		case 3:
			displayRecordsSong (pHead);
			break;
		case 4:
			displayRecordsGenre (pHead);
			break;
		case 5:
			displayRecordsLength (pHead);
			break;
		case 6:
			displayRecordsPlayCount (pHead);
			break;
		case 7:
			displayRecordsRating (pHead);
			break;
		case 8:
			displayRecordsAll (pHead);
			break;
		default:
			printf ("Please enter a valid number 1 - 8\n");
			break;
		} // end switch statement
	} while (searchType < 1 && searchType > 8); // end while loop to keep displaying the menu if the user chooses an invalid option

} // end displayRecordsMenu function

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment:
* Date: mm/dd/2015
* Function: displayRecordsArtist
* Description: display all records to the screen that contain the entered criteria
* Precondition: must have been chosen from the display menu, pHead must exist and
*				contain data
* Postcondition: All records that match the selected criteria will be displayed
*********************************************************************************/
void displayRecordsArtist (Node *pHead)
{
	// declare variables:

	char searchArtist[100] = {""};
	int success = 0, menuPause = 0;
	
		// prompt for and get user input for search criteria

	printf ("Enter the artist name: ");

	// use %[^\n]s to read all characters until newline so artist can contain spaces (stackoverflow.com)
	scanf (" %[^\n]s", searchArtist);

	// display a message to the user of the content being searched for

	printf ("searching for: \"%s\"\n\n", searchArtist);

	// use a while loop to find and print only the first matching record
	// set success flag to 1 when a record is found that matches the criteria
	// let while criteria be a success flag == 0, this will stop after a single
	// matching record is found

	while ((pHead != NULL) && success == 0)
	{	
		// use string-compare to evaluate records

		if (strcmp (pHead -> entry.artist, searchArtist) == 0)
		{
			printf ("Artist: %s\n", pHead -> entry.artist);
			printf ("Album: %s\n", pHead -> entry.albumTitle);
			printf ("Song: %s\n", pHead -> entry.songTitle);
			printf ("Genre: %s\n", pHead -> entry.genre);
			printf ("Length: %d m %ds\n", pHead -> entry.lengthOfSong.minutes, 
				pHead -> entry.lengthOfSong.seconds);
			printf ("Count: %d\n", pHead -> entry.numberTimesPlayed);
			printf ("Rating: %d\n\n", pHead -> entry.rating);

			// if search was successful, update success flag

			success = 1;
		} // end if there is a match, print the record(s)

		// navigation only, no need to set pPrev

		pHead = pHead -> pNext;
	} // end while loop

	// if search was unsuccessful, alert user (don't leave them hanging)

	if (success == 0)
	{
		printf ("No records were found that have an Artist with the name: \"%s\"\n", searchArtist);
	}

	while (menuPause == 0)
	{
		printf ("Type 1 to return to the previous menu: ");
		scanf ("%d", &menuPause);
	} // end hold display until user enters a not zero
} // end displayRecordsArtist function

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment:
* Date: mm/dd/2015
* Function: displayRecordsAlbum
* Description: display all records to the screen that contain the entered criteria
* Precondition: must have been chosed from display menu
* Postcondition: All records that match the selected criteria will be displayed
*********************************************************************************/
void displayRecordsAlbum (Node *pHead)
{
	// declare variables:

	char searchAlbum[100] = {""};
	int success = 0, menuPause = 0;
	
		// prompt for and get user input for search criteria

	printf ("Enter the Album name: ");
	// use %[^\n]s to read all characters until newline so artist can contain spaces (stackoverflow.com)
	scanf (" %[^\n]s", searchAlbum);

		// display a message to the user of the content being searched for
	printf ("searching for: \"%s\"\n\n", searchAlbum);

	// use a while loop to find and print only the first matching record
	// set success flag to 1 when a record is found that matches the criteria
	// let while criteria be a success flag == 0, this will stop after a single
	// matching record is found

	while ((pHead != NULL) && success == 0)
	{	
		// use string-compare to evaluate nodes

		if (strcmp (pHead -> entry.albumTitle, searchAlbum) == 0)
		{
			printf ("Artist: %s\n", pHead -> entry.artist);
			printf ("Album: %s\n", pHead -> entry.albumTitle);
			printf ("Song: %s\n", pHead -> entry.songTitle);
			printf ("Genre: %s\n", pHead -> entry.genre);
			printf ("Length: %d m %ds\n", pHead -> entry.lengthOfSong.minutes, 
				pHead -> entry.lengthOfSong.seconds);
			printf ("Count: %d\n", pHead -> entry.numberTimesPlayed);
			printf ("Rating: %d\n\n", pHead -> entry.rating);

			// if record(s) were found, update success flag

			success = 1;
		} // end if there is a match, print the record(s)

		// navigation only, no need to set pPrev

		pHead = pHead -> pNext;
	} // end while loop

	// if search was unsuccessful, alert user (don't leave them hanging)
	if (success == 0)
	{
		printf ("No records were found that have an Album with the name: \"%s\"\n", searchAlbum);
	}

	// hold display until user enters a non-zero
	while (menuPause == 0)
	{
		printf ("Type 1 to return to the previous menu: ");
		scanf ("%d", &menuPause);
	} // end hold display until user enters a not zero
} // end displayRecordsAlbum function

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment:
* Date: mm/dd/2015
* Function: displayRecordsSong
* Description: display all records to the screen that contain the entered criteria
* Precondition: must have been chosed from display menu
* Postcondition: All records that match the selected criteria will be displayed
*********************************************************************************/
void displayRecordsSong (Node *pHead)
{
	// declare variables:

	char searchSong[100] = {""};
	int success = 0, menuPause = 0;
	
		// prompt for and get user input for search criteria

	printf ("Enter the Song Title: ");
	// use %[^\n]s to read all characters until newline so artist can contain spaces (stackoverflow.com)
	scanf (" %[^\n]s", searchSong);

	// display a message to the user of the content being searched for
	
	printf ("searching for: \"%s\"\n\n", searchSong);

	// use a while loop to find and print only the first matching record
	// set success flag to 1 when a record is found that matches the criteria
	// let while criteria be a success flag == 0, this will stop after a single
	// matching record is found

	while ((pHead != NULL) && success == 0)
	{	
		// use string-compare to evaluate nodes
		if (strcmp (pHead -> entry.songTitle, searchSong) == 0)
		{
			printf ("Artist: %s\n", pHead -> entry.artist);
			printf ("Album: %s\n", pHead -> entry.albumTitle);
			printf ("Song: %s\n", pHead -> entry.songTitle);
			printf ("Genre: %s\n", pHead -> entry.genre);
			printf ("Length: %d m %ds\n", pHead -> entry.lengthOfSong.minutes, 
				pHead -> entry.lengthOfSong.seconds);
			printf ("Count: %d\n", pHead -> entry.numberTimesPlayed);
			printf ("Rating: %d\n\n", pHead -> entry.rating);

			// if record(s) were found, update success flag

			success = 1;
		} // end if there is a match, print the record(s)

		// navigation only, no need to set pPrev

		pHead = pHead -> pNext;
	} // end while loop

	// if search was unsuccessful, alert user (don't leave them hanging)

	if (success == 0)
	{
		printf ("No records were found that have Song by the name: \"%s\"\n", searchSong);
	}

	// hold display until user enters a non-zero
	while (menuPause == 0)
	{
		printf ("Type 1 to return to the previous menu: ");
		scanf ("%d", &menuPause);
	} // end hold display until user enters a not zero

} // end displayRecordsSong function

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment:
* Date: mm/dd/2015
* Function: displayRecordsGenre
* Description: display all records to the screen that contain the entered criteria
* Precondition: must have been chosed from display menu
* Postcondition: All records that match the selected criteria will be displayed
*********************************************************************************/
void displayRecordsGenre (Node *pHead)
{
	// declare variables:

	char searchGenre[100] = {""};
	int success = 0, menuPause = 0;
	
		// prompt for and get user input for search criteria

	printf ("Enter the Genre type: ");
	// use %[^\n]s to read all characters until newline so artist can contain spaces (stackoverflow.com)
	scanf (" %[^\n]s", searchGenre);

		// display a message to the user of the content being searched for

	printf ("searching for: \"%s\"\n\n", searchGenre);

	// use a while loop to find and print only the first matching record
	// set success flag to 1 when a record is found that matches the criteria
	// let while criteria be a success flag == 0, this will stop after a single
	// matching record is found

	while ((pHead != NULL) && success == 0)
	{	
		// use string-compare to evaluate data

		if (strcmp (pHead -> entry.genre, searchGenre) == 0)
		{
			printf ("Artist: %s\n", pHead -> entry.artist);
			printf ("Album: %s\n", pHead -> entry.albumTitle);
			printf ("Song: %s\n", pHead -> entry.songTitle);
			printf ("Genre: %s\n", pHead -> entry.genre);
			printf ("Length: %d m %ds\n", pHead -> entry.lengthOfSong.minutes, 
				pHead -> entry.lengthOfSong.seconds);
			printf ("Count: %d\n", pHead -> entry.numberTimesPlayed);
			printf ("Rating: %d\n\n", pHead -> entry.rating);

			// if successful, update flag

			success = 1;
		} // end if there is a match, print the record(s)

		// navigation only, no need to set pPrev

		pHead = pHead -> pNext;
	} // end while loop

	// if unsuccessful, notify user

	if (success == 0)
	{
		printf ("No records were found in the Genre: \"%s\"\n", searchGenre);
	}

	// hold display until user enters a non-zero
	while (menuPause == 0)
	{
		printf ("Enter 1 to continue: ");
		scanf ("%d", &menuPause);
	} // end hold display until user enters a non-zero

} // end displayRecordsGenre function

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment:
* Date: mm/dd/2015
* Function: displayRecordsLength
* Description: display all records to the screen that contain the entered criteria
* Precondition: must have been chosed from display menu
* Postcondition: All records that match the selected criteria will be displayed
*********************************************************************************/
void displayRecordsLength (Node *pHead)
{
	// declare variables:

	int searchLengthMinutes = 0, searchLengthSeconds = 0, success = 0, menuPause = 0;
	
		// prompt for and get user input for search criteria

	printf ("Enter the Song Length (minutes, seconds): ");
	
	scanf (" %d %d", &searchLengthMinutes, &searchLengthSeconds);

	// print a message to let the user know what is being searched for
		
	printf ("searching for: %dm %ds\n\n", searchLengthMinutes, searchLengthSeconds);

	// use a while loop to find and print only the first matching record
	// set success flag to 1 when a record is found that matches the criteria
	// let while criteria be a success flag == 0, this will stop after a single
	// matching record is found

	while ((pHead != NULL) && success == 0)
	{	
		// evaluate nodes with an if statement

		if ((pHead -> entry.lengthOfSong.minutes == searchLengthMinutes) && 
			(pHead -> entry.lengthOfSong.seconds == searchLengthSeconds))
		{
			printf ("Artist: %s\n", pHead -> entry.artist);
			printf ("Album: %s\n", pHead -> entry.albumTitle);
			printf ("Song: %s\n", pHead -> entry.songTitle);
			printf ("Genre: %s\n", pHead -> entry.genre);
			printf ("Length: %d m %ds\n", pHead -> entry.lengthOfSong.minutes, 
				pHead -> entry.lengthOfSong.seconds);
			printf ("Count: %d\n", pHead -> entry.numberTimesPlayed);
			printf ("Rating: %d\n\n", pHead -> entry.rating);

			// if records are found, update flag

			success = 1;
		} // end if there is a match, print the record(s)

		// navigation only, no need to set pPrev

		pHead = pHead -> pNext;
	} // end while loop

	// if no records are found, notify user

	if (success == 0)
	{
		printf ("No records were found that were %dm %ds long: \n", searchLengthMinutes, 
			searchLengthSeconds);
	}

	// hold display until user enters a non-zero
	while (menuPause == 0)
	{
		printf ("Type 1 to return to the previous menu: ");
		scanf ("%d", &menuPause);
	} // end hold display until user enters a not zero

} // end displayRecordsLength function

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment:
* Date: mm/dd/2015
* Function: displayRecordsPlayCount
* Description: display all records to the screen that contain the entered criteria
* Precondition: must have been chosed from display menu
* Postcondition: All records that match the selected criteria will be displayed
*********************************************************************************/
void displayRecordsPlayCount (Node *pHead)
{
	// declare variables
	int searchPlayCount = 0, success = 0, menuPause = 0;
	
		// prompt for and get user input for search criteria

	printf ("Enter the number of times played: ");
	
	scanf (" %d", &searchPlayCount);

	// print message to screen to inform user what is being searched for	

	printf ("searching for: %d times\n\n", searchPlayCount);

	// use a while loop to find and print only the first matching record
	// set success flag to 1 when a record is found that matches the criteria
	// let while criteria be a success flag == 0, this will stop after a single
	// matching record is found

	while ((pHead != NULL) && success == 0)
	{	
		if ((pHead -> entry.numberTimesPlayed == searchPlayCount))
		{
			printf ("Artist: %s\n", pHead -> entry.artist);
			printf ("Album: %s\n", pHead -> entry.albumTitle);
			printf ("Song: %s\n", pHead -> entry.songTitle);
			printf ("Genre: %s\n", pHead -> entry.genre);
			printf ("Length: %d m %ds\n", pHead -> entry.lengthOfSong.minutes, 
				pHead -> entry.lengthOfSong.seconds);
			printf ("Count: %d\n", pHead -> entry.numberTimesPlayed);
			printf ("Rating: %d\n\n", pHead -> entry.rating);

			// if records are found, update flag

			success = 1;
		} // end if there is a match, print the record(s)

		// navigation only, no need to set pPrev

		pHead = pHead -> pNext;
	} // end while loop

	// if no records are found, inform the user

	if (success == 0)
	{
		printf ("No records were found that were played %d times: \n", searchPlayCount);
	}

	// hold display until user enters a non-zero
	while (menuPause == 0)
	{
		printf ("Type 1 to return to the previous menu: ");
		scanf ("%d", &menuPause);
	} // end hold display until user enters a not zero

} // end displayPlayCount function

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment:
* Date: mm/dd/2015
* Function: displayRecordsRating
* Description: display all records to the screen that contain the entered criteria
* Precondition: must have been chosed from display menu
* Postcondition: All records that match the selected criteria will be displayed
*********************************************************************************/
void displayRecordsRating (Node *pHead)
{
	// declare variables:

	int searchRating = 0, success = 0, menuPause = 0;
	
		// prompt for and get user input for search criteria

	printf ("Enter a rating level: ");
	
	scanf (" %d", &searchRating);

	// inform user what is being searched for:

	printf ("searching for rating of %d: \n\n", searchRating);

	// use a while loop to find and print only the first matching record
	// set success flag to 1 when a record is found that matches the criteria
	// let while criteria be a success flag == 0, this will stop after a single
	// matching record is found

	while ((pHead != NULL) && success == 0)
	{	
		// evaluate with an if statement

		if ((pHead -> entry.rating == searchRating))
		{
			printf ("Artist: %s\n", pHead -> entry.artist);
			printf ("Album: %s\n", pHead -> entry.albumTitle);
			printf ("Song: %s\n", pHead -> entry.songTitle);
			printf ("Genre: %s\n", pHead -> entry.genre);
			printf ("Length: %d m %ds\n", pHead -> entry.lengthOfSong.minutes, 
				pHead -> entry.lengthOfSong.seconds);
			printf ("Count: %d\n", pHead -> entry.numberTimesPlayed);
			printf ("Rating: %d\n\n", pHead -> entry.rating);

			// if records are found, update flag

			success = 1;
		} // end if there is a match, print the record(s)

		// navigation only, no need to set pPrev

		pHead = pHead -> pNext;
	} // end while loop

	// if no records are found, inform user

	if (success == 0)
	{
		printf ("No records were found that have a rating of %d. \n", searchRating);
	}

	// hold display until user enters a non-zero
	while (menuPause == 0)
	{
		printf ("Type 1 to return to the previous menu: ");
		scanf ("%d", &menuPause);
	} // end hold display until user enters a not zero

} // end displayRecordsRating function

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment:
* Date: mm/dd/2015
* Function: displayRecordsAll
* Description: display all records to the screen
* Precondition: must have been chosed from display menu
* Postcondition: All records will be displayed
*********************************************************************************/
void displayRecordsAll (Node *pHead)
{
	// declare variables:

	int menuPause = 0;

	// use a while loop to display the contents of each node in the linked list

	while (pHead != NULL)
	{	
		printf ("Artist: %s\n", pHead -> entry.artist);
		printf ("Album: %s\n", pHead -> entry.albumTitle);
		printf ("Song: %s\n", pHead -> entry.songTitle);
		printf ("Genre: %s\n", pHead -> entry.genre);
		printf ("Length: %dm %ds\n", pHead -> entry.lengthOfSong.minutes, 
			pHead -> entry.lengthOfSong.seconds);
		printf ("Count: %d\n", pHead -> entry.numberTimesPlayed);
		printf ("Rating: %d\n\n", pHead -> entry.rating);

		// navigation only, no need to set pPrev

		pHead = pHead -> pNext;
	} // end while not at the end of the list

	// hold display until user enters a non-zero
	while (menuPause == 0)
	{
		printf ("Type 1 to return to the previous menu: ");
		scanf ("%d", &menuPause);
	} // end hold display until user enters a not zero

} // end displayRecordsAll function

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment:
* Date: mm/dd/2015
* Function: insertRecords
* Description: insert new records
* Precondition: must be selected from the main menu, phead must exist
* Postcondition: a new record will be added to the linked list based on user input
*********************************************************************************/
void insertRecords (Node **pHead)
{
	// declare variables, arrays again instead of pointers

	char artist[100] = {""}, album[100] = {""}, song[100] = {""}, genre[100] = {""};
	int lengthMinutes = 0, lengthSeconds = 0, playCount = 0, rating = 0;
	Record newRecord;
	Node *newNode = NULL;

	// prompt user for each element and read in the data from the user

	printf ("Enter the name of the Artist: ");
	scanf (" %[^\n]s", artist);
	printf ("Enter the name of the Album: ");
	scanf (" %[^\n]", album);
	printf ("Enter the Song Title: ");
	scanf (" %[^\n]s", song);
	printf ("Enter the Genre: ");
	scanf (" %[^\n]s", genre);
	printf ("Enter the song length in minutes and seconds: ");
	scanf (" %d %d", &lengthMinutes, &lengthSeconds);
	printf ("Enter the number of times this song has been played: ");
	scanf (" %d", &playCount);
	printf ("Enter a rating for this song: ");
	scanf (" %d", &rating);

	// create a new record struct with this data:

	strcpy (newRecord.artist, artist);
	strcpy (newRecord.albumTitle, album);
	strcpy (newRecord.songTitle, song);
	strcpy (newRecord.genre, genre);
	newRecord.lengthOfSong.minutes = lengthMinutes;
	newRecord.lengthOfSong.seconds = lengthSeconds;
	newRecord.numberTimesPlayed = playCount;
	newRecord.rating = rating;

	// insert the new data in alphabetial order

	insertInOrder (pHead, newRecord);

} // end insertRecords function

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment:
* Date: mm/dd/2015
* Function: deleteRecords
* Description: delete a specific node from the linked list
* Precondition: pHead must exist, should contain data
* Postcondition: if it exists, the node containing the offending song will be
*				removed from the linked list
*********************************************************************************/
void deleteRecords (Node **pHead)
{
	// declare variables:

	char song[100] = {""};
	Node *pPrev = NULL, *pNext = NULL;

	// prompt for and get input from user

	printf ("Enter a song title to delete: ");
	scanf (" %[^\n]", song);

	// traverse the list to find this title
	while (*pHead != NULL)
	{
		if (strcmp ((*pHead) -> entry.songTitle, song) == 0)
		{
			// set pPrev to pNext to link over the node to be deleted
			// and set pNext's pPrev to pPrev
			// (and let this be a lesson to me to be more creative with my node and node elements names)

			pPrev -> pNext = pNext;
			pNext -> pPrev = pPrev;

			// once the new links are made, the desired node can be freed

			free ((*pHead) -> entry.artist);
			free ((*pHead) -> entry.albumTitle);
			free ((*pHead) -> entry.songTitle);
			free ((*pHead) -> entry.genre);
			// I can't get this to work on the integers ?!?
			/*
			free ((*pHead) -> entry.lengthOfSong.minutes);
			free ((*pHead) -> entry.lengthOfSong.seconds);
			free ((*pHead) -> entry.numberTimesPlayed);
			free ((*pHead) -> entry.rating);
			*/
			// this is a memory leak right now !!!
			free (*pHead);
		} // end free memory from the node that contain(ed) the song
		else
		{
			pPrev = *pHead;
			*pHead = (*pHead) -> pNext;
			// this looks confusing but it's setting pNext to the new pHead's pNext
			// this is in fact a different node than the (*pHead) -> pNext from the preious statement
			pNext = (*pHead) -> pNext; 
		} // end navigate to the next node

	} // end while
} // end deleteRecords function

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment:
* Date: mm/dd/2015
* Function: editRecords
* Description: edit an element of a record
* Precondition: must be called from the menu
* Postcondition: the song title will be changed to the new value entered by the user
*********************************************************************************/
void editRecords (Node **pHead)
{
	// declare variables:

	char song[100] = {""};
	int menuPause = 0;

	// prompt for and get input from user

	printf ("Enter a song title to edit: ");
	scanf (" %[^\n]s", song);

	// use a while loop and string-compare to locate the desired node

	while (strcmp(((*pHead) -> entry.songTitle), song) != 0)
	{
		// navigation only, no need to set pPrev, pPrev is still a pointer the node preceeding this one
		*pHead = (*pHead) -> pNext;
	} // end while loop to find record to edit

	// prompt for and get replacement data from user

	printf ("Enter the new title: ");
	scanf (" %[^\n]s", song);

	// put the new data in the field

	strcpy ((*pHead) -> entry.songTitle, song);

	// print the data from the node to let the user know the change was successful

	printf ("The new song title is: %s\n", (*pHead) -> entry.songTitle);

	// hold display until user enters a non-zero
	while (menuPause == 0)
	{
		printf ("Type 1 to return to the previous menu: ");
		scanf ("%d", &menuPause);
	} // end hold display until user enters a not zero

} // end editRecords function

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment:
* Date: mm/dd/2015
* Function: rateRecords
* Description: rate a song
* Precondition: must be called from the menu, pHead must exist, the desired record
*				must exist
* Postcondition: the selected song will be updated to the new rating entered by user
*********************************************************************************/
void rateRecords (Node **pHead)
{
		// declare variables:

	char song[100] = {""};
	int pRating = 0, menuPause = 0;

	// prompt for and get input from user

	printf ("Enter a song title to edit: ");
	scanf (" %[^\n]s", song);

	// use a while loop and string-compare to locate the desired node

	while (strcmp(((*pHead) -> entry.songTitle), song) != 0)
	{
		// navigation only, no need to set pPrev

		*pHead = (*pHead) -> pNext;
	} // end while loop to find record to edit

	// prompt for and get replacement data from user

	printf ("Enter the rating for this song: ");
	scanf (" %d", pRating);

	// put the new data in the field

	(*pHead) -> entry.rating = pRating;

	// print the data from the node to let the user know the change was successful

	printf ("The new rating for %s is: %d\n", (*pHead) -> entry.songTitle, (*pHead) -> entry.rating);

	// hold display until user enters a non-zero
	while (menuPause == 0)
	{
		printf ("Type 1 to return to the previous menu: ");
		scanf ("%d", &menuPause);
	} // end hold display until user enters a not zero

} // end rateRecords function

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment:
* Date: mm/dd/2015
* Function: insertAtFront
* Description: insert a Node at the front of the list
* Precondition: pHead must exist, pMem must exist and contain data
* Postcondition: the new node will be inserted at the beginnng of the list
*********************************************************************************/
void insertAtFront (Node **pHead, Node *pMem)
{
	// check if linked list is empty, if so, just make the new data the first node
	if (*pHead == NULL)
	{
		*pHead = pMem; // pPrev and pNext still point to NULL, all good
	}
	else // if not empty, insert new data at the front of the list
	{
		pMem -> pNext = *pHead; // pMem's pPrev is still NULL, all good
		*pHead = pMem;
	}
} // end insertAtFront function

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment:
* Date: mm/dd/2015
* Function: printList
* Description: used for debugging
*				print the entire list to the screen
* Precondition: pHead must exist, must contain data
* Postcondition: the contents of the entire linked list will be printed to the
*				screen with the prefix "printList: " to identify these as 
*				contents from the list that were printed from this function
*********************************************************************************/
void printList (Node *pHead)
{
	// use while loop to print each element of each node
	while ((pHead) != NULL)
	{
		printf ("printList: Artist: %s\n", pHead -> entry.artist);
		printf ("printList: Album: %s\n", pHead -> entry.albumTitle);
		printf ("printList: Song: %s\n", pHead -> entry.songTitle);
		printf ("printList: Genre: %s\n", pHead -> entry.genre);
		printf ("printList: Length: %dm %ds\n", pHead -> entry.lengthOfSong.minutes,
			pHead -> entry.lengthOfSong.seconds);
		printf ("printList: Play count: %d\n", pHead -> entry.numberTimesPlayed);
		printf ("printList: Rating: %d\n", pHead -> entry.rating);
		
		// navigation only, no need to set pPrev

		pHead = pHead -> pNext;
	}
}

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment:
* Date: mm/dd/2015
* Function: insertInOrder
* Description: insert a new node in the linked list in alphabetical order
* Precondition: must be called from the menu, pHead must exist, the new record
*				must exist
* Postcondition: the new node will be inserted in to the list in order
*********************************************************************************/
void insertInOrder (Node **pHead, Record newRecord)
{
	// declare navigation nodes
	Node *pMem = NULL, *pPrev = NULL, *pCur = NULL, *pNext = NULL;
	pMem = makeNode (newRecord);

	// if the list is empty, just put the new node at the beginning
	if (*pHead == NULL) // list is empty
	{
		*pHead = pMem;
	} // end if list is empty
	else // else, the list is not empty
	{
		// pPrev = NULL initially
		pCur = *pHead; // set to front of list
		pNext = pCur -> pNext;
		while ((pCur != NULL) && 
			strcmp ((pCur -> entry.artist),(pMem -> entry.artist)) == -1)
			// allows us to walk through list, rely on short circuit evaluation
		{
			pPrev = pCur; 
			pCur = pCur -> pNext;
			// pNext = pCur -> pNext;
		} // end while 
	} // end list is not empty

	// we are now in the right spot to insert new data
	if (pPrev != NULL)
	{
	pMem -> pNext = pCur;
	pPrev -> pNext = pMem; 
	} // end if we are not at the beginning
	else
	{
		pMem -> pNext = pCur;
		*pHead = pMem;
	} // end if we are at the beginning

} // end insertInOrder function