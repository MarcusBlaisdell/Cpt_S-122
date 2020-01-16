#include "Blaisdell_PA2_v2.h"

Node *makeNode (Record newRecord)
{
	Node *pMem = NULL;

	pMem = (Node *) malloc (sizeof (Node));

	// pMem -> newRecord.artist = (char *) malloc (sizeof (char) * (strlen (newArtist) + 1));
	// pMem -> newRecord.album = (char *) malloc (sizeof (char) * (strlen (album) + 1));
	pMem -> newRecord = newRecord;
	pMem -> pNext = NULL;

	printf ("Artist (makeNode): %s\nAlbum (makeNode): %s\n", pMem -> newRecord.artist, 
		pMem -> newRecord.album);

	return pMem;
}

void insertAtFront (Node **pHead, Record newRecord)
{
	Node *pMem = NULL, *pCur = NULL;

	pMem = makeNode (newRecord);
	printf ("This is insertatFront: Artist (pMem): %s\nAlbum (pMem): %s\n", pMem -> newRecord.artist, 
		pMem -> newRecord.album);

	if (pHead == NULL)
	{
		*pHead = pMem;
	}
	else
	{
		pMem -> pNext = *pHead;
		*pHead = pMem;
	}

	printf ("this is the end of insert at front Artist (pHead): %s\nAlbum (pHead): %s\n", (*pHead) -> newRecord.artist,
		(*pHead) -> newRecord.album);

} // end insertAtFront

/*
void createRecords (Node **pHead)
{
	Record newRecord;
	newRecord.artist = "Lindsey Stirling";
	newRecord.album = "Stirling, Lindsey";
	newRecord.songTitle = "Electric Daisy Violin";
	newRecord.genre = "Electronic";
	newRecord.lengthOfSong.minutes = 3;
	newRecord.lengthOfSong.seconds = 38;
	newRecord.numberTimesPlayed = 3;
	newRecord.rating = 5;
	insertAtFront (pHead, newRecord);

	newRecord.artist = "Mathew Kearney";
	newRecord.album = "Something about love";
	newRecord.songTitle = "Closer To Love";
	newRecord.genre = "Rock";
	newRecord.lengthOfSong.minutes = 3;
	newRecord.lengthOfSong.seconds = 37;
	newRecord.numberTimesPlayed = 5;
	newRecord.rating = 5;
	insertAtFront (pHead, newRecord);
}
*/

void printList (Node *pHead)
{
	while ((pHead) != NULL)
	{
		printf ("printList: Artist: %s\n", pHead -> newRecord.artist);
		printf ("printList: Album: %s\n", pHead -> newRecord.album);
		printf ("printList: Song: %s\n", pHead -> newRecord.songTitle);
		printf ("printList: Genre: %s\n", pHead -> newRecord.genre);
		printf ("printList: Length: %dm %ds\n", pHead -> newRecord.lengthOfSong.minutes,
			pHead -> newRecord.lengthOfSong.seconds);
		printf ("printList: Play count: %d\n", pHead -> newRecord.numberTimesPlayed);
		printf ("printList: Rating: %d\n", pHead -> newRecord.rating);
		
		pHead = pHead -> pNext;
	}
}

/*
Node *makeNode (char *newArtist, char *album)
{
	Node *pMem = NULL;

	pMem = (Node *) malloc (sizeof (Node));

	pMem -> newRecord.artist = (char *) malloc (sizeof (char) * (strlen (newArtist) + 1));
	pMem -> newRecord.album = (char *) malloc (sizeof (char) * (strlen (album) + 1));
	pMem -> newRecord.artist = newArtist;
	pMem -> newRecord.album = album;
	pMem -> pNext = NULL;

	printf ("Artist (makeNode): %s\nAlbum (makeNode): %s\n", pMem -> newRecord.artist, 
		pMem -> newRecord.album);

	return pMem;
}

void insertAtFront (Node **pHead, char *newArtist, char *album)
{
	Node *pMem = NULL, *pCur = NULL;

	pMem = makeNode (newArtist, album);
	printf ("Artist (pMem): %s\nAlbum (pMem): %s\n", pMem -> newRecord.artist, 
		pMem -> newRecord.album);

	if (pHead == NULL)
	{
		*pHead = pMem;
	}
	else
	{
		pMem -> pNext = *pHead;
		*pHead = pMem;
	}

	printf ("Artist (pHead): %s\nAlbum (pHead): %s\n", (*pHead) -> newRecord.artist,
		(*pHead) -> newRecord.album);

} // end insertAtFront
*/

