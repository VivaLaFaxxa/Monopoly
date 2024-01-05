#include "..//include/player.h"
#include <cstdlib>		//for std::rand and std::srand
#include <ctime>			//for std::time

class Square;
class Board;

//Constructor, sets position to 0 (start of the board) and balance to 100
Player::Player(Board* board, int id) : position_(0), balance_(100), board_(board), id_(id) {}

Player::Player() : position_(0), balance_(100), board_(nullptr), id_(0){}

//Destructor
Player::~Player() {
	propreties_.clear();			//Clears the vector without deleting the square objects.
}

//Getter functions
int Player::GetPosition() const { return position_; }

int Player::GetBalance() const { return balance_; }

std::string Player::GetName() const { return name_; }

int Player::GetId() const { return id_; }

const std::vector<Square*>& Player::GetPropreties() const { return propreties_; }

//Setter functions
void Player::SetPosition(int position) { position_ = position; }

void Player::SetBalance(int balance) { balance_ = balance; }

void Player::AddProprety(Square* proprety) { propreties_.push_back(proprety); }

//Game functions
int Player::RollDice() {
	//initialize random seed
	std::srand(static_cast<unsigned int>(std::time(0)));
	
	//Generate random numbers between 1 and 6
	int die1 = std::rand() % 6 + 1;
	int die2 = std::rand() % 6 + 1;

	return die1 + die2;
}