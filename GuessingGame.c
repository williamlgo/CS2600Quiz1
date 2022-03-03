/*Guessing game
* Create an interactive guessing game for a user.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

//Global Variables
int gamesWon = 0;
int gamesLost = 0;
int counter = 0;
int maxNum = 10;

void game(){
    srand((unsigned) time(NULL));
    int answer = rand()%((10+1)-1)+1;
    int guess;
    bool correct = false;
    while (correct != true){
            printf("Please enter a number 1-%i: ", maxNum);
            scanf("%s", &guess);

            if (guess == answer){
                printf("\n You won!");
                counter++;
                gamesWon++;
                correct = true;
            }else if (guess == "q"){
                printf("\n Game was lost. Returning back to menu.");
                gamesLost++;
                correct = true;
            }else if (guess < answer){
                printf("\n This guess was too low. Try again.");
                counter++;
            }else{
                printf("\n This guess was too big. Try again.");
                counter++;
            }

    }
}