#ifndef PLAYER_H
#define PLAYER_H

#include "..//include/square.h"
#include <vector>

//To avoid cirucal reference
class Board;

class Player {
public:
	//Constructors
	Player(Board* board, int id);

	Player();

	//Destructor
	~Player();

	//Getter functions
	int GetPosition() const;

	int GetBalance() const;

	std::string GetName() const;

	int GetId() const;

	const std::vector<Square*>& GetPropreties() const;

	//Setter functions
	void SetPosition(int position);
	
	void SetBalance(int balance);

	void AddProprety(Square* proprety);

	//Game functions
	int RollDice();

	//Virtual function
	virtual void PerformAction(Square* square) = 0; //Pure virtual function

protected:
	int position_;
	int balance_;
	std::string name_;
	std::vector <Square*> propreties_;
	Board* board_;
	int id_;
};


#endif 