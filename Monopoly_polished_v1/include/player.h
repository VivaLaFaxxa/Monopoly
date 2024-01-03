#ifndef PLAYER_H
#define PLAYER_H

#include "..//include/square.h"
#include <vector>

class Player {
public:
	//Constructors
	Player();

	//Destructor
	~Player();

	//Getter functions
	int GetPosition() const;

	int GetBalance() const;

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
	std::vector <Square*> propreties_;
};


#endif 