#include "..//include/board.h"
#include <random>

//Constructor
Board::Board() {
	//Initialize the array squares at nullptr
	for (int i = 0; i < 28; i++) {
		squares_[i] = nullptr;
	}

	//Initialize the vector of players with 1 HumanPlayer and 3 ComputerPlayer
	players_.push_back(new HumanPlayer());
	for (int i = 0; i < 3; i++) {
		players_.push_back(new ComputerPlayer());
	}
}

//Destructor
Board::~Board() {
	//Delete the Square objects
	for (int i = 0; i < 28; i++) {
		delete squares_[i];
		squares_[i] = nullptr;
	}
	
	//Delete the player object
	for (Player* player : players_) {
		delete player;
	}
	players_.clear();								//Clears the vector after deleting the objects
}

Square* Board::GetSquare(int position) const{
	if (position < 0 || position >= 28) {
		//Out of range
		throw std::out_of_range("Board position is out of range");
	}
	return squares_[position];
}

//Check function
bool Board::IsSquareOwned(int index) const {
	return squares_[index]->IsOwned();
}

//Game functions
void Board::MovePlayer(Player& player, int roll) {
	//Update the player position
	int new_position = (player.GetPosition() + roll) % 28;
	player.SetPosition(new_position);

	//Get the square at the new position
	Square* square = GetSquare(new_position);

	//Depending on where you are perform action (function to be defined in each sub class of square)
}

void Board::SetupBoard()	{
	//Create the corner squares
	squares_[0] = new Square(SquareType::START);
	squares_[7] = new Square(SquareType::EMPTY);
	squares_[14] = new Square(SquareType::EMPTY);
	squares_[21] = new Square(SquareType::EMPTY);

	//Create an array of the non-corner square types
	SquareType types[] = { SquareType::ECONOMIC, SquareType::STANDARD, SquareType::LUXURY };

	//Create an array for the limits:
	int limits[] = { 8, 10, 6 };
	int counts[] = { 0,0,0 };

	//Initialize a random number generator7
	std::default_random_engine generator;

	//Create the non-corner squares
	for (int i = 1; i < 28; i++) {
		if (i % 7 != 0) {
			//Chose a random square type
			std::uniform_int_distribution<int> distribution(0, 2);
			int random_index = distribution(generator);

			//Check if the limit for this type has been reached
			if (counts[random_index] < limits[random_index]) {
				//Create the square
				squares_[i] = new Square(types[random_index]);

				//Increment the count for this type
				counts[random_index]++;
			} else {
				//Find a type that hasn't reached its limit
				for (int j = 0; j < 3; j++) {
					if (counts[j] < limits[j]) {
						//Create the square
						squares_[i] = new Square(types[j]);

						//Increment the count for this type
						counts[j]++;
						break;
					}
				}
			}
		}
	}
}


