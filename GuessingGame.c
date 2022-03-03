/*Guessing game
* Create an interactive guessing game for a user.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void game();
void maximum();
int main();

//Global Variables
int gamesWon = 0;
int gamesLost = 0;
int counter = 0; //counts total guesses made
int maxNum = 10; //maximum number that can be changed with maximum()

//Function: Game High or Low
void game(){
    srand((unsigned) time(NULL));
    int answer = rand()%((10+1)-1)+1;
    int guess;
    bool correct = false;
    while (correct != true){
            printf("Please enter a number 1-%i: ", maxNum);
            scanf("%s", &guess);

            //Checks guess relationship with answer.
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

//Function: Changing the maximum
void maximum(){
    bool inRange = false;
    printf("\n Please enter a new maximum that is 100 or lower.");
    while (inRange != true){
        int newMax;
        scanf("%d", &newMax);
        
        if((newMax <= 100) && (newMax > 0)){
            inRange = true;
        }
        else{
            printf("\n The number you entered is not in range (max 100), please enter another number.");
        }
    }
}

//Function: Main
int main(){
    //creating file
    FILE *fp;
    fp = fopen("guessHistory.txt", "w+");
    fputs("This will record changes in Max Number.", fp);

    bool playing = true;
    int choice;
    while (playing != false){
        printf("Press 1 to play a game\nPress 2 to change the max number\nPress 3 to quit");
        scanf("%d", &choice);

        //Checking user's selection. If invalid, try again.
        if(choice == 1){
            game();
        }else if(choice == 2){
            maximum();
        }else if(choice ==3){
            printf("Thank you for playing. \nYou won %d games and lost %d games. \nThe total number of guesses made was %d.", gamesWon, gamesLost, counter);
            playing = false;
        }else{
            printf("\nInvalid selection, please try again.");
        }
    }

    fclose(fp);
}
