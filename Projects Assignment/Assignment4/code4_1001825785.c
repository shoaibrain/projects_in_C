//Name: Shoaib Rain
//Student ID: 1001825785
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <ctype.h> 
#include "DrawTool.h"

int main (void)
{
	//Declare 2d array with max size of 20/MAXMAPSIZE
	char array_canvas[MAXMAPSIZE ][MAXMAPSIZE ] = {};
	//variables for array size and background character from user
	int user_choice;
	char background_char;
	
	//Call initialize map from DrawTool
	InitializeMap(array_canvas,&user_choice);
	
	//Call print function from DrawTool
	PrintInstructions();
	
	//Call function to PrintMap() from DrawTool
	PrintMap(array_canvas,user_choice);
	
	char quit;
	char draw_command[20];
	
	//direction is a variable for P/V/H
	char direction[2], mark[2];
	//(row,col) is start point on array_canvas 
	// range is how far it goes
	char row[4],col[4],range[4];
	int r,c,rng;
	
	char *Token;
	
	do
	{
		//Ask the user for draw command
		printf("Enter draw command (enter Q to quit)");
		fgets(draw_command,20,stdin);
		quit = draw_command[0];
		//Check if draw command is to quit
		if (quit == 'Q' || quit == 'q')
			quit = 'Q';
		
		else
		{
			//String tok for direction
			Token = strtok(draw_command, "(),");
			//Assign to direction
			strcpy(direction,Token);
			//String tok for row
			Token = strtok(NULL, "(),");
			//Assign to row
			r = atoi(strcpy(row,Token));
			//String tok for col
			Token = strtok(NULL, "(),");
			//Assign to col
			c = atoi(strcpy(col, Token));
			//String tok for range
			Token = strtok(NULL,"(),");
			//Assign to range
			rng = atoi(strcpy(range, Token));
			//String tok for mark
			Token = strtok(NULL, "(),");
			//Assign to mark
			if (*Token == '\n')
				mark[0] = 'X';
			else
			    strcpy(mark,Token);	
						
			//Convert p,v,h to Uppercase
			direction[0] = toupper(direction[0]);
			
			//Validate draw command
	        if (direction[0] != 'P' && direction[0] != 'V' && direction[0] != 'H')
			{
				printf("That draw command is unknown\n");
			}
						
			if (direction[0] == 'P' && (r < 0 || r > user_choice-1 || c < 0 || c > user_choice-1))
				printf("That draw command is out of range\n");
			else if (direction[0] == 'P')
				array_canvas[r][c] = mark[0];
			
			else if (direction[0] == 'V' && ((r < 0 || r > user_choice-1) || (c < 0 || c > user_choice-1) || (rng <0 || rng > user_choice-1)))
			{
				printf("That draw command is out of range\n");
			}
			else if (direction[0] == 'H' && ((r < 0 || r > user_choice-1) || (c < 0 || c > user_choice-1) || (rng <0 || rng > user_choice-1)))
			{
				printf("That draw command is out of range\n");
			}
			//For point Command
			else
			{
				//Draw line in vertical or horizontal
				DrawLine(array_canvas,r,c,direction[0],rng,mark[0]);
			}	
			PrintMap(array_canvas,user_choice);

		}
	
	}
	while (quit != 'Q');
	
	return 0;
}