/* StackLib.c Template */

/* add necessary includes */
 #include "StackLib.h"
 #include "MovieTheater.h"
 #include "ListLib.h"
 #include "FileLib.h"
 #include <ctype.h>
/* set return value based on prototype */void PushTickets(SNODE **StackTop, char MovieTheaterName[], char Row, int SeatNumber/* add parameters based on prototype */)
{
	/* in one line of code, declare a pointer named NewNode of type SNODE and initialize to */
	/* the return value of malloc() where malloc() is asked for sizeof() SNODE memory       */
    SNODE *NewNode = malloc(sizeof(SNODE));
	/* in one line of code, set NewNode's MovieTheaterName equal to the pointer returned by */
	/* calling malloc() and asking for enough memory to hold MovieTheaterName + 1 */
	NewNode->MovieTheaterName = malloc(strlen(MovieTheaterName)+1); 
	/* copy MovieTheaterName into NewNode's MovieTheaterName */
	strcpy(NewNode->MovieTheaterName,MovieTheaterName);
	/* use sprintf() to combine Row and SeatNumber into NewNode's PurchasedSeat */
	sprintf(NewNode->PurchasedSeat,"%c%d",Row,SeatNumber);
	/* Set NewNode's next_ptr equal to NULL */
	NewNode->next_ptr = NULL;
	
	/* if dereferenced StackTop is NULL */
	if (*StackTop == NULL)
	{
		/* Dereference StackTop and set it equal to NewNode */
		*StackTop = NewNode;
	}
	else
	{
		/* Set NewNode's next_ptr equal to dereferenced StackTop */
		NewNode->next_ptr = *StackTop;
		/* Dereference StackTop and set it equal to NewNode */
		*StackTop = NewNode;
    }
}

/* set return value based on prototype */void PrintTickets(SNODE **StackTop/* add parameter based on prototype */)
{
	/* in one line of code, create a pointer named TempPtr of type SNODE and set it equal */
	/* to (*StackTop)->next_ptr                                                           */
	SNODE *TempPtr = (*StackTop)->next_ptr; 

	printf("\n\nHere's your tickets.  Enjoy your movie!!\n\n");

	/* while dereferenced StackTop is not NULL */
	while (*StackTop != NULL)
	{
		/* print out                         */
		/* (*StackTop)->MovieTheaterName     */
		printf("%s %s\n",(*StackTop)->MovieTheaterName,(*StackTop)->PurchasedSeat);
		/* (*StackTop)->PurchasedSeat        */
		//printf("%s\n",(*StackTop)->PurchasedSeat);
	
		/* for the assignment, format the ticket output however you want */
		
		/* For a 10 point bonus, format the ticket output like shown in the video.  */
		/* Notice that the movie theater name is centered no matter how long it is. */
		/* You will have to figure out how to do that without hardcoding values.    */

		/* Set TempPtr equal to (*StackTop)->next_ptr */
		TempPtr = (*StackTop)->next_ptr;
		/* free dereferenced StackTop */
		free(*StackTop);
		/* Dereference StackTop and set equal to TempPtr */
		*StackTop = TempPtr;
	}
}
