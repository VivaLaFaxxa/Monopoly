#ifndef utilities_h
#define utilities_h

#include <vector>
#include <algorithm>
#include "..//headers/player.h"


std::vector<Player*> DetermineTurnOrder(std::vector<Player*> players);

bool comparePlayers(Player* a, Player* b);





#endif