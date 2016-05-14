#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#define MAX_TESTS 1300

//This randomly tests gardens

int main(int argc, char *argv[]) {

	srand(time(NULL));
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
		sea_hag, tribute, smithy};

	//int i, choice1, choice2, choice3, ranseed, test;
	int i, ranseed, test;
	if(argc > 1){
		ranseed = atoi(argv[1]);
		printf("Seed Set to %d\n", ranseed);
	}
	else{
		ranseed = 42;
	}
	struct gameState g;
	struct gameState *playGame = &g;
	srand(time(NULL));
	printf("Running Random Card Test for Gardens\n");
	int players = 4;
	int creatingGame = initializeGame(players, k, ranseed, playGame);
	if(creatingGame != 0){
		printf("Failed to initialize game\n");
		exit(0);
	}


	for (i = 0; i < MAX_TESTS; i++) {
		whoseTurn(playGame);
		/*	choice1 = rand() % 100 + i;
			choice2 = rand() % 100 + i;
			choice3 = rand() % 100 + i;*/
		int handPos = rand() % 100 + i;
		int bonus = rand() % 100 + i;


		test = cardEffect(gardens, 0, 0, 0, playGame, handPos, &bonus);		//Call to gardens
		if(test != 0){
			printf("Failed to run gardens card\n");
			exit(0);
		}
		endTurn(playGame);
	}
	printf("Test Completed succesfully\n");

	return 0;

}
