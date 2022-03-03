/*Guessing game
* Create an interactive guessing game for a user.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>

void game();
void maximum();
int main();

//creating file
    FILE *fp;

//Global Variables
int gamesWon = 0;
int gamesLost = 0;
int counter = 0; //counts total guesses made
int maxNum; //maximum number that can be changed with maximum()

//Function: Game High or Low
void game(){
    //set original maxNum as 10
    maxNum = 10;

    //choose random for answer
    srand((unsigned) time(NULL));
    int answer = rand()%((maxNum+1)-1)+1;
    int guess;
    bool correct = false;

    while (correct != true){
            printf("Please enter a number from 1-%i or -1 to quit: ", maxNum);
            scanf("%i", &guess);
            //Checks guess relationship with answer. Also checks for invalid inputs.
            if(guess == -1){
                printf("\nGame was lost. Returning back to menu.");
                gamesLost++;
                correct = true;
            }else if(guess < 0){
                printf("\nInvalid entry. Please try again.");
            }else if(guess > maxNum){
                printf("\nInvalid entry. Please try again.");
            }else if(guess == answer){
                printf("\nYou won!");
                counter++;
                gamesWon++;
                correct = true;
            }else if ((guess < answer) && (guess > 0) && (guess < maxNum)){
                printf("\nThis guess was too low. Try again.");
                counter++;
            }else{
                printf("\nThis guess was too big. Try again.");
                counter++;
            }
            
    }
}

//Function: Changing the maximum
void maximum(){
    bool inRange = false;
    printf("\nPlease enter a new maximum that is 100 or lower.");
    while (inRange != true){
        int newMax;
        scanf("%i", &newMax);
        
        if((newMax > 0) && (newMax < 100)){
            inRange = true;
            fputs("New Maximum " + newMax, fp);
        }
        else{
            printf("\nThe number you entered is not in range (max 100), please enter another number.");
        }
    }
}

//Function: Main
int main(){
    fp = fopen("guessHistory.txt", "w+");
    fputs("This will record changes in Max Number.", fp);

    bool playing = true;
    int choice;
    while (playing != false){
        printf("\nPress 1 to play a game\nPress 2 to change the max number\nPress 3 to quit\nPlease enter a number: ");
        scanf("%i", &choice);

        //Checking user's selection. If invalid, try again.
        if(choice == 1){
            game();
        }else if(choice == 2){
            maximum();
        }else if(choice == 3){
            printf("Thank you for playing. \nYou won %d games and lost %d games. \nThe total number of guesses made was %d.", gamesWon, gamesLost, counter);
            playing = false;
        }else{
            printf("\nInvalid selection, please try again.");
        }
    }

    fclose(fp);
}
