#ifndef BOARD_H
#define BOARD_H

#include "square.h"
#include "player.h"
#include "human_player.h"
#include "computer_player.h"
#include <vector>

class Board {
public:
	//Constructor
	Board(Player* p1,Player* p2,Player* p3,Player* p4);

	//Destructor
	~Board();

	//Getter function
	Square* GetSquare(int position) const;

	//Setter function
	void AddPlayerToEliminate(Player* player);

	//Check function
	bool IsSquareOwned(int index) const;

	//Game functions
	void MovePlayer(Player& player, int roll);

	void SetupBoard();

	void EliminatePlayer(Player* player);

	void HandlePropreties(Player* player);

	void CheckForWinner();

	//Show function
	void Show();

	void PrintSquare(int i);

	Player* GetPlayer(int i);

private:
	Square* squares_[28];
	std::vector<Player*> players_;
	std::vector<Player*> players_to_eliminate_;			//Useful in order to avoid error with iteration of players_ vector
};


#endif 
