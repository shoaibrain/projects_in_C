//Name: Shoaib Rain
//Student ID: 1001825785
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

//Functions Prototype
int get_random(int low,int high);
void print_grid(int arr[5][5]);
int contains(int num, int arr[25]);
void populate_board(int arr[5][5]);
int pick_number (int bank[], int counter);
int num_exist(int number, int bingo_array[5][5]);
int is_row_complete(int bingo_card[5][5]);
int is_col_complete(int bingo_card[5][5]);
int is_diagonal_1(int bingo_card[5][5]);
int is_diagonal_2(int bingo_card[5][5]);

// This function prints the game board
void print_grid(int arr[5][5])
{
    char name[5] = {'B', 'I','N', 'G', 'O'};
    int i,j;

    printf("\n");
    for (i = 0; i < 5; i++)
    {
        printf("   %c   ", name[i]);
    }
    printf("\n------------------------------------");
    printf("\n");
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (arr[i][j] == 0)
            {
                printf("|   X  ");
            }
            else printf("|%4d  ",arr[i][j]);
        }

        printf("|\n");
        printf("------------------------------------\n");
    }
}

//Function to check if array arr contains a number num
int contains(int num, int arr[25])
{
    int found = 0,i=0;
    do
    {
        if (arr[i] == num)
        {
            found =1;
        }
        i++;
    }
    while (i < 25 && found == 0);
    return found;
}

//Function to populate the game board with random number
void populate_board(int arr[5][5])
{
    int bank[25] = {};
    int i,j;
    int counter = 0;
    int random_number;
    int dup = 1;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        { 
            if  (j == 0)
            {   
                //Get random number for B column in range(1,15) inclusive
                random_number = get_random(1,15);
         
                //Do this while random_number is duplicate
                do
               {
                   //If true then newly generated random num is already in bank array           
                   if (contains(random_number, bank))
                   {
                       //get new random number since previous one was already been generated
                       random_number = get_random(1,15);
                   }
                   //random_number is unique
                   else dup = 0;
               }
               while (dup == 1);
               dup =1;
               //Save random_number in bank array
               bank[counter] = random_number;
               //  Save random number in game board
               arr[i][j] = random_number;
               //Increase counter for bank array
               counter++;
          
            } 
            else if (j == 1) 
            {    
            //Get random number for B column in range(1,15) inclusive
            random_number = get_random(16,30);
            //Do this while random_number is duplicate
            do
            {
                //If true then newly generated random num is already in bank array           
                if (contains(random_number, bank))
                {
                    //  get new random number since previous one was already been generated
                    random_number = get_random(16,30);
                }
                //random_number is unique
                else dup = 0;
            }
            while (dup == 1);
            dup =1;        
            //Save random_number in bank array
            bank[counter] = random_number;
            //Save random number in game board
            arr[i][j] = random_number;
            //Increase counter for bank array
            counter++;
          
            } 
       
            else if (j == 2)
            {   
                //Get random number for B column in range(1,15) inclusive
                random_number = get_random(31,45);
                //Do this while random_number is duplicate
                do
                {
                    //If true then newly generated random num is already in bank array           
                    if (contains(random_number, bank))
                    {
                        //get new random number since previous one was already been generated
                        random_number = get_random(31,45);
                    }
                    //random_number is unique
                    else dup = 0;
                }
                while (dup == 1);
                dup =1;
         
          
                //Save random_number in bank array
                bank[counter] = random_number;
                //Save random number in game board
                arr[i][j] = random_number;
                //Increase counter for bank array
                counter++;
            } 
            else if (j == 3)
            {   
                //Get random number for B column in range(1,15) inclusive
                random_number = get_random(46,60);
                //Do this while random_number is duplicate
                do
                {
                    //If true then newly generated random num is already in bank array           
                    if (contains(random_number, bank))
                    {
                        //get new random number since previous one was already been generated
                        random_number = get_random(46,60);
                    }
                    //random_number is unique
                    else dup = 0;
                }
                while (dup == 1);
                dup =1;       
                //Save random_number in bank array
                bank[counter] = random_number;
                //Save random number in game board
                arr[i][j] = random_number;
                //Increase counter for bank array
                counter++;
          
            }   
            else if (j == 4)
            {   
                //Get random number for B column in range(1,15) inclusive
                random_number = get_random(61,75);
                //Do this while random_number is duplicate
                do
                {
                    //If true then newly generated random num is already in bank array           
                    if (contains(random_number, bank))
                    {
                        //get new random number since previous one was already been generated
                        random_number = get_random(61,75);
                    }
                    //random_number is unique
                    else dup = 0;
                }
                while (dup == 1);
                dup =1;
                //Save random_number in bank array
                bank[counter] = random_number;
                //Save random number in game board
                arr[i][j] = random_number;
                //Increase counter for bank array
                counter++;
          
            }  
     }
   }
   //element at position [2][2] is always zero
   arr[2][2] = 0;
}

