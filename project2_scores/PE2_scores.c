
/* 
   PE2_scores.c
   Mike Brandin
   October 7th, 2019
   
   Section 200 - CPSC 1010
*/

#include <stdio.h>

int main(){
    
    //declare variables
    int i;
    double input[5];
    double temp = 0;

    double totalScore = 0;
    double avgScore = 0;
    double minScore = 100;
    double maxScore = 0;
    
    for (i=1; i<6; i++){
    printf("Enter Score %d:", i);
    scanf("%lf", &temp);


    while (temp > 100.0 || temp < 0.0){
        printf("Invalid Input\n");
        printf("Enter Score %d:", i);
        scanf("%lf", &temp);
    }
        //set array value to temp value
        if(minScore > temp)
        minScore = temp;
        if(maxScore < temp)
        maxScore = temp; 
    input[i-1] = temp;
    totalScore += input [i-1];
    }
  
/*
    
    printf("Enter Score 1:");
    scanf("%lf", &temp);

    //check if valid input

    while (temp > 100.0 || temp < 0.0){
        printf("Invalid Input\n");
        printf("Enter Score 1:");
        scanf("%lf", &temp);
    }
        //set array value to temp value

    input[0] = temp;

    
    printf("Enter Score 2:");
    scanf("%lf", &temp);

    //check if valid input

    while (temp > 100.0 || temp < 0.0){
        printf("Invalid Input\n");
        printf("Enter Score 2:");
        scanf("%lf", &temp);
    }
    //set array value to temp value
    input[1] = temp;

    printf("Enter Score 3:");
    scanf("%lf", &temp);
    //check if valid input
    while (temp > 100.0 || temp < 0.0){
        printf("Invalid Input\n");
        printf("Enter Score 3:");
        scanf("%lf", &temp);
    }
    //set array value to temp value

    input[2] = temp;

    
    printf("Enter Score 4:");
    scanf("%lf", &temp);
    //check if valid input
    while (temp > 100.0 || temp < 0.0){
        printf("Invalid Input\n");
        printf("Enter Score 4:");
        scanf("%lf", &temp);
    }
    //set array value to temp value

        input[3] = temp;

    
    printf("Enter Score 5:");
    scanf("%lf", &temp);
    //check if valid input
    while (temp > 100.0 || temp < 0.0){
        printf("Invalid Input\n");
        printf("Enter Score 5:");
        scanf("%lf", &temp);
    }
    //set array value to temp value
    

        input[4] = temp;
        
        */

    printf("\n");
    
     printf("You entered: ");
    for (i=0; i<5; i++){
        if (i<4){
        printf("%lf, ", input[i]);
        }
        if (i==4){
        printf("%lf", input[i]);

        }
    }
    

    printf("\n\n");
   // printf("You entered: %lf, %lf, %lf, %lf, %lf\n\n", input[0], input[1], input[2], input[3], input[4]); //print all valid user inputs
   
    //totalScore = input[0] + input[1] + input[2] + input[3]  + input[4];//calculate total score
    
    printf("Total Score: %lf\n", totalScore);
    avgScore = totalScore / 5.0; //calculate average score
    
    printf("Average Score: %lf\n", avgScore);
    //find min and max score
  /*
    for (i=1; i<5; i++){
        if (input[i] > input [i-1]){
            maxScore=input[i];
        }
        else if (input [i-1] > input[i]){
            maxScore = input[0];
        }
        
        if (input[i] < input [i-1]){
            minScore=input[i];
        }
        else{
            minScore = input[0];
  
        }
  
    }
*/    
//print min and max scores
    printf("Max Score: %lf\n", maxScore);

    printf("Min Score: %lf\n", minScore);


    

}