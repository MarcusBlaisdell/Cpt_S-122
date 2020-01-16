#ifndef BLAISDELL_PA2_V2_H
#define BLAISDELL_PA2_V2_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct songLength
{
	int minutes;
	int seconds;
} SongLength;

typedef struct Record
{
	char *artist;
	char *album;
	char *songTitle;
	char *genre;
	SongLength lengthOfSong;
	int numberTimesPlayed;
	int rating;
} Record;

typedef struct node
{
	Record newRecord;
	struct node *pNext;
} Node;

// makeNode function
// Node *makeNode (char *newArtist, char *album);
Node *makeNode (Record newRecord);

// void insertAtFront
// void insertAtFront (Node **pHead, char *newArtist, char *album);
void insertAtFront (Node **pHead, Record newRecord);
// void createRecords (Node **pHead);
void printList (Node *pHead);
Record loadARecord (FILE *theFile, Node **pHead);
void loadRecords (Node **pHead);

#endif