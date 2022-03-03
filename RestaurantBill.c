/*Restaurant Bill
* Calculating the tax and tip for a patron.
*/
#include <stdio.h>

//Global variables
const float salad = 9.95;
const float soup = 4.55;
const float sandwich = 13.25;
const float pizza = 22.35;
char mealChosen;
float mealPrice;
float total;
float taxRate;
float tax;
float tipRate;
float tip;

/* Calculate Tax
* Calculates the Tax given a price.
*/
float calcTax(float price, float rate){
  float result;
  float newRate = rate/100;
  result = result * newRate;
  return result;
}

/* Calculate Tip
* Calculates the Tip given a price. This should be calculated 
* after calculating tax.
*/
float calcTip(float price, float rate){
  float result;
  float newRate = rate/100;
  result = result * newRate;
  return result;
}

//Main function
int main(){
  printf("Please enter the tax rate:");
  scanf("%f", &taxRate);
  printf("Please enter the tip rate:");
  scanf("%f", &tipRate);

  //Choose random 1-4 here 
  int mealSelect;

  //Calculating tax and tip depending on the meal chosen
  if(mealSelect == 1){
    total = salad;
    mealPrice = salad;
    mealChosen = "salad";
    tax = calcTax(total, taxRate);
    tip = calcTip(total, tipRate);
  }else if(mealSelect == 2){
    total = soup;
    mealPrice = soup;
    mealChosen = "soup";
    tax = calcTax(total, taxRate);
    tip = calcTip(total, tipRate);
  }else if (mealSelect == 3){
    total = sandwich;
    mealPrice = sandwich;
    mealChosen = "sandwich";
    tax = calcTax(total, taxRate);
    tip = calcTip(total, tipRate);
  }else{
    total = pizza;
    mealPrice = pizza;
    mealChosen = "pizza";
    tax = calcTax(total, taxRate);
    tip = calcTip(total, tipRate);
  }

  //Calculating the total
  total = total + tax + tip;

  //Printing the result
  printf(mealChosen + "($" + mealPrice + "), tax: " + tax + "%, tip: " + tip + "%, total: $" + total);  
}