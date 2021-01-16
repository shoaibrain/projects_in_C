// MovieTheater Template

/* add necessary includes */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* add include guard */
#ifndef _MOVIE_THEATER_H_
#define _MOVIE_THEATER_H_
/* add a define called MAX_COLS and set to 10 */
#define MAX_COLS 10
/* add a define called MAX_ROWS and set to 10 */
#define MAX_ROWS 10

typedef struct
{
	int SeatNumber;
	char SeatRow;
	int sold;
} 
Seat;

enum
{
	ReadyForPurchase, AlreadySold
};

int SeatAvailable(Seat *Ticket);
void SellSeat(Seat *SoldSeat);
void PrintSeatMap(Seat MovieTheater[][MAX_COLS], int rows, int SeatsPerRow);

#endif