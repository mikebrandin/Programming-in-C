/*
Project4_soccer.c
Mike Brandin
12/02/2019
Version 3

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>



typedef struct playerData_struct {
	int jerseyNum;
	char playerName[50];
	int maxJersyCount;
	double playerRate;
} playerData;


int findPlayer(int whichPlayer, const playerData jerseyNumbers[], int maxJersyCount);

bool jerseyValid(int playerJerseyNumber);

bool ratingValid(double playerRating);

void printPlayer(playerData* player);

int saveRoster(char filenameOutput[], playerData myRoster[], int playerCount);

playerData*  loadRoster(char filenameInput[], int* mySize);


int main(void) {
    
	int starInput;
	int count = 0;
	char fileName[50];
	int playerPos;
	int tempJersey;
	char tempName[100];
	double tempRate;
	int arraySize = 0;

	playerData* player = (playerData*)malloc( sizeof(playerData) * 1);
	//playerData* player2;
	
	char menuOp = 'x';

	while (menuOp != 'q') {
	    int inputJersey;
	    
 
		// Menu
		printf("\nMENU\n");
		printf("l - Load the player roster\n");
		printf("s - Save the player roster\n");
		printf("e - create an empty player roster\n");
		printf("a - Add a new player\n");
		printf("u - Update player information\n");
		printf("r - Remove a player from the roster\n");
		printf("d - Display player information\n");
		printf("p - Print the full roster\n");
		printf("* - Print \"Star\" players\n");
		printf("q - Quit\n");

		printf("\nChoose an option: ");
		scanf(" %c", &menuOp);

		switch (menuOp) {

		case 'a':
        //add a new player to the roster
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
			 player = realloc(player, (count+1) * sizeof(playerData));
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

		case 'd':
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
		player[0].maxJersyCount = count;
        printPlayer(player);
            break;
            
		case '*':
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
		    
		case 'l':
        printf("Enter file name: ");
        scanf("%s", fileName);
        player = loadRoster(fileName, &arraySize);
        count = arraySize;
        
        break;
        
        case 's':
        printf("Enter file name: ");
        scanf("%s", fileName);
        saveRoster(fileName, player, count);
        break;
        
        case 'e':
        for (int m=0; m<count; m++){
            player[m].jerseyNum = 0;
        }
        count = 0;
        printf("Roster Emptied.\n");
        break;
        
		case 'q':
        break;
		default:
        break;

		}
	}
    free(player);
	return 0;
}

/*
	YOUR FUNCTION DEFINITIONS GO HERE!
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

bool jerseyValid(int playerJerseyNumber){
    if (playerJerseyNumber < 1 || playerJerseyNumber > 99){
        return false;
    }
    else {
        return true;
    }
}

bool ratingValid(double playerRating){
    if (playerRating < 0.0 || playerRating > 100.0){
        return false;
    }
    else{
        return true;
    }
}

void printPlayer(playerData* player){
    printf("ROSTER\n------\n");
		for (int j = 0; j < player[0].maxJersyCount; j++){
		    
		    printf("%s", player[j].playerName);


            printf("\n%d", player[j].jerseyNum);


            printf("\n%lf\n\n", player[j].playerRate);
		}
}
//save local roster contents to a file
int saveRoster(char filenameOutput[], playerData myRoster[], int playerCount){
    FILE* inFile;
    inFile = fopen(filenameOutput, "w");
    
    if (inFile == NULL){
        printf("Error saving roster: \"~/NoSuchDirectory/NoSuchFile\".\n");
        return -1;
    }
    
    fprintf(inFile, "%d\n", playerCount);
    
    for (int i=0; i<playerCount; i++){
        fprintf(inFile, "%s\t%d\t%lf\n", myRoster[i].playerName, myRoster[i].jerseyNum, myRoster[i].playerRate);
    }
    fclose(inFile);
    return 0;
}
//load roster from a file
playerData*  loadRoster(char filenameInput[], int* mySize){
    FILE* outFile;
    outFile = fopen(filenameInput, "r");
    
    if (outFile==NULL){
        printf("Error loading roster: \"NoSuchFile\".\n");
        return NULL;
    }
    fscanf(outFile, "%d", mySize);
    playerData* playerList = (playerData*)malloc(sizeof(playerData) * *mySize);
    
    for (int i=0; i<*mySize; i++){
        fscanf(outFile, "%s\t%d\t%lf\n", playerList[i].playerName, &playerList[i].jerseyNum, &playerList[i].playerRate);
    }
    fclose(outFile);
    printf("Roster Loaded.\n");

    return playerList;
}

