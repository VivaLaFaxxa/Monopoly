#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>

class Player;		//To avoid circular inclusion

enum class SquareType {
	START,
	EMPTY,
	ECONOMIC,
	STANDARD,
	LUXURY
};

class Square {
public:
	//constructors
	Square(SquareType type, std::string owner);

	Square(SquareType type);

	//Destructor
	virtual ~Square();

	//Getter functions
	SquareType GetType() const;

	std::string GetOwner() const;

	bool HasHouse() const;

	bool HasHotel() const;

	//Setter functions
	void SetOwner(const std::string& owner);

	void BuildHouse();

	void BuildHotel();

	//Check function
	bool IsOwned() const;

private:
	SquareType type_;
	std::string owner_;
	bool has_house_;
	bool has_hotel_;
};

#endif 
