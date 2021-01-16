// ListLib.c Template

/* add necessary include */
#include "FileLib.h"
#include "ListLib.h"
#include "MovieTheater.h"
#include "StackLib.h"
#include <ctype.h>

/* set return value based on prototype */void CreateMovieTheaterLL(FILE *InputFileHandle, NODE **LLH/* add parameters based on prototype */)
{
	/* declare a char array of size 500 named MovieLine and set it to {} */
	char MovieLine[500] = {};
    /* declare pointers named TempPtr and NewNode of type NODE */
	NODE *TempPtr;
	NODE *NewNode;
    /* declare a char pointer named Token for use with strtok() */
	char *Token;

	while ( fgets(MovieLine,sizeof(MovieLine)-1,InputFileHandle)/* use fgets() to read from the passed file handle into variable MovieLine - do not hardcode 2nd parameter */)
	{
		/* use malloc with the sizeof of NODE and store the resulting pointer in NewNode */
		NewNode = malloc(sizeof(NODE));
		/* Set NewNode's next_ptr to NULL */
		NewNode->next_ptr = NULL;
		/* use strtok() on MovieLine with a delimiter of | */
		Token = strtok(MovieLine, "|");
		/* in one line of code, call malloc() and store the resulting pointer in NewNode's MovieTheaterName - do not hardcode the number of bytes passed to malloc() */
		NewNode->MovieTheaterName = malloc(strlen(Token)*sizeof(char)+1);
		/* copy Token into NewNode's MovieTheaterName */
		strcpy(NewNode->MovieTheaterName,Token);

		/* use strtok() again */
		Token = strtok(NULL, "|");
		/* in one line of code, call malloc() and store the resulting pointer in NewNode's MovieTheaterSeatMap - do not hardcode the number of bytes passed to malloc() */
		NewNode->MovieTheaterSeatMap = malloc(strlen(Token)*sizeof(char)+1);
		/* copy Token into NewNode's MovieTheaterSeatMap */
		strcpy(NewNode->MovieTheaterSeatMap,Token);
		/* use strtok() again */
		Token = strtok(NULL, "|");
		/* use atoi() on Token and store the result in rows in NewNode */
		NewNode->rows = atoi(Token);

		/* use strtok() again */
		Token = strtok(NULL, "|");
		/* use atoi() on Token and store the result in SeatsPerRow in NewNode */
		NewNode->SeatsPerRow = atoi(Token);
		/* if dereferenced LLH is NULL */
		if (*LLH == NULL)
		{
			/* set dereferenced LLH equal to NewNode */
			*LLH = NewNode;
		}
		else
		{
			/* set TempPtr equal to the dereferenced LLH */
			TempPtr = *LLH;

			/* while TempPtr's next_ptr is not NULL */
			while (TempPtr->next_ptr != NULL)
			{
				/* set TempPtr equal to TempPtr's next_ptr */
				TempPtr = TempPtr->next_ptr;
			}
			/* Set TempPtr's next_ptr equal to NewNode */
			TempPtr->next_ptr = NewNode;
			
		}
	}
}

/* set return value based on prototype */ NODE *DisplayAndPickMovieTheater(NODE *LLH/* add parameter based on prototype */)
{
	int MenuChoice = 0;
	int TheaterCount = 0;
	int NodeCount = 0;
	/* Create a pointer of type NODE named TempPtr and set it equal to LLH */
	NODE *TempPtr = LLH;

	/* while TempPtr is not equal to NULL */
	while (TempPtr != NULL)
	{
		printf("%d.\t%s\n", ++TheaterCount, TempPtr->MovieTheaterName /* TempPtr's MovieTheaterName */);
		/* Set TempPtr equal to TempPtr's next_ptr */
		TempPtr = TempPtr->next_ptr;
	}

	do
	{
		printf("\n\nPick a theater ");
		scanf("%d", &MenuChoice);

		if (MenuChoice < 1 || MenuChoice > TheaterCount)
		{
			printf("\n\nInvalid choice\n\n");
		}
	}
	while (MenuChoice < 1 || MenuChoice > TheaterCount);

	/* Set TempPtr equal to LLH */
	TempPtr = LLH;
	while(TempPtr != NULL && NodeCount++ != MenuChoice-1)
	{
		/* Set TempPtr equal to TempPtr's next_ptr */
		TempPtr = TempPtr->next_ptr;
	}

	return TempPtr;
}

