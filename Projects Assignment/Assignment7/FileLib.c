// Template for FileLib.c - same file as previous assignment - just remove ReadMovieTheater and WriteMovieTheater - those will be done elsewhere

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

FILE *OpenFile(char Filename[], char mode[3])
{
	FILE *FileHandle = NULL;

	FileHandle = fopen(Filename, mode);
	if (FileHandle == NULL)
	{
		perror("File did not open ");
	}
	return FileHandle;
}

void CloseFile(FILE *FileHandle)
{
	fclose(FileHandle);
}

