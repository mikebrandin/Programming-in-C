/*
Project4_soccer.c
Mike Brandin
11/05/2019
Version 2
                --DESCRIPTION--
    This program uses struct arrays in order to
hold the value of a user inputed player's name,
jersey number, and rating. In addition to adding
these players to the program, the program also 
updates the players information, can remove a 
player, can display a single players information,
can print the full roster, can print all players
over a user inputed rating, and quits on command.
As an update to its predecessor, I have used my 
knowledge of passing by pointer to pass referenced
struct  values to the printPlayer function.

*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//define playerData type struct
typedef struct playerData_struct {
	
	int jerseyNum;
	char playerName[100];
	double playerRate;
	
    
} playerData;

//call function prototypes

//used to search struct array for a matching jersey number
int findPlayer(int whichPlayer, const playerData jerseyNumbers[], int maxJersyCount);

//checks if jersey number is in an artificial range
bool jerseyValid(int playerJerseyNumber);

//checks if rating is in an artificial range
bool ratingValid(double playerRating);

//prints the roster of players
void printPlayer(playerData* player, int count);

int main(void) {

    int count = 0;
	//create an array of type playerData variable
	playerData player[10];
	
	int tempJersey;
	char tempName[100];
	double tempRate;
	
	int playerPos;

	int starInput;
	
	char menuOp = 'x';

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

		printf("\nChoose an option: ");
		scanf(" %c", &menuOp);

		switch (menuOp) {

		case 'a':
        //add a new player to the roster
		    if (count > 9){
		        //if the roster exceeds ten players display error
		        printf("The Roster is full.\n");
		        break;
		    }		
		    //prompt and scan for jersey number
			printf("Enter player jersey number: ");
			scanf("%d", &tempJersey);
			
		//call jerseyValid function to check if input is inbounds	
		 if (jerseyValid(tempJersey)){
		     //if player no matching player is found
		   if (findPlayer(tempJersey, player, count) == -1){
			    
			//prompt and scan for user info
			printf("Enter player first or nick name: ");
			scanf("%s", tempName);
			printf("Enter player rating: ");
			scanf("%lf", &tempRate);
			    //call ratingValid to check if input is inbounds
			    if (ratingValid(tempRate)){
			 
    		    printf("\n");
    		    //add temporary values to the local struct variable
    		    player[count].jerseyNum = tempJersey;
    			strcpy(player[count].playerName, tempName);
    			player[count].playerRate = tempRate;
    			//increment playercount
    		    count++;
    			}
			else {
            //if player rating is not within 0.0-100.0    
            printf("Bad Rating.");
			}
		    }
		    
			else{
		   //if player jersey # not found display error message    
                printf("Jersey # already in use.\n");
			}
		 }
        
        else {
        //if player jersey # is not within 1-99    
            printf("Bad Jersey Number.");
        }
		break;
		case 'u':
		//update an already inputted player's info
			printf("Enter a jersey number: ");
			scanf("%d", &inputJersey);
			
			//use playerPos as a placeholder for function call for improved readability
			playerPos = findPlayer(inputJersey, player, count);
			    			
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
			    
			    strcpy(player[playerPos].playerName, tempName);
			    
			    player[playerPos].playerRate = tempRate;
			
			}
		    break;
		case 'r':
		//remove a player from the roster
			printf("Enter a jersey number: ");
			scanf("%d", &inputJersey);
			
			if (findPlayer(inputJersey, player, count) == -1){
		   //if player jersey # not found display error message    
                printf("Jersey not in use.  No such player.\n");
                break;
			}
			
			int y = findPlayer(inputJersey, player, count);
			//start from the removed jersey's index number and increment to the max jersey number (-1)
			while (y < count - 1){
			    //set the value of each players info to the index ahead of it
			    player[y].jerseyNum = player[y+1].jerseyNum; 
			    player[y].playerRate = player[y+1].playerRate; 
			    strcpy(player[y].playerName, player[y+1].playerName); 
			    y++; 
		    } 
		    //decrement count to make room for new players
		    count--;
		    break;
		case 'd'://possiby update for function
		    //displays player information
		    printf("Enter a jersey number: ");
		    scanf("%d", &inputJersey);
		    
		    
		    if (findPlayer(inputJersey, player, count) == -1){
		   //if player jersey # not found display error message     
                printf("Jersey not in use.  No such player.\n");
		    }
		    else {
		    //otherwise print the players info
		        printf("Name: %s\nJersey #: %d\nRating: %lf\n", player[findPlayer(inputJersey, player, count)].playerName, player[findPlayer(inputJersey, player, count)].jerseyNum, player[findPlayer(inputJersey, player, count)].playerRate);
		    }            
		    break;
		case 'p':
		//calls print player function
        printPlayer(player, count);
            break;
		case 's':
	    //print all players above a user inputed rating
	    printf("Enter minimum STAR rating: ");
	    scanf("%d", &starInput);
		printf("MY STARS\n--------\n");
	
		for (int m = 0; m < count; m++){
		    //check whether player rating is above input
    		if (player[m].playerRate > starInput){
    		    
    		    printf("%s", player[m].playerName);
    
                printf("\n%d", player[m].jerseyNum);
    
                printf("\n%lf\n\n", player[m].playerRate);
    		} 
		}
		    break;
		case 'q':
        
		default:
        break;
		}
	}

	return 0;
}


/*
@findPlayer
@brief description: Search a struct array for a matching jersey number.

parameters:
@whichPlayer: The jersey number to search for.
@playerData jerseyNumbers[]: The array of structs to search through.
@maxJersyCount: Player count in roster. 


*/

int findPlayer(int whichPlayer, const playerData jerseyNumbers[], int maxJersyCount){
        
    int i = 0;

    while (i < maxJersyCount){
        if (jerseyNumbers[i].jerseyNum == whichPlayer){
            
            return i;
        }

        i++;
     }
    return -1;
    
}

/*
@jerseyValid
@brief description: Check to see if jersey number is between 1-99


parameters:
@playerJerseyNumber: User inputed jersey number to check.

*/
bool jerseyValid(int playerJerseyNumber){
    if (playerJerseyNumber < 1 || playerJerseyNumber > 99){
        return false;
    }
    else {
        return true;
    }
}

/*
@ratingValid
@brief description: Check to see if rating is between 0.0-100.0

parameters:
@playerRating: User inputed player rating to check.

*/
bool ratingValid(double playerRating){
    if (playerRating < 0.0 || playerRating > 100.0){
        return false;
    }
    else{
        return true;
    }
}

/*
@printPlayer
@brief description: Prints the roster of all the players inputed.

parameters:
@player: A passed by pointer array of playerData structs filled with the user inputed information.
@count: The player count which will be looped through to print each player's information.

*/
void printPlayer(playerData* player, int count){
    printf("ROSTER\n------\n");
		for (int j = 0; j < count; j++){
		    
		    printf("%s", player[j].playerName);


            printf("\n%d", player[j].jerseyNum);


            printf("\n%lf\n\n", player[j].playerRate);
		}
}
