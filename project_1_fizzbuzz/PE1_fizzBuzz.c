/* 
   PE1_fizzBuzz.c
   Mike Brandin
   09/29/2019
   
   CSPC 1010 - Section 200
   
   -->This program will display numbers from one to the user inputted number and replace multiples of 3 with "Fizz", multiples of 5 with "Buzz", and multiples of both 3 and 5 with "FizzBuzz"<---
   
*/

#include <stdio.h>

int main()
{
    //declare input variable
int input;


//prompt and scan for input
printf("Welcome to FizzBuzz\nEnter a number between 1 and 100: ");
scanf("%d", &input);


//if valid input
if ((input >= 1) && (input <= 100)){
    
    //repeats until incremented to input number
  for (int i=1; i<=input; i++){
      
  //prints if i is multiple of 5 and 5
    if ((i % 3==0) && (i % 5==0)){
    printf("FizzBuzz\n");
      }
      //prints if i is multiple of 5
      else if (i % 5==0){
    printf("Buzz\n");
      }
      //prints if i is multiple of 3
     else if (i % 3==0){
    printf("Fizz\n");
      }
      //prints defaultly
    else {
    printf("%d\n", i);
      }
  }
  
}
//prints if input not in range of 1 to 100
else {
    printf("Invalid input\n");
    
}

return 0;
} 
