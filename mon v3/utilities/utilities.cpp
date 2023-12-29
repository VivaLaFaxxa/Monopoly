#include "..//utilities/utilities.h"
#include <random> 
#include <iostream>
#include "..//headers/player.h"


std::vector<Player*> DetermineTurnOrder(std::vector<Player*> players) {
	//Generates a casual number for each player
	for (Player* player : players) {
		player->rollDice();
	}

	//Orders the players considering their dice results
	std::sort(players.begin(), players.end(), [](Player* a, Player* b) {
		return a->getRoll() < b->getRoll();
	});

	//In case the score is even, players with the same score have to re-throw the dice
	for (int i = 0; i < players.size() - 1; i++) {
		if (players[i]->getRoll() == players[i + 1]->getRoll()) {
			players[i]->rollDice();
			players[i + 1]->rollDice();
		}
	}
	return players;
}


