// ListLib.h Template

/* add necessary includes */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "StackLib.h"
#include "MovieTheater.h"

/* add include guard */
#ifndef _LISTLIB_H_
#define _LISTLIB_H_
typedef struct node
{
	/* declare a char pointer named MovieTheaterName */
	char *MovieTheaterName;
	/* declare a char pointer named MovieTheaterSeatMap; */
	char *MovieTheaterSeatMap;
	/* declare an integer named rows */
	int rows;
	/* declare an integer named SeatsPerRow */
	int SeatsPerRow;
	/* declare a struct node pointer named next_ptr */
	struct node *next_ptr;
}
NODE;

void FillMovieTheater(Seat MovieTheater[][MAX_COLS], NODE *Theater);
void CreateMovieTheaterLL(FILE *InputFileHandle, NODE **LLH);
NODE *DisplayAndPickMovieTheater(NODE *LLH);
void UpdatePickedTheater(Seat MovieTheater[][MAX_COLS], NODE *PickedTheater);
void WriteMovieTheaterLL(FILE *OutputFileHandle, NODE **LLH, NODE *PickedTheater);
void FreeMovieTheaterLL(NODE **LLH);


#endif