//Function to generate a random number between start,end (inclusive)
int get_random(int low,int high)
{   
    
    int random;
    random = (rand() % (high + 1 - low)) + low;
    return random;
}
// Function for picking a number
int pick_number (int bank[], int counter)
{
    //nt counter = 0;
    int random_number;
    int dup = 1;
    random_number = get_random(1, 75);
    do
    {
        if (contains(random_number, bank))
        {
            random_number = get_random(1, 75);
        }
        else dup = 0;
    }
    while (dup ==1);
    bank[counter] = random_number;
    //Print random nunber
    if (random_number >=1 && random_number<=15)
    {
        printf("\nThe next number is B%d\n\n", random_number);
    }
    else if (random_number >=16 && random_number <= 30)
    {
        printf("\nThe next number is I%d\n\n", random_number);
    }
    else if (random_number >=31 && random_number <= 45)
    {
        printf("\nThe next number is N%d\n\n", random_number);
    }
    if (random_number >=46 && random_number <= 60)
    {
        printf("\nThe next number is G%d\n\n", random_number);
    }
    else if (random_number >= 61 && random_number<=75)
    {
        printf("\nThe next number is O%d\n\n", random_number);
    }
    return random_number;

}
//Function to check if the number exists in the Bingo game board
int num_exist(int number, int bingo_array[5][5])
{
    int i,j;
    int exist =0;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {   
	        //Number is present in bingo card
            if (bingo_array[i][j] == number)
            {
                bingo_array[i][j] = 0;
                exist =1;
            }
        }
    }
    //number is not present in bingo card
    return exist;
}
//Function to check if the row is complete
int is_row_complete(int bingo_card[5][5])
{
    int row, col;
    int ans[5] = {};
    int is_complete;
    for (row = 0; row < 5; row++)
    { 
        is_complete = 1;
        for (col = 0; col < 5; col++)
        {
            if (bingo_card[row][col] != 0)
            {
                is_complete = 0; 
                col = 5;
            }
            ans[row] = is_complete;
        }
    
    }
    int k =0;
    int flag = 0;
    do
    {
        if (ans[k] == 1)
        {
            flag =1;
        }
        k++;
    }
    while (k < 5);
    return flag;
}
//Function to check if column is complete
int is_col_complete(int bingo_card[5][5])
{
    int row, col;
    int ans[5] = {};
    int is_complete;
    for (row = 0; row < 5; row++)
    { 
        is_complete = 1;
        for (col = 0; col < 5; col++)
        {
            if (bingo_card[col][row] != 0)
            {
                is_complete = 0; 
                col = 5;
            }
            ans[row] = is_complete;
        }
    
    }
    int k =0;
    int flag = 0;  
    do
    {
        if (ans[k] == 1)
        {
            flag =1;
        }
        k++;
    }
    while (k < 5);
    return flag;
  
}
//Function to check if the diagonal from top left is complete
int is_diagonal_1(int bingo_card[5][5])
{
    int row, col;
    int ans[5] = {};
    for (row =0; row <5; row++)
    {  
        for (col =0; col < 5; col++)
        {
            if (row == col)
            {
                if (bingo_card[row][col] !=0)
                {
                    ans[row] = 1;
                }
                else ans[row] = 0;
            }
        }
    }
    int is_diagonal = 1;
    for (row =0; row < 5; row++)
    {
        if (ans[row] ==1)
        {
            is_diagonal =0;
        }
    } 
    return is_diagonal; 

}
//Function to check if the diagonal from top right is complete
int is_diagonal_2(int bingo_card[5][5])
{
    int row, col;
    int ans[5] = {};
    for (row =0; row <5; row++)
    { 
        for (col =0; col < 5; col++)
        {
            if (row+col==4)
            {
                if (bingo_card[row][col] !=0)
                {
                    ans[row] = 1;
                }
                else ans[row] = 0;
            }
        }
    }
    int is_diagonal = 1;
    for (row =0; row < 5; row++)
    {
        if (ans[row] ==1)
        {
            is_diagonal =0;
        }
    } 
    return is_diagonal; 
}

//Main Function
int main(void) {
    srand(time(0)); 
    int game_board[5][5] = {};
	//Populate the game board with possible random numbers
    populate_board(game_board);
	//Display the BINGO game board to the user
    print_grid(game_board);
    //Initiaize empty array to hold all the called values when player is playing the game
	int bank[75] = {};
	//Initiaize counter to count the values in bank array and insert that array
    int counter = 0;
    int won = 0;
    int num;
    char ans[3];
    while (won == 0 && counter <=75 )
    {
        //Call a function to pick a number that has not been chosen already
        num = pick_number(bank,counter);
        //Ask if the player has that number
        printf("Do you have it? (Y/N) ");
        scanf("%s",ans);
        if (ans[0] == 'Y' || ans[0] == 'y')
        {
            if (num_exist(num, game_board))
            { 
                print_grid(game_board);
                if (is_row_complete(game_board) && is_col_complete(game_board))
                {
                    won = 1;
                    printf("\nYou filled out a row and a column - BINGO!!!\n");
                }
                else if (is_diagonal_1(game_board) || is_diagonal_2(game_board))
                {
                     won = 1;
                     printf("\nYou filled out a diagonal - BINGO!!!\n");
                }
                else if (is_row_complete(game_board))
                {
                    won = 1;
                    printf("\nYou filled out a row - BINGO!!!\n");
                }
                else if (is_col_complete(game_board))
                {
                    won = 1;
                    printf("\nYou filled out a column - BINGO!!!\n");
                }
            }
            else
            {
                printf("\nThat value is not on your BINGO card - are you trying to cheat??\n");
                print_grid(game_board);
            }
        }
        else
        {
            print_grid(game_board);
            counter++;
        } 
    }
    return 0;
}