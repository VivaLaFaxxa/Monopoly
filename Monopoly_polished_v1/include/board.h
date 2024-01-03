#ifndef BOARD_H
#define BOARD_H

#include "..//include/square.h"
#include "..//include/player.h"
#include "..//include/human_player.h"
#include "..//include/computer_player.h"
#include <vector>

class Board {
public:
	//Constructor
	Board();

	//Destructor
	~Board();

	//Getter function
	Square* GetSquare(int position) const;

	//Setter functions
	void MovePlayer(Player& player, int roll);

	void SetupBoard();

	//Check function
	bool IsSquareOwned(int index) const;

private:
	Square* squares_[28];
	std::vector<Player*> players_;
};


#endif 
