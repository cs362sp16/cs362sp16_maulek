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

	printf("----------Testing Is Game Over Function----------\n");

	game.supplyCount[province] = 0;
	int check = isGameOver(&game);

	if(check != 1){
		printf("Failed Is Game Over check on Province card pile\n");
		return -1;
	}


	printf("Successfully Tested Is Game Over  Function\n");



	return 0;
}
