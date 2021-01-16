//Name: Shoaib Rain
//Student ID: 1001825785

/* add an include for FileLib.h and MovieTheater.h */
#include "FileLib.h"
#include "MovieTheater.h"
#include <ctype.h>
int main(int argc, char *argv[] /* add arguments needed to use command line arguments */)
{
	/* declare a 2D array called MovieTheater of type Seat of size MAX_ROWS by MAX_COLS   */
	/* and initialize to nulls/zeroes                                                     */
	Seat MovieTheater[MAX_ROWS][MAX_COLS] = {};
	
	/* declare a 1D array called Tickets of type Seat - this array should be able to hold */
	/* as many tickets as are available in the theater - do NOT hardcode a value  - and   */
	/* initialize to nulls/zeroes                                                         */
	Seat Tickets[MAX_ROWS*MAX_COLS] = {};

	int SeatNumber;
	char Row;
	int ArrayRow, ArrayCol;
	int NumberOfTickets = 0;
	int TicketStatus = 0;
	/* declare a char array of size 50 called InputFilename and set to {}                 */
	char InputFilename[50] = {};
	/* declare a char array of size 50 called OutputFilename and set to {}                */
	char OutputFilename[50] = {};
	/* declare a variable of type FILE * named InputFileHandle and set to NULL            */
	FILE *InputFileHandle = NULL;
	/* declare a variable of type FILE * named OutputFileHandle and set to NULL           */
	FILE *OutputFileHandle = NULL;
	/* declare a char array named ReadMode and initialize it to "r+"                      */
	char ReadMode[3] = "r+";
	/* declare a char array named WriteMode and initialize it to "w"                      */
	char WriteMode[3] = "w";
	/* call get_command_line_parameter with argv and "INPUTFILENAME" and InputFilename    */
	get_command_line_parameter(argv, "INPUTFILENAME=", InputFilename);
	/* call get_command_line_parameter with argv and "OUTPUTFILENAME" and OutputFilename  */
	get_command_line_parameter(argv, "OUTPUTFILENAME=", OutputFilename);
	/* if the first character of the InputFilename is the null character OR */
	/* the first character of the OutputFilename is the null character      */
	if (InputFilename[0] == '\0' || OutputFilename[0] == '\0')
	{
		printf("Must run program with two filenames...\n\n"
		       "./Code_xxxxxxxxxx.e INPUTFILENAME=yyyy OUTPUTFILENAME=zzzz\n");
		/* exit the program */
		exit(0);
	}
	
	/* Call function OpenFile to open the InputFilename in ReadMode and capture the return value in InputFileHandle */
	InputFileHandle = OpenFile(InputFilename,ReadMode);
	/* Call function OpenFile to open the OutputFilename in WriteMode and capture the return value in OutputFileHandle */
	OutputFileHandle = OpenFile(OutputFilename, WriteMode);
	/* if the input or output file handle is NULL, then print the message shown in */
	/* the sample output and exit.                                                 */
	if (InputFileHandle == NULL || OutputFileHandle == NULL)
	{
		printf("No such file or directory.\nUnable to open file...existing.\n");
		exit(0);
	}

	/* Call function ReadMovieTheater and pass in the 2d array MovieTheater and the input file handle */
	ReadMovieTheater(MovieTheater,InputFileHandle);

	/* Call function PrintSeatMap and pass the 2d array MovieTheater */
    PrintSeatMap(MovieTheater);
	printf("\n\nHow many movie tickets do you want to buy? ");
	/* use scanf() to get the NumberOfTickets */
	scanf("%d",&NumberOfTickets);
	/* use variable i to create a for loop for the number of tickets */
	int i,j;
	for (i = 0; i < NumberOfTickets; i++)
	{
		do
		{
			do
			{
				printf("\nPick a seat (Row Seat) ");
				scanf(" %c%d", &Row, &SeatNumber);
				/* uppercase variable Row */
				Row = toupper(Row);
				/* Set variable ArrayRow equal to Row cast to int minus 65 */
				ArrayRow = (int) Row - 65;
				/* Set variable ArrayCol to SeatNumber minus 1 */
				ArrayCol = SeatNumber -1;
				/* if ArrayRow is less than 0 OR greater than or equal to MAX_ROWS OR */
				/*    ArrayCol is less than 0 OR greater than or equal to MAX_COLS    */
				if ((ArrayRow < 0 || ArrayRow >= MAX_ROWS) || (ArrayCol < 0 || ArrayCol >= MAX_COLS))
				{
					printf("\nThat is not a valid seat.  Please choose again\n\n");
				}		
			}
			/* while ArrayRow is less than 0 OR greater than or equal to MAX_ROWS OR */
			/*       ArrayCol is less than 0 OR greater than or equal to MAX_COLS    */
			while ((ArrayRow < 0 || ArrayRow >= MAX_ROWS) || (ArrayCol < 0 || ArrayCol >= MAX_COLS));
			/* Call SeatAvailable with the address of a single cell of 2d array MovieTheater */
			/* Capture the return value of function SeatAvailable in variable TicketStatus   */
			TicketStatus =  SeatAvailable(&MovieTheater[ArrayRow][ArrayCol]);
			
			
		
			switch (TicketStatus)
			{
				case ReadyForPurchase :
					/* Call function SellSeat and pass in the address of a single cell of the 2d array MovieTheater */
					/* Set Tickets[i] equal to the cell from MovieTheater that was just purchased */
					SellSeat(&MovieTheater[ArrayRow][ArrayCol]);
					Tickets[i] = MovieTheater[ArrayRow][ArrayCol];
					break;
				case AlreadySold :
					printf("\nSeat %c%d is not available.\n\n", Row, SeatNumber);
					break;
				default :
					printf("Not sure how we got here but we did!!");
			}

			/* Call function PrintSeatMap and pass the 2d array MovieTheater */
			PrintSeatMap(MovieTheater);
		}
		while(TicketStatus == AlreadySold);
		/* while TicketStatus has a value of AlreadySold */
	}

	/* Call function PrintTickets - pass in array Tickets and the number of tickets */
	PrintTickets(Tickets,NumberOfTickets);
	/* Call function WriteMovieTheater - pass in the 2d array MovieTheater and the output file handle */
	WriteMovieTheater(MovieTheater, OutputFileHandle);
	/* Call function CloseFile to close the input file */
	CloseFile(InputFileHandle);
	/* Call function CloseFile to close the output file */
	CloseFile(OutputFileHandle);
	return 0;
}