/* set return value based on prototype */void FillMovieTheater(Seat MovieTheater[][MAX_COLS], NODE *Theater/* add parameters based on prototype */)
{
	int x = 0, y = 0, z = 0;

	for (x = 0; x < Theater->rows/* Theater's rows */; x++)
	{
		for (y = 0; y < Theater->SeatsPerRow/* Theater's SeatsPerRow */; y++)
		{
			MovieTheater[x][y].sold = Theater->MovieTheaterSeatMap[z++]-48;
			MovieTheater[x][y].SeatRow = x+65;
			MovieTheater[x][y].SeatNumber = y+1;
		}
	}
}

/* set return value based on prototype */void UpdatePickedTheater(Seat MovieTheater[][MAX_COLS], NODE *PickedTheater)
{
	int x = 0, y = 0, z = 0;

	for (x = 0; x <PickedTheater->rows /* PickedTheater's rows */; x++)
	{
		for (y = 0; y < PickedTheater->SeatsPerRow/* PickedTheater's SeatsPerRow */; y++)
		{
			PickedTheater->MovieTheaterSeatMap[z++] = MovieTheater[x][y].sold+48;
		}
	}
}

/* set return value based on prototype */void WriteMovieTheaterLL(FILE *OutputFileHandle, NODE **LLH, NODE *PickedTheater/* add parameters based on prototype */)
{
	/* Create a pointer of type NODE named TempPtr and set it equal to dereferenced LLH */
	NODE *TempPtr = *LLH;

	/* while TempPtr is not equal to NULL */
	while(TempPtr != NULL)
	{
		/* if TempPtr is equivalent to PickedTheater */
		if(TempPtr == PickedTheater)
		{
			fprintf(/* passed in file handle */OutputFileHandle, "%s|%s|%d|%d\n",
					/* PickedTheater's MovieTheaterName */PickedTheater->MovieTheaterName, /* PickedTheater's MovieTheaterSeatMap */PickedTheater->MovieTheaterSeatMap,
					/* PickedTheater's rows */PickedTheater->rows, /* PickedTheater's SeatsPerRow */PickedTheater->SeatsPerRow);
		}
		else
		{
			fprintf(/* passed in file handle */OutputFileHandle, "%s|%s|%d|%d\n",
					/* TempPtr's MovieTheaterName */TempPtr->MovieTheaterName, /* TempPtr's MovieTheaterSeatMap */TempPtr->MovieTheaterSeatMap,
					/* TempPtr's rows */TempPtr->rows, /* TempPtr's SeatsPerRow */TempPtr->SeatsPerRow);
		}

		/* Set TempPtr equal to TempPtr's next_ptr */
		TempPtr = TempPtr->next_ptr;
	}
}

/* set return value based on prototype */void FreeMovieTheaterLL(NODE **LLH/* add parameter based on prototype */)
{
	/* declare a pointer named TempPtr of type NODe and initialize it to the dereferenced LLH */
	NODE *TempPtr = *LLH;

	while (TempPtr != NULL/* TempPtr is not equal to NULL */)
	{
		/* use free() to release the memory reserved for TempPtr's MovieTheaterName */
		free(TempPtr->MovieTheaterName);
		/* use free() to release the memory reserved for TempPtr's MovieTheaterSeatMap */
		free(TempPtr->MovieTheaterSeatMap);
		*LLH = (*LLH)->next_ptr;
		/* use free() to release the memory reserved for TempPtr */
		free(TempPtr);
		/* set TempPtr equal to the dereferenced LLH */
		TempPtr = *LLH;
	}
}




