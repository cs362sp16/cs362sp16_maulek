#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>

int main(){

	//Testing disCard card function.
	srand(time(NULL));
	struct gameState game;
	int randomNum = rand() % 100;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	initializeGame(5, k, randomNum, &game);
	int turn;	
	int i;

	printf("----------Testing Whose Turn Function----------\n");

	for(i = 0; i < 5; i++){
		game.whoseTurn = i;
		turn = whoseTurn(&game);	
		if(turn != i){
			printf("Testing Whose Turn failed\n");
		}
	}

	printf("Successfully tested Whose Turn Function\n");



	return 0;
}
