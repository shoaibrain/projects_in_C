//Name: Shoaib Rain
//Student ID: 1001825785
/*add include for FileLib.h */
#include "FileLib.h"
#include "MovieTheater.h"
#include <ctype.h>
void get_command_line_parameter(char *argv[], char ParamName[], char ParamValue[])
{
	int i  = 0; 
	
	while (argv[++i] != NULL)
	{
		if (!strncmp(argv[i], ParamName, strlen(ParamName)))
		{
			strcpy(ParamValue, strchr(argv[i], '=') + 1);
		}
	}
	
	return;
}

/* add function OpenFile based on information from prototype in .h file */
FILE *OpenFile(char Filename[], char mode[3])
{
	/* declare a variable named FileHandle of type FILE * and set to NULL */
	FILE *FileHandle = NULL;
	/* call fopen() with Filename and mode and capture the result in FileHandle */
    FileHandle = fopen(Filename, mode);
	/* if the FileHandle is NULL */
	if (FileHandle == NULL)
	{
		/* call perror() with the message "File did not open" */
		 perror ("File did not open.");
	}
	
	/* return file handle */
	return FileHandle;
}

/* add function CloseFile based on information from prototype in .h file */
void CloseFile(FILE *FileHandle)
{
	/* call fclose() with passed in file handle */
	fclose(FileHandle);
}

/* add function ReadMovieTheater based on information from prototype in .h file */	
void ReadMovieTheater(Seat MovieTheater[][MAX_COLS], FILE* InputFileHandle)
{
	int x = 0, y = 0, z = 0;
	char Buffer[500] = {};
	
	/* use fgets() to read into array Buffer from passed in file handle.  */
	/* Do NOT hardcode the 2nd parameter of fgets()                       */
    fgets(Buffer, sizeof(Buffer)-1, InputFileHandle);
	/* for loop from 0 to the maximum number of rows (use define) */
	for (x = 0; x < MAX_ROWS; x++)
	{
		/* for loop from 0 to the maximum number of columns (use define) */
		for (y = 0; y < MAX_COLS; y++)
		{
			MovieTheater[x][y].sold = Buffer[z++]-48;
			MovieTheater[x][y].SeatRow = x+65; 
			MovieTheater[x][y].SeatNumber = y+1;
		}
	}	

}

/* add function WriteMovieTheater based on information from prototype in .h file */
void WriteMovieTheater(Seat MovieTheater[][MAX_COLS], FILE* OutputFileHandle)
{
	int x = 0, y = 0, z = 0;

	/* for loop from 0 to the maximum number of rows (use define) */
	for (x = 0; x < MAX_ROWS; x++)
	{
		/* for loop from 0 to the maximum number of columns (use define) */
		for (y = 0; y < MAX_COLS; y++)
		{
			/* use fprintf() to write out the sold value from each cell of MovieTheater */
			fprintf(OutputFileHandle,"%d",MovieTheater[x][y].sold);
		}
	}	
}
























