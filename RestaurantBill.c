/*Restaurant Bill
* Calculating the tax and tip for a patron.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//Functions being used
void calcTax(float price, float rate);
void calcTip(float price, float rate);
int main();

//Global variables
const float salad = 9.95;
const float soup = 4.55;
const float sandwich = 13.25;
const float pizza = 22.35;
char mealChosen[10];
float total = 0.0;
float tax = 0.0;
float tip = 0.0;
float taxRate = 0.0;
float tipRate = 0.0;
float mealPrice = 0.0;

/* Calculate Tax
* Calculates the Tax given a price and a rate.
*/
void calcTax(float price, float rate){
  float result;
  float newRate = rate / (float)100;
  result = price * newRate;
  total = total + result;
  tax = result;
}

/* Calculate Tip
* Calculates the Tip given a price and a rate. This should be calculated 
* after calculating tax.
*/
void calcTip(float price, float rate){
  float result;
  float newRate = rate / (float)100;
  result = price * newRate;
  total = total + result;
  tip = result;
}

//Main function
int main(){
  //Choose random 1-4 here 
  int mealSelect;
  srand((unsigned) time(NULL));
  mealSelect = rand()%((4+1)-1)+1;
  printf("%d price here", mealSelect);

  //Input tax and tip rate
  printf("Please enter the tax rate:");
  scanf("%f", &taxRate);
  printf("Please enter the tip rate:");
  scanf("%f", &tipRate);

  //Calculating tax and tip depending on the meal chosen
  if(mealSelect == 1){
    total = salad;
    mealPrice = total;
    strcpy(mealChosen, "Salad");
  }else if(mealSelect == 2){
    total = soup;
    mealPrice = total;
    strcpy(mealChosen, "Soup");
  }else if (mealSelect == 3){
    total = sandwich;
    mealPrice = total;
    strcpy(mealChosen, "Sandwich");
  }else{
    total = pizza;
    mealPrice = total;
    strcpy(mealChosen, "Pizza");
  }

  calcTax(mealPrice, taxRate);
  calcTip(total, tipRate);

  //Printing the result
  printf("%s ($%.2f), tax: %.2f, tip: %.2f, total $%.2f", mealChosen, mealPrice, tax, tip, total);
  return 0;
}