// Template for MovieTheater.c

#include "MovieTheater.h"

int SeatAvailable(Seat *Ticket)
{
	return Ticket->sold;
}

void SellSeat(Seat *SoldSeat)
{
	SoldSeat->sold = 1;
}

/* use your PrintSeatMap function from previous assignment except pass in row and column and use those in your for loops rather than MAX_ROW and MAX_COL */
/* add function PrintSeatMap using prototype information from .h file */
void PrintSeatMap(Seat MovieTheater[][MAX_COLS], int rows, int SeatsPerRow)
{
	int i, j;

	printf("\n\tX - sold\tO - available\n\n\t");
	
	/* for loop from 0 to the maximum number of columns (use define) */
	for (i = 0; i < SeatsPerRow; i++)
	{
		printf("Seat %d\t", i+1);
	}
	printf("\n");
	
	/* for loop from 0 to the maximum number of rows (use define) */
	for (i = 0; i < rows; i++)
	{
		/* for loop from 0 to the maximum number of columns (use define) */
		for (j = 0; j < SeatsPerRow; j++)
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
/* Remove function PrintTickets - you will be printing the tickets elsewhere */
