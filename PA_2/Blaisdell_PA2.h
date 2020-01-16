#ifndef BLAISDELL_PA2
#define BLAISDELL_PA2

#define _CRT_SECURE_NO_WARNINGS

	// libraries:

#include <stdio.h>
#include <stdlib.h> // for malloc
#include <string.h>

	// declare structs:

// song length:

typedef struct songLength
{
	int minutes;
	int seconds;
} SongLength;

// record attributes:

// I really tried to do this using pointers but everytime it would load records from the file,
// the pointer would change pHead to the value that just got read in. I tried to go to the 
// ACM after Hackathon on Sunday (which I participated in, from 9am Saturday to 12pm Sunday) 
// but there were no TA's there so I changed all of these to arrays
typedef struct record
{
	char artist[100];
	char albumTitle[100];
	char songTitle[100];
	char genre[100];
	SongLength lengthOfSong;
	int numberTimesPlayed;
	int rating;
} Record;

typedef struct node
{
	Record entry;
	struct node *pNext;
	struct node *pPrev;
} Node;

	// function prototypes:

// make a record
Node *makeNode (Record newEntry);

// insert at front function
void insertAtFront (Node **pHead, Node *pMem);

// print the entire list
void printList (Node *pHead);

// load records from file
void loadRecords (Node **pHead);

// store records to file
void storeRecords (Node **pHead);

// display records to the screen based on a search field 
// one function for each option:

void displayRecordsMenu (Node *pHead);
void displayRecordsArtist (Node *pHead);
void displayRecordsAlbum (Node *pHead);
void displayRecordsSong (Node *pHead);
void displayRecordsGenre (Node *pHead);
void displayRecordsLength (Node *pHead);
void displayRecordsPlayCount (Node *pHead);
void displayRecordsRating (Node *pHead);
void displayRecordsAll (Node *pHead);

// insert new records
void insertRecords (Node **pHead);

// delete records
void deleteRecords (Node **pHead);

// edit a record
void editRecords (Node **pHead);

// rate a song
void rateRecords (Node **pHead);

// insert new data in alphabetical order:
void insertInOrder (Node **pHead, Record newData);

#endif