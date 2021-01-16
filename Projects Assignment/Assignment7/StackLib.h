/* StackLib.h Template */

/* add necessary includes */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* add include guard */
#ifndef _STACKLIB_H_
#define _STACKLIB_H_
typedef struct SNODE
{
    /* declare a char of size 4 named PurchasedSeat */
	char PurchasedSeat[4];
	/* declare a char pointer named MovieTheaterName */
	char *MovieTheaterName;
	/* declare a struct SNODE pointer named next_ptr */
	struct SNODE *next_ptr;
} 
SNODE;

void PushTickets(SNODE **StackTop, char MovieTheaterName[], char Row, int SeatNumber);
void PrintTickets(SNODE **);

#endif