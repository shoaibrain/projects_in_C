//Name: Shoaib Rain
//Student ID: 1001825785
/* add needed includes */

/* add include guard */
#ifndef _FILELIB_H_
#define _FILELIB_H_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "MovieTheater.h"
void get_command_line_parameter(char *argv[], char ParamName[], char ParamValue[]);
FILE *OpenFile(char Filename[], char mode[3]);
void CloseFile(FILE *FileHandle);
void ReadMovieTheater(Seat MovieTheater[][MAX_COLS], FILE* InputFileHandle);
void WriteMovieTheater(Seat MovieTheater[][MAX_COLS], FILE* OutputFileHandle);

#endif