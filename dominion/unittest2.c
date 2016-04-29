#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

int main(){

	//Testing disCard card function.
	srand(time(NULL));
	struct gameState game;
	struct gameState *playGame = &game;
	int randomNum = rand() % 100;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	printf("----------Testing Initialize Game Function----------\n");
	int createGame = initializeGame(3, k, randomNum, playGame);


	if(createGame == 0){
		printf("Successfully created game\n");
	}
	else{
		printf("Failed to create game\n");
		return -1;
	}




	return 0;
}
