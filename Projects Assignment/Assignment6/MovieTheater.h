//Name: Shoaib Rain
//Student ID: 1001825785

/* add necessary includes */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* add include guard */
#ifndef _MOVIE_THEATER_H_
#define _MOVIE_THEATER_H_
/* add a define for MAX_COLS and set to 4 */
#define MAX_COLS 4
/* add a define for MAX_ROWS and set to 6 */
#define MAX_ROWS 6
typedef struct
{
	/* declare an integer variable named SeatNumber */
	int SeatNumber;
	/* declare a character variable named SeatRow */
	char SeatRow;
	/* declare an integer variable named sold */
	int sold;
} 
Seat;

enum
{
	ReadyForPurchase, AlreadySold
};

int SeatAvailable(Seat *Ticket);
void SellSeat(Seat *SoldSeat);
void PrintSeatMap(Seat MovieTheater[][MAX_COLS]);
void PrintTickets(Seat Tickets[], int NumberOfTickets);

#endif