#include "Blaisdell_PA2_v2.c"

int main (void)
{
	Node *pHead = NULL;

	// createRecords(&pHead);
	loadRecords(&pHead);

	printList (pHead);



	printf ("Artist (main): %s\n", pHead -> newRecord.artist);
	printf ("Album (main): %s\n", pHead -> newRecord.album);
	printf ("Artist (main -> pNext): %s\n", pHead -> pNext -> newRecord.artist);
	printf ("Album (main -> pNext): %s\n", pHead -> pNext -> newRecord.album);


	return 0;
}
