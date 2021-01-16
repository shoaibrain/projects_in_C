// FileLib.h template

/* add necessary includes */

/* add include guard */
#ifndef _FILELIB_H_
#define _FILELIB_H_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void get_command_line_parameter(char *argv[], char ParamName[], char ParamValue[]);
FILE *OpenFile(char Filename[], char mode[3]);
void CloseFile(FILE *FileHandle);

#endif