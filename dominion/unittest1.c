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
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	char *kingdom[10] = {"adventurer", "gardens", "embargo", "village", "minion", "mine", "cutpurse", "sea_hag", "tribute", "smithy"};
	int randomNum = rand() % 100;
	printf("----------Testing Buy Card Function----------\n");

	initializeGame(3, k, randomNum, playGame);
	int chooseKingdom = rand() % 10;

	int boughtCard = buyCard(k[chooseKingdom], playGame);
	char *kingDom = kingdom[chooseKingdom];	

	if(boughtCard == 0){
		printf("Successfully bought %s\n" , kingDom);
	}
	else{
		printf("Failed to buy %s\n", kingDom);
		return -1;
	}




	return 0;
}
