#ifndef player_h
#define player_h

#include <vector>
#include "../headers/tile.h"

class Player {
public:
	//Enumerated type for representing player types
	enum Type {
		HUMAN, 
		COMPUTER
	};
	
private:
	std::string name_;
	Type type_;
	int balance_;
	std::vector<Tile*> properties_; 
	int roll = 0;

public:
	Player(const std::string& name, Type type);

	//Getters for accessing player properties
	std::string getName() const;
	Player::Type getType() const;
	int getBalance() const;
	std::vector<Tile*> getProperties() const;
	int getRoll() const;
	

	//Setter for modifying player properties
	void setName(const std::string& new_name);
	void setType(Type newType);
	void setBalance(int newBalance);
	void addProperty(Tile* Tile);

	//Game functions 
	int rollDice();
};



#endif 