void loadRecords (Node **pHead)
{
	// declare variables to store values read in from file before moving to the struct
	//char artist[500] = {""}, albumTitle[30] = {""}, songTitle[30] = {""}, genre[30] = {""}, 
	//	eatspace = '\0';
	char *artist = NULL, *albumTitle = NULL, *songTitle = NULL, *genre = NULL, eatspace = '\0';
	SongLength lengthOfSong;
	int minutes = 0, seconds = 0, numberTimesPlayed = 0, rating = 0;
	

	// Record newRecord = {NULL}; // FROM ANDY!! (not necessary as it turns out?)
	Record newRecord;

	// declare a pointer to a file to open for streaming
	FILE *infile = NULL;
	
	// declare navigation nodes (to traverse the list)
	Node *pPrev = NULL, *pCur = NULL, *pNext = NULL, *pMem = NULL;

	// open file for reading
	infile = fopen("Records.txt", "r");

	artist = (char *) malloc (sizeof (char) * 500);
	albumTitle = (char *) malloc (sizeof (char) * 30);
	songTitle = (char *) malloc (sizeof (char) * 30);
	genre = (char *) malloc (sizeof (char) * 30);

	while (!feof (infile))
	{
		/*
		// read each newRecord from the file into a node
		// use of [^\n] found on stackoverflow.net,
		// it tells scanf to read until a newline (\n) is encountered
		fscanf(infile, "%[^\n]s", artist);
		fscanf(infile, "%c", &eatspace); // take care of pesky new-line character
		fscanf(infile, "%[^\n]s", albumTitle);
		fscanf(infile, "%c", &eatspace);
		fscanf(infile, "%[^\n]s", songTitle);
		fscanf(infile, "%c", &eatspace);
		fscanf(infile, "%[^\n]s", genre);
		fscanf(infile, "%c", &eatspace);
		fscanf(infile, "%d", &minutes);
		fscanf(infile, "%c", &eatspace);
		fscanf(infile, "%d", &seconds);
		fscanf(infile, "%c", &eatspace);
		fscanf(infile, "%d", &numberTimesPlayed);
		fscanf(infile, "%c", &eatspace);
		fscanf(infile, "%d", &rating);
		fscanf(infile, "%c", &eatspace);

		// store the read-in variables into the struct 
		newRecord.artist = artist;
		newRecord.album = albumTitle;
		newRecord.songTitle = songTitle;
		newRecord.genre = genre;
		newRecord.lengthOfSong.minutes = minutes;
		newRecord.lengthOfSong.seconds = seconds;
		newRecord.numberTimesPlayed = numberTimesPlayed;
		newRecord.rating = rating;
		*/
		newRecord = loadARecord(infile, pHead);
		// insert the new record at the front of the list
		insertAtFront (pHead, newRecord);
		
		printf ("Load: Artist: %s\n", (*pHead) -> newRecord.artist);
		if (  ((*pHead) -> pNext) != NULL  )
		{
			printf ("Load: pNext -> Artist: %s\n", (*pHead) -> pNext -> newRecord.artist);
		}
		printf ("Load: Album: %s\n", (*pHead) -> newRecord.album);
		printf ("Load: Song: %s\n", (*pHead) -> newRecord.songTitle);
		printf ("Load: Genre: %s\n", (*pHead) -> newRecord.genre);
		printf ("Load: Length: %dm %ds\n", (*pHead) -> newRecord.lengthOfSong.minutes, 
			(*pHead) -> newRecord.lengthOfSong.seconds);
		printf ("Load: Play Count: %d\n", (*pHead) -> newRecord.numberTimesPlayed);
		printf ("Load: Rating: %d\n\n", (*pHead) -> newRecord.rating);
		
		// pMem -> pPrev = pPrev;
 		// pCur = pCur -> pNext;
	} // end while loop to read until end of file

	// close the input file
	fclose (infile);

} // end loadRecords function

// load a single record
Record loadARecord (FILE *infile, Node **pHead)
{
	// declare variables to store values read in from file before moving to the struct
	//char artist[500] = {""}, albumTitle[30] = {""}, songTitle[30] = {""}, genre[30] = {""}, 
	//	eatspace = '\0';
	char *artist = NULL, *albumTitle = NULL, *songTitle = NULL, *genre = NULL, eatspace = '\0';
	SongLength lengthOfSong;
	int minutes = 0, seconds = 0, numberTimesPlayed = 0, rating = 0;
	

	// Record newRecord = {NULL}; // FROM ANDY!! (not necessary as it turns out?)
	Record newRecord;

	// declare a pointer to a file to open for streaming
	// FILE *infile = NULL;
	
	// declare navigation nodes (to traverse the list)
	Node *pPrev = NULL, *pCur = NULL, *pNext = NULL, *pMem = NULL;

	// open file for reading
	// infile = fopen("Records.txt", "r");

	artist = (char *) malloc (sizeof (char) * 30);
	albumTitle = (char *) malloc (sizeof (char) * 30);
	songTitle = (char *) malloc (sizeof (char) * 30);
	genre = (char *) malloc (sizeof (char) * 30);

//	while (!feof (infile))
//	{
		// read each newRecord from the file into a node
		// use of [^\n] found on stackoverflow.net,
		// it tells scanf to read until a newline (\n) is encountered
		fscanf(infile, "%[^\n]s", artist);
		fscanf(infile, "%c", &eatspace); // take care of pesky new-line character
		fscanf(infile, "%[^\n]s", albumTitle);
		fscanf(infile, "%c", &eatspace);
		fscanf(infile, "%[^\n]s", songTitle);
		fscanf(infile, "%c", &eatspace);
		fscanf(infile, "%[^\n]s", genre);
		fscanf(infile, "%c", &eatspace);
		fscanf(infile, "%d", &minutes);
		fscanf(infile, "%c", &eatspace);
		fscanf(infile, "%d", &seconds);
		fscanf(infile, "%c", &eatspace);
		fscanf(infile, "%d", &numberTimesPlayed);
		fscanf(infile, "%c", &eatspace);
		fscanf(infile, "%d", &rating);
		fscanf(infile, "%c", &eatspace);

		// store the read-in variables into the struct 
		newRecord.artist = artist;
		newRecord.album = albumTitle;
		newRecord.songTitle = songTitle;
		newRecord.genre = genre;
		newRecord.lengthOfSong.minutes = minutes;
		newRecord.lengthOfSong.seconds = seconds;
		newRecord.numberTimesPlayed = numberTimesPlayed;
		newRecord.rating = rating;
		
		/*
		// insert the new record at the front of the list
		insertAtFront (pHead, newRecord);
		
		printf ("Load: Artist: %s\n", (*pHead) -> newRecord.artist);
		if (  ((*pHead) -> pNext) != NULL  )
		{
			printf ("Load: pNext -> Artist: %s\n", (*pHead) -> pNext -> newRecord.artist);
		}
		printf ("Load: Album: %s\n", (*pHead) -> newRecord.album);
		printf ("Load: Song: %s\n", (*pHead) -> newRecord.songTitle);
		printf ("Load: Genre: %s\n", (*pHead) -> newRecord.genre);
		printf ("Load: Length: %dm %ds\n", (*pHead) -> newRecord.lengthOfSong.minutes, 
			(*pHead) -> newRecord.lengthOfSong.seconds);
		printf ("Load: Play Count: %d\n", (*pHead) -> newRecord.numberTimesPlayed);
		printf ("Load: Rating: %d\n\n", (*pHead) -> newRecord.rating);
		
		// pMem -> pPrev = pPrev;
 		// pCur = pCur -> pNext;
	} // end while loop to read until end of file

	// close the input file
	fclose (infile);
	*/

	return newRecord;

} // end loadARecord function