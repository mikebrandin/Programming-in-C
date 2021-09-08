/* 
   Project3_soccer.c
   Mike Brandin
   October 21, 2019
   Version 1 
   
                *BRIEF DESCRIPTION*
                -------------------
        This program uses three parralel arrays to
    hold the value of a user inputed player's name,
    jersey number, and rating. In addition to adding
    these players to the program, the program also 
    updates the players information, can remove a 
    player, can display a single players information,
    can print the full roster, can print all players
    over a user inputed rating, and quits on command.
    
*/

#include <stdio.h>
#include <string.h>

int findPlayer(int whichPlayer, 
               const int jerseyNumbers[], 
			   int maxJersyCount);

int main(void) {
	char menuOp = 'x';
	int count = 0;
	
	int jerseyNum[10];
	char playerName[100][100];
	double playerRate[10];
	
	int tempJersey;
	char tempName[100];
	double tempRate;
	
	int playerPos;

	int starInput;

	while (menuOp != 'q') {
	    
	    int inputJersey;
	    
		// Menu
		printf("\nMENU\n");
		printf("a - Add a new player\n");
		printf("u - Update player information\n");
		printf("r - Remove a player from the roster\n");
		printf("d - Display player information\n");
		printf("p - Print the full roster\n");
		printf("s - Print \"Star\" players\n");
		printf("q - Quit\n");

		printf("\nChoose an option: ") ;
		scanf(" %c", &menuOp);

		switch (menuOp) {
		case 'a':
		//add a new player to the roster
		    if (count > 9){
		        //if the roster exceeds ten players display error
		        printf("The Roster is full.\n");
		        break;
		    }		
		    
			printf("Enter player jersey number: ");
			scanf("%d", &tempJersey);
			
		   if (findPlayer(tempJersey, jerseyNum, count) == -1){
			    
			//prompt and scan for user info
			printf("Enter player first or nick name: ");
			scanf("%s", tempName);
			printf("Enter player rating: ");
			scanf("%lf", &tempRate);
			printf("\n");
		    
		    jerseyNum[count] = tempJersey;
			strcpy(playerName[count], tempName);
			playerRate[count] = tempRate;
			
		    count++;

		    }
		    
			else{
		   //if player jersey # not found display error message    
                printf("Jersey # already in use.\n");
			 }
			 
		 
        
		break;
		
		case 'u':
		//update an already inputted player's info
			printf("Enter a jersey number: ");
			scanf("%d", &inputJersey);
			
			//use playerPos as a placeholder for function call for improved readability
			playerPos = findPlayer(inputJersey, jerseyNum, count);
			    			
			if (playerPos == -1){
		   //if player jersey # not found display error message    
			    printf("Jersey # already in use.\n");

			}
			
			else {
            //prompt and scan for new information
                printf("Enter player first or nick name: ");
			    scanf("%s", tempName);
			    printf("Enter player rating: ");
			    scanf("%lf", &tempRate);
			    
			    strcpy(playerName[playerPos], tempName);
			    
			    playerRate[playerPos] = tempRate;
			
			}
			
		break;
		
		case 'r':	
		//remove a player from the roster
			printf("Enter a jersey number: ");
			scanf("%d", &inputJersey);
			
			if (findPlayer(inputJersey, jerseyNum, count) == -1){
		   //if player jersey # not found display error message    
                printf("Jersey not in use.  No such player.\n");
                break;
			}
			
			int y = findPlayer(inputJersey, jerseyNum, count);
			//start from the removed jersey's index number and increment to the max jersey number (-1)
			while (y < count - 1){
			    //set the value of each players info to the index ahead of it
			    jerseyNum[y] = jerseyNum[y+1]; 
			    playerRate[y] = playerRate[y+1]; 
			    strcpy(playerName[y], playerName[y+1]); 
			    y++; 
		    } 
		    //decrement count to make room for new players
		    count--;
		    
		break;

		case 'd':
		    //displays player information
		    printf("Enter a jersey number: ");
		    scanf("%d", &inputJersey);
		    
		    
		    if (findPlayer(inputJersey, jerseyNum, count) == -1){
		   //if player jersey # not found display error message     
                printf("Jersey not in use.  No such player.\n");
		    }
		    else {
		    //otherwise print the players info
		        printf("Name: %s\nJersey #: %d\nRating: %lf\n", playerName[findPlayer(inputJersey, jerseyNum, count)], jerseyNum[findPlayer(inputJersey, jerseyNum, count)], playerRate[findPlayer(inputJersey, jerseyNum, count)]);
		    }
        break;

		case 'p':
		//print the full roster
		
		printf("ROSTER\n------\n");
		for (int j = 0; j < count; j++){
		    
		    printf("%s", playerName[j]);


            printf("\n%d", jerseyNum[j]);


            printf("\n%lf\n\n", playerRate[j]);
		}
        
		break;
	
	    case 's':
	    //print all players above a user inputed rating
	    printf("Enter minimum STAR rating: ");
	    scanf("%d", &starInput);
		printf("MY STARS\n--------\n");
	
		for (int m = 0; m < count; m++){
		    //check whether player rating is above input
    		if (playerRate[m] > starInput){
    		    
    		    printf("%s", playerName[m]);
    
                printf("\n%d", jerseyNum[m]);
    
                printf("\n%lf\n\n", playerRate[m]);
    		} 
		}
		break;

		case 'q':
        //quits loop
		break;
	
		default:

		break;
		}
	}
	   return 0;
}

/*
Project3_soccer.c  <findPlayer> 

        This function uses a user inputted jersey number 
    to check a whole array of 10 jersey numbers to the 
    maximum number of inputted jerseys to find the index 
    value of that jersey number.  It then returns that 
    value which I use as a common index for my 3 parralel
    arrays.
        


    - whichPlayer <PARAMETER 1> integer, holds value of the jersey number I search the larger array for
    - jerseyNumbers <PARAMETER 2> constant integer, holds value of array of 10 jerseys/players
    - maxJersyCount <PARAMETER 3> int, holds value of number of players/jerseys inputted.

    @section PSEUDO_CODE
- start from zero and loop till you reach the number of values inputted
- check if the array index equal to the loop count has a value equal to user inputted jersey number
- return the index value if they do in fact match
- if they never match return -1 (which will be used for an error code in the main)


*/

int findPlayer(int whichPlayer, 
               const int jerseyNumbers[], 
			   int maxJersyCount)
{
    
    int i = 0;

    while (i < maxJersyCount){
        if (jerseyNumbers[i] == whichPlayer){
            
            return i;
        }

        i++;
     }
    return -1;
}


