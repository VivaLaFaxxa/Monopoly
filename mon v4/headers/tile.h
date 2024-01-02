#ifndef tile_h
#define tile_h

#include <iostream>

class Tile {
public:
	//Enumerated type for pepresenting tile types
	enum Type {
		START,
		EMPTY,
		ECONOMIC,
		STANDARD,
		LUXURY
	};

private:
	Type type_;
	std::string owner_;
	int houses_;
	bool hotel_;

public:
	//Constructor to initialize a Tile object
	Tile(Type type, std::string owner, int houses, bool hotel);
		

	//Getter for accessing tile propreties
	Type getType() const;
	std::string getOwner() const;
	int getHouses() const;
	bool hasHotel() const;

	//Setters for modifying tile propreties
	void setOwner(const std::string& newOwner);
	void addHouse();
	void buildHotel();
};

#endif