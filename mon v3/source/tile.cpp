#include "../headers/tile.h"

//Constructor to initialize a Tile object
Tile::Tile(Type type = EMPTY, std::string owner = "", int houses = 0, bool hotel = false) :
	type_(type), owner_(owner), houses_(houses), hotel_(hotel) {}

//Getter for accessing tile propreties
Tile::Type Tile::getType() const { return type_; }

std::string Tile::getOwner() const { return owner_; }

int Tile::getHouses() const { return houses_; }

bool Tile::hasHotel() const { return hotel_; }

//Setters for modifying tile propreties
void Tile::setOwner(const std::string& newOwner) { owner_ = newOwner; }

void Tile::addHouse() { houses_++; }

void Tile::buildHotel() { hotel_ = true; }