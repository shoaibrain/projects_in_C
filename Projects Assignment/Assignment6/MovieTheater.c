//Name: Shoaib Rain
//Student ID: 1001825785

/* add include for MovieTheater.h */

#include "MovieTheater.h"
#include "FileLib.h"
#include <ctype.h>


/* add function SeatAvailable using prototype information from .h file */
int SeatAvailable(Seat *Ticket)
{
	/* return the value of sold from the struct */
	return Ticket->sold;
	
}

/* add function SellSeat using prototype information from .h file */
void SellSeat(Seat *SoldSeat)
{
	/* set sold to 1 to indicate the the seat has been sold */
	SoldSeat->sold = 1;
}

/* add function PrintSeatMap using prototype information from .h file */
void PrintSeatMap(Seat MovieTheater[][MAX_COLS])
{
	int i, j;

	printf("\n\tX - sold\tO - available\n\n\t");
	
	/* for loop from 0 to the maximum number of columns (use define) */
	for (i = 0; i < MAX_COLS; i++)
	{
		printf("Seat %d\t", i+1);
	}
	printf("\n");
	
	/* for loop from 0 to the maximum number of rows (use define) */
	for (i = 0; i < MAX_ROWS; i++)
	{
		/* for loop from 0 to the maximum number of columns (use define) */
		for (j = 0; j < MAX_COLS; j++)
		{
			if (j == 0) 
			{	
				printf("Row %c\t", i+65);
			}
			
			/* if the sold member of a cell of MovieTheater is 1 */
			if (MovieTheater[i][j].sold == 1)
			{
				printf("X\t");
			}
			else
			{
				printf("O\t");
			}
		}
		printf("\n");
	}
}

/* add function PrintTickets using prototype information from .h file */
void PrintTickets(Seat Tickets[], int NumberOfTickets)
{
	/* print out all of the tickets as shown in the sample output */
	printf("Here's your tickets. Enjoy your movie!\n");
	int i = 0;
	for(i; i< NumberOfTickets; i++)
	{
		printf(" ___________\n|\t    |\n|  Seat %c%d  |\n|___________|\n",Tickets[i].SeatRow, Tickets[i].SeatNumber);
				

	}
	
}













