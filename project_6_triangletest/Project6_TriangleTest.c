/* 
   Project6_TriangleTest.c
   Mike Brandin
   12/01/2019
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>



int main(int argc, char *argv[]){
  int sideA;
  int sideB;
  int sideC;
  
  if (argc != 4){//if too few or too many arguemnts
    printf("Usage: a.out side_a side_b side_c\n");
  }
  else{
      
    sideA = atoi(argv[1]);//set value of first num to sideA
    sideB = atoi(argv[2]);//set value of second num to sideB
    sideC = atoi(argv[3]);//set value of third num to sideC
    
    if (isalpha(argv[1][0])){
        printf("Value of a is not in the range of permitted values.\n");//check for valid input
    }
    else if (isalpha(argv[2][0])){
        printf("Value of b is not in the range of permitted values.\n");
    }
    else if (isalpha(argv[3][0])){
        printf("Value of c is not in the range of permitted values.\n");
    }

    else if (sideA < 1 || sideA > 200 || sideA > sideB + sideC){//if a is invalid
        printf("Value of a is not in the range of permitted values.\n");
    }
    else if (sideC < 1 || sideC > 200 || sideC > sideB + sideA ){//if c is invalid
        printf("Value of c is not in the range of permitted values.\n");
    }  
    else if (sideC >= sideB + sideA || sideA >= sideB + sideC || sideA >= sideB + sideC){
    printf("Not a triangle\n");//if last 3 cases arent met

    }

    else if (sideA == sideB && sideB != sideC || sideB == sideC && sideC != sideA || sideC == sideA && sideA != sideB){//if iscosceles
        printf("Isosceles\n");
    }
    else if (sideA == sideB && sideB == sideC){//if equilateral
        printf("Equilateral\n");
    }
    else if (sideA != sideB && sideB != sideC && sideA != sideC){//if scalene
        printf("Scalene\n");
    }

    
    
  }//else arguement == valid
    
return 0;
}