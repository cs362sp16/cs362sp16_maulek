#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
//#include "cards.h"
int main(){

	srand(time(NULL));

	struct gameState game;
	int handpos = 0;
	int c1 = -1;
	int c2 = -1;
	int c3 = -1;
	int CP = 1;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	int randomNum = rand() % 100;
	printf("----------Testing Buy Card Function----------\n");

	initializeGame(3, k, randomNum, playGame);
	
	game.handcount[0] = 1;
	g.hand[0][0] = council_room;
	playCard(handpos, c1, c2, c3, playGame);
	if( g.hand[0][0] == council_room){
		printf("Successfully played CouncilRoom");
	}
	else{
		printf("Failed");
	}




	return 0;
}
