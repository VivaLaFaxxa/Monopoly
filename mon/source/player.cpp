#include "..//headers/player.h"

Player::Player(const std::string& name, Type type) :
	name_(name), type_(type), balance_(100) {}

//Getters for accessing player properties
std::string Player::getName() const { return name_; }

Player::Type Player::getType() const { return type_; }

int Player::getBalance() const { return balance_; }

std::vector<Tile*> Player::getProperties() const { return properties_; }

//Setter for modifying player properties
void Player::setName(const std::string& new_name) { name_ = new_name; }
void Player::setType(Type newType) { type_ = newType; }
void Player::setBalance(int newBalance) { balance_ = newBalance; }
void Player::addProperty(Tile* Tile) { properties_.push_back(Tile); }

