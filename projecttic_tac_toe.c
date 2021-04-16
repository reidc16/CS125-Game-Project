/************************
*File: projecttic_tac_toe.c title.c tiegame.c player.c tictac.c gameover.c tictacbox.h -o board
*Author: Clayton Reid
*Purpose: CS125 Game Project
*Version: 1.0 March 9th, 2021
***********************/

#include <stdio.h>
#include <stdlib.h>
#include "tictacbox.h"
void make_board();
void title(void);
void tiegame(void);
void player(void);
void tictac(void);
void gameover(void);
int wehavewin();

char tictacbox[3][3] = { {'1', '2', '3'},{'4', '5', '6'},{'7', '8', '9'} };        /* 2D character array */


int main()
{
int player = 1, playerchoice, y;

title();                                                /* ASCII title text art */

char score;
do
  {
   make_board();                                        /* calls make_board function so if the value is -1, board disappears once it runs through the while loop */
    if (player % 2)                                     
        player = 1;
    else
        player = 2;                                     /* if the players remainder is 2, the player will be 1, anything else will be player 2 (if value is 0 it will be false) */
 
     printf("Player %d, enter a number: ", player);
      scanf("%d", &playerchoice);
 
    score = (player == 1)? 'X' : 'O';                   /* if player is equal to 1, then it will score an X, if player is equal to 2, it will score an O (basically works like an if else statement) */
 
if (playerchoice == 1 && tictacbox[0][0] == '1')
  tictacbox[0][0] = score;

else if (playerchoice == 2 && tictacbox[0][1] =='2')
  tictacbox[0][1] = score;

else if (playerchoice == 3 && tictacbox[0][2] =='3')
  tictacbox[0][2] = score;

else if (playerchoice == 4 && tictacbox[1][0] =='4')
  tictacbox[1][0] = score;

else if (playerchoice == 5 && tictacbox[1][1] =='5')
  tictacbox[1][1] = score;

else if (playerchoice == 6 && tictacbox[1][2] =='6')
  tictacbox[1][2] = score;

else if (playerchoice == 7 && tictacbox[2][0] == '7')
  tictacbox[2][0] = score;

else if (playerchoice == 8 && tictacbox[2][1] == '8')
  tictacbox[2][1] = score;

else if (playerchoice == 9 && tictacbox[2][2] == '9')
  tictacbox[2][2] = score;

else 
{
  printf("Invalid choice, Try again\n");
  
  player--;                                       /* decreases player so it gives player another chance to get correct choice before moving onto next player */
}
 
 y = wehavewin();
 player++;                                    /* increases to next player if there is no invalid choice, rather a correct choice */
  
}while(y==-1);

make_board();                                   /* call make_board function again because it runs through the while loop that will make it disappear, thus it needs to be called again if it isn't -1 */


if(y==1)                                                      /* equal to one means game has been won and returns result */
  printf("Player %d wins\n", --player);                      /* we decrease player again because we added to it in the do while loop, if we didnt decrease the player here, and say player two wins it would print "Player 3 wins" and if player one won it would print "Player 2 wins because it increased from the do while loop */
else
  tiegame();                                              /* ASCII tie game text art */
  gameover();                                            /* ASCII game over text art */
return 0;
}


void make_board(){                         /* Board creating function */
 printf("\n");
  tictac();                                  /* ASCII tic tac text art */
 printf("\n");
  player();                                  /* ASCII player text art */

printf("       |       |      \n");
printf("    %c  |    %c  |    %c \n", tictacbox[0][0], tictacbox[0][1], tictacbox[0][2]);     /* scans in characters that user enters */

printf("_______|_______|_______\n");
printf("       |       |       \n");

printf("    %c  |    %c  |    %c \n", tictacbox[1][0], tictacbox[1][1], tictacbox[1][2]);

printf("_______|_______|_______\n");
printf("       |       |       \n");

printf("    %c  |    %c  |    %c \n", tictacbox[2][0], tictacbox[2][1], tictacbox[2][2]);

printf("       |       |     \n\n");
}

int wehavewin(){                              /* Checker for winner function */

if (tictacbox[0][0] == tictacbox[0][1] && tictacbox[0][1] == tictacbox[0][2])
return 1;

else if (tictacbox[1][0] == tictacbox[1][1] && tictacbox[1][1] == tictacbox[1][2])
return 1;

else if (tictacbox[2][0] == tictacbox[2][1] && tictacbox[2][1] == tictacbox[2][2])
return 1;                                                                            /* Horizontal win checker */


else if (tictacbox[0][0] == tictacbox[1][0] && tictacbox[1][0] == tictacbox[2][0])
return 1;

else if (tictacbox[0][1] == tictacbox[1][1] && tictacbox[1][1] == tictacbox[2][1])
return 1;

else if (tictacbox[0][2] == tictacbox[1][2] && tictacbox[1][2] == tictacbox[2][2])
return 1;                                                                           /* Vertical win checker */
                               

else if (tictacbox[0][0] == tictacbox[1][1] && tictacbox[1][1] == tictacbox[2][2])
return 1;

else if (tictacbox[0][2] == tictacbox[1][1] && tictacbox[1][1] == tictacbox[2][0])
return 1;
                                                                                    /* Diagonal win checker */

else if (tictacbox[0][0] != '1' && tictacbox[0][1] != '2' && tictacbox[0][2] != '3' && tictacbox[1][0] != '4' && tictacbox[1][1] != '5' && tictacbox[1][2] != '6' && tictacbox[2][0] != '7' && tictacbox[2][1] != '8' && tictacbox[2][2] != '9')     /* Checks for non matching as well as if the positions are already filled */
return 0;

else
return -1;
}
