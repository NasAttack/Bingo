/********DO NOT MODIFY THIS SECTION************
 * 
 * EECS 22 : Advanced C Programming
 * Winter 2020, Prof. Quoc-Viet Dang
 * 
 * HW1  : Bingo Simulator
 * Template file : Bingo.c
 * 
 * Created on Jan 5, 2020, 10:56 PM by Bo Tsai <bo.tsai@uci.edu>
 */
/**********************************************
 
// Enter your name, last name and UCInet ID below://
 * 
 * *****************************
 * First Name : Nasser
 * Last Name: Marcellus
 * UCInet ID: 22197730
 *
 */

#include <stdio.h>
#include <stdbool.h>

/*Declare your function definitions in the section below*/
/*You may add other functions if needed*/
/*********************************************************/


/*********************************************************/

/*Declare your global variables below (if any)*/
/**************************************************/




/**************************************************/

/*Colors (you can add or remove from this list*/


/*Colors (you can add or remove from this list*/
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"


/*Main function*/
int main(int argc, char** argv) 
{
   /*Initializing variables*/
    char name[10][64];
    int playerBoard[10][256][256][2];
    int numPlayers = 0;
    int length = 0;
    int number[65536];
    bool tracker[11];
 
    /*Inputing file */
    FILE *fp;
    fp = fopen("Input1.txt", "r");
    if (fp == NULL) { /*checks to see if it reads anything*/
    fprintf(stderr, "Can't open input file in.list!\n");
        return(1);
                    }
    /*Reads in board size and amount of players*/
    fscanf(fp, "%d %d", &numPlayers, &length);
    printf("players: %d board dimension: %d \n\n", numPlayers, length);
    printf("Start Game: \n");
 	 
    for(int i = 0; i < numPlayers; i++){
        fscanf(fp, " %[^\n]", name[i]);
        printf("Name: %s\n",name[i]); 
        for(int j = 0; j < length; j++){
            for(int k = 0; k < length; k++){
                fscanf(fp, "%d ", &playerBoard[i][j][k][0]);
                printf("%d ", playerBoard[i][j][k][0]);
            }
            printf("\n");
        }
        printf("\n");
    } 
    int i=0;
    while(!feof(fp))
    {
      fscanf(fp,"%d ",&number[i]);
      i++;   
    }
    
   int isbingo = 0; /*intializing a condition for bingo*/
 /*Conditons to get in the nested loop is not have bingo and within the amount of call number*/
 for(int y=0; y<length*length && isbingo==0; y++)
 {
   for(int i = 0; i < numPlayers; i++)
   {    
        printf("Name: %s\n",name[i]); 
        
        for(int j = 0; j < length; j++)
        { 
            for(int k = 0; k < length; k++)
            {   
           /*Check player board to see if there is a matched number and print out correct color*/                                                                
                if(number[y]==playerBoard[i][j][k][0])
                {
                   playerBoard[i][j][k][1]= 99;
                   printf(KGRN "%d " KNRM, playerBoard[i][j][k][0]);   
                 } 
                 else if (99 == playerBoard[i][j][k][1])
                 {
                    printf(KRED "%d " KNRM, playerBoard[i][j][k][0]);
                 }
                   else 
                 {
                     printf("%d ",playerBoard[i][j][k][0]);
                 }  
                    /* Checking through the board horizontally*/
                     for(int r = 0; r < length; r++) /*Hold row*/
                    {
                      for(int counter =0 ,c = 0;  c < length; c++)/*Go through column of row*/
                      {
                        if (99 == playerBoard[i][r][c][1])
                        {
                        counter++;
                          if(counter == length)
                          {
                          tracker[i]= true; 
                          isbingo = 1;
                           r = length;
                           c =length; 
                          }
                      
                        }
                      }
                    }
                     
                     /*Checking the board vertically*/
                     for(int c = 0; c < length; c++) /*Hold Column*/
                    {
                      for(int counter =0 ,r = 0;  r < length; r++)/*Go though each row*/
                      {
                        if (99 == playerBoard[i][r][c][1])
                        {
                        counter++;
                          if(counter == length)
                          {
                          tracker[i]= true; 
                          isbingo = 1;
                           r = length;
                           c =length; 
                          }
                      
                        }
                      }
                    }
                     /*Checking the board diagonally from the top left to bottom right*/
                      for(int counter =0 ,c = 0,r=0;  c < length; c++)
                      {
                        if (99 == playerBoard[i][r][c][1])
                        {
                        counter++;
                          if(counter == length)
                          {
                          tracker[i]= true; 
                          isbingo = 1;
                           r = length;
                           c =length; 
                          }
                      
                        }
                       r++; 
                      }
                      /*Checking board from bottom left to top right*/
                      for(int counter =0 ,c = 0 , r=length-1;  c < length ; r--, c++)
                      {
                        if (99 == playerBoard[i][r][c][1])
                        {
                        counter++;
                          if(counter == length)
                          {
                          tracker[i]= true; 
                          isbingo = 1;                  
                           c = length; 
                          }                    
                        } 
                      }                                        
             }
    printf("\n"); 
            }
            printf("%d \n",number[y]);
        }
   }
   /*Prints out the persons that won bingo*/
   for(int i = 0; i < numPlayers; i++)
   {
   if(tracker[i]==true)
        {
          printf("Bingo %s \n", name[i]);
           
        } 
    }
    return 0; /*EOF*/
}


