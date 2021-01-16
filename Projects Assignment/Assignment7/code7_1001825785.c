// Coding Assignment 7 Template

#include "FileLib.h"
#include "MovieTheater.h"
/* add include for ListLib.h */
#include "ListLib.h"
/* add include for StackLib.h */
#include "StackLib.h"
int main(int argc, char *argv[])
{
	Seat MovieTheater[MAX_ROWS][MAX_COLS] = {};
	int SeatNumber;
	char Row;
	int ArrayRow, ArrayCol;
	int NumberOfTickets = 0;
	int TicketStatus = 0;
	int i;
	char InputFilename[50] = {};
	char OutputFilename[50] = {};
	FILE *InputFileHandle = NULL;
	FILE *OutputFileHandle = NULL;
	char ReadMode[] = "r+";
	char WriteMode[] = "w";
	/* Create a pointer of type SNODE named TicketStack and set it to NULL */
	SNODE *TicketStack = NULL;
	/* Create a pointer of type NODE named LLH and set it to NULL */
	NODE *LLH = NULL;
	/* Create a pointer of type NODE named PickedTheater and set it to NULL */
	NODE *PickedTheater = NULL;
	int TheaterCount = 0;
	char answer[80] = {};

	get_command_line_parameter(argv, "INPUTFILENAME=", InputFilename);
	get_command_line_parameter(argv, "OUTPUTFILENAME=", OutputFilename);

	if (InputFilename[0] == '\0' || OutputFilename[0] == '\0')
	{
		printf("Must run program with two filenames...\n\n"
		       "./Code_xxxxxxxxxx.e INPUTFILENAME=yyyy OUTPUTFILENAME=zzzz\n");
		exit(0);
	}

	InputFileHandle = OpenFile(InputFilename, ReadMode);
	OutputFileHandle = OpenFile(OutputFilename, WriteMode);

	if (InputFileHandle == NULL || OutputFileHandle == NULL)
	{
		printf("Unable to open file...exiting\n");
		exit(0);
	}

	/* call CreateMovieTheaterLL and pass InputFileHandle and the address of LLH */
	CreateMovieTheaterLL(InputFileHandle,&LLH);

	do
	{
		/* Call DisplayAndPickMovieTheater and pass in LLH and capture the return value in PickedTheater */
		PickedTheater = DisplayAndPickMovieTheater(LLH);

		/* Call FillMovieTheater and pass in MovieTheater and PickedTheater */
	    FillMovieTheater(MovieTheater,PickedTheater);
		/* Call PrintSeatMap with MovieTheater and rows from PickedTheater and SeatsPerRow from PickedTheater */
		PrintSeatMap(MovieTheater,PickedTheater->rows,PickedTheater->SeatsPerRow);
		printf("\n\nHow many movie tickets do you want to buy? ");
		scanf("%d", &NumberOfTickets);
		getchar();

		for (i = 0; i < NumberOfTickets; i++)
		{
			do
			{
				do
				{
					printf("\nPick a seat (Row Seat) ");
					scanf(" %c%d", &Row, &SeatNumber);
					Row = toupper(Row);
					ArrayRow = (int)Row - 65;
					ArrayCol = SeatNumber - 1;
					getchar();

					if ((ArrayRow < 0 || ArrayRow >= PickedTheater->rows) ||
						(ArrayCol < 0 || ArrayCol >= PickedTheater->SeatsPerRow))
					{
						printf("\nThat is not a valid seat.  Please choose again\n\n");
					}
				}
				while ((ArrayRow < 0 || ArrayRow >= PickedTheater->rows) ||
					   (ArrayCol < 0 || ArrayCol >= PickedTheater->SeatsPerRow));

				TicketStatus = SeatAvailable(&MovieTheater[ArrayRow][ArrayCol]);

				switch (TicketStatus)
				{
					case ReadyForPurchase :
						SellSeat(&MovieTheater[ArrayRow][ArrayCol]);
						/* Call PushTickets with the address of TicketStack and MovieTheaterName from PickedTheater and Row and SeatNumber */
						PushTickets(&TicketStack,PickedTheater->MovieTheaterName,Row,SeatNumber);
						break;
					case AlreadySold :
						printf("\nSeat %c%d is not available.\n\n", Row, SeatNumber);
						break;
					default :
						printf("Not sure how we got here but we did!!");
				}

				/* Call PrintSeatMap with MovieTheater and rows from PickedTheater and SeatsPerRow from PickedTheater */
				PrintSeatMap(MovieTheater,PickedTheater->rows,PickedTheater->SeatsPerRow);
			}
			while (TicketStatus == AlreadySold);
		}

		if (NumberOfTickets)
		{
			/* Call UpdatePickedTheater with MovieTheater and PickedTheater */;
			UpdatePickedTheater(MovieTheater,PickedTheater);
		}

		printf("\n\nDo you want to buy tickets at a different theater? (Y/N) ");
		/* use fgets() to fill variable answer with whatever the user types at the prompt - do not hardcode the 2nd parameter */
		fgets(answer,sizeof(answer)-1,stdin);
		/* uppercase the first character of whatever was entered */
		answer[0] = toupper(answer[0]);
		
		
	}
	while ( answer[0] == 'Y');
	/* while the first character of answer is a Y */

	/* if TicketStack is not NULL */
	if (TicketStack != NULL)
	{	
		/* Call PrintTickets with the address of TicketStack */
		PrintTickets(&TicketStack);
	}

	/* Call WriteMovieTheaterLL with OutputFileHandle and the address of LLH and PickedTheater */
	WriteMovieTheaterLL(OutputFileHandle,&LLH,PickedTheater);
	/* Call FreeMovieTheaterLL with address of LLH */
	FreeMovieTheaterLL(&LLH);
	CloseFile(InputFileHandle);
	CloseFile(OutputFileHandle);

	return 0;
}