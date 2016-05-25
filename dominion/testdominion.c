#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]){
	int i, j, money, seed;
	struct gameState g;
	struct gameState *p = &g;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
		sea_hag, tribute, smithy};
	int players = rand() % 3 + 2;
	if(argc > 1){
		seed = atoi(argv[1]);
		 initializeGame(players, k, seed, p);
	}
	else{
		srand(time(NULL));
		seed = rand() % 100;
		initializeGame(players, k, seed, p);

	}


	while(!isGameOver(p)){
		money = 0;
		printf("Player %d:\n", whoseTurn(p));
		printf("\t-----Action Phase-----\n");
		/*---------------ACTION PHASE-------------------*/
		for(i = 0; i < numHandCards(p); i++){
			if (handCard(i, p) == copper){
				money++;         
			}
			else if (handCard(i, p) == silver){
				money += 2;
			}
			else if (handCard(i, p) == gold){
				money += 3;
			}
		}

		for(i = 0; i < numHandCards(p); i++){
			for(j = 0; j < 10; j++){
				if(handCard(i, p) == k[j]){
					printf("\tPlaying action card\n");
					playCard(i, -1, -1, -1, p);
					goto buyphase;
				}					
			}
		}


buyphase:


		/*---------------BUY PHASE-------------------*/
		printf("\t-----Buy Phase-----\n");
		int choice = rand() % 9;
		int action_card = k[choice];
		printf("\tBuying Kingdom Card . . . \n");
		buyCard(action_card, p);
		if (money >= 8) {
			printf("\t1: bought province\n");
			buyCard(province, p);
		}
		else if (money >= 6){
			printf("\t1: bought gold\n");
			buyCard(gold, p);
		}
		else if (money >= 3){
			printf("\t1: bought silver\n");
			buyCard(silver, p);
		}
		printf("Player %d: endTurn\n\n\n", whoseTurn(p));

		endTurn(p);    		
	}			

	for(i = 0; i < players; i++){
		printf("-------Score For Player %d is %d\n", i, scoreFor(i, p));
	/*	if(scoreFor(i, p) >= score){
			winner = i;*/ 
		//	score = scoreFor(i, p);
		
	}


	return 0;

}
