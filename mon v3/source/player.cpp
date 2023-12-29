#include "..//headers/player.h"
#include <random>

Player::Player(const std::string& name, Type type) :
	name_(name), type_(type), balance_(100), roll(0){}

//Getters for accessing player properties
std::string Player::getName() const { return name_; }

Player::Type Player::getType() const { return type_; }

int Player::getBalance() const { return balance_; }

std::vector<Tile*> Player::getProperties() const { return properties_; }

int Player::getRoll() const { return roll; }

//Setter for modifying player properties
void Player::setName(const std::string& new_name) { name_ = new_name; }
void Player::setType(Type newType) { type_ = newType; }
void Player::setBalance(int newBalance) { balance_ = newBalance; }
void Player::addProperty(Tile* Tile) { properties_.push_back(Tile); }

//Game functions

	int Player::rollDice() {
	//Generates two random numbers between 1 and 6.
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(1, 6);
	int n1 = distr(gen);
	int n2 = distr(gen);
	roll = n1 + n2;
	//Returns the sum of the two numbers 
	return roll;
	
}