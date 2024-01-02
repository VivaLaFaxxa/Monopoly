#include "..//utilities/utilities.h"
#include <random> 
#include <iostream>
#include "..//headers/player.h"


bool comparePlayers(Player* a, Player* b) {
    return a->getRoll() > b->getRoll();
}

std::vector<Player*> DetermineTurnOrder(std::vector<Player*> players) {
    bool hasTie = true;

    while (hasTie) {
        // Roll dice for each player
        for (Player* player : players) {
            player->rollDice();
        }

        // Sort players by dice roll
        std::sort(players.begin(), players.end(), comparePlayers);

        // Check for ties
        hasTie = false;
        for (int i = 0; i < players.size() - 1; i++) {
            if (players[i]->getRoll() == players[i + 1]->getRoll()) {
                hasTie = true;
                break;
            }
        }
    }

    return players;
}

