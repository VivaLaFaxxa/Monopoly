#include "..//include/board.h"
#include <random>
#include <chrono>
#include <string>

//Constructor
Board::Board() {
	//Initialize the array squares at nullptr
	for (int i = 0; i < 28; i++) {
		squares_[i] = nullptr;
	}

	//Initialize the vector of players with 1 HumanPlayer and 3 ComputerPlayer
	players_.push_back(new HumanPlayer(this, 1));
	for (int i = 0; i < 3; i++) {
		players_.push_back(new ComputerPlayer(this, i + 2));
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

//Setter functions
void Board::AddPlayerToEliminate(Player* player) {
	players_to_eliminate_.push_back(player);
}

//Check function
bool Board::IsSquareOwned(int index) const {
	return squares_[index]->IsOwned();
}

//Game functions
void Board::MovePlayer(Player& player, int roll) {
	//Save the old position
	int old_position = player.GetPosition();

	//Update the player position
	int new_position = (player.GetPosition() + roll) % 28;
	player.SetPosition(new_position);

	//Check if the player has passed the start square
	if (old_position < 0 && new_position >= 0) {
		player.SetBalance(player.GetBalance() + 20);
		std::cout << "You passed the start square, you got 20 fiorini! \n";
	}

	//Get the square at the new position
	Square* square = GetSquare(new_position);

	//Depending on where you are perform action.
	player.PerformAction(square);
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

	//Initialize a random number generator, the static cast avoid the warking loss of precision
	//The generator doesn't need a very large seed so it will not present any problem.
	std::default_random_engine 
	generator(static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count()));

	//Create a distribution
	std::uniform_int_distribution<int> distribution(0, 2);

	//Create the non-corner squares
	for (int i = 1; i < 28; i++) {
		if (i % 7 != 0) {
			//Chose a random square type
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

void Board::EliminatePlayer(Player* player) {
	players_.erase(std::remove(players_.begin(), players_.end(), player), players_.end());
}

void Board::HandlePropreties(Player* player) {
	//Obtain the propreties vector
	std::vector <Square*> propreties = player->GetPropreties();
	for (Square* square : propreties) {
		//Resets the owner to ""
		square->SetOwner("");
		//Resets the owner the houses and hotels if they exist
		if (square->HasHouse()) {
			square->RemoveHouse();
		}
		if (square->HasHotel()) {
			square->RemoveHotel();
		}
	}
}

void Board::CheckForWinner() {
	if (players_.size() == 1) {
		std::cout << "The winner is " << players_[0]->GetName() << "!" << std::endl;
	}
}

void Board::Show() {
	int side_length = 7; //The length of the side of the board

	//Print the top row
	for (int i = 0; i < side_length; i++) {
		PrintSquare(i);
	}
	std::cout << std::endl;

	//Print the middle rows
	for (int i = 1; i < side_length - 1; i++) {
		PrintSquare(side_length * 4 - i); //Print the square on the left side
		for (int j = 0; j < side_length - 2; j++) {
			std::cout << "                "; //Print spaces in the middle of the board
		}
		PrintSquare(side_length + i); //Print the square on the right side
		std::cout << std::endl;
	}

	//Print the bottom row
	for (int i = side_length * 3 - 1; i >= side_length * 2; i--) {
		PrintSquare(i);
	}
	std::cout << std::endl;
}

	void Board::PrintSquare(int i) {
		char square_char;
		std::string suffix = "";

		switch (squares_[i]->GetType()) {
		case SquareType::START:
			square_char = 'P';
			break;
		case SquareType::EMPTY:
			square_char = 'E';
			break;
		case SquareType::ECONOMIC:
			square_char = 'S';
			break;
		case SquareType::LUXURY:
			square_char = 'L';
			break;
		}

		if (squares_[i]->HasHouse()) {
			suffix += "*";
		}

		if (squares_[i]->HasHotel()) {
			suffix += "^";
		}

		//Add player position information
		for (Player* player : players_) {
			if (player->GetPosition() == i) {
				suffix += std::to_string(player->GetId());
			}
		}

		std::cout << square_char << suffix << " ";
	}

//squares_ e' un array di square objects, squares_->GetType() 
//Ho tolto static, creiamo un oggetto board.show() ecc.... 
//Facendo abbiamo il meglio di entrambi i mondi, possiamo accedere direttamente alla variabile esmplare
	//Funzione di fax, magari se non funge l'altra la re-implementiamo
/*void Board::Show() {
	for (int i = 0; i < 8; i++) {
		switch (squares_[i]->GetType()) {
		case SquareType::START:
			std::cout << "|P|   ";
			break;
		case SquareType::EMPTY:
			std::cout << "| |   ";
			break;
		case SquareType::ECONOMIC:
			std::cout << "|E|   ";
			break;
		case SquareType::STANDARD:
			std::cout << "|S|   ";
			break;
		case SquareType::LUXURY:
			std::cout << "|L|   ";
			break;
		}
	}
	for (int i = 8; i < 14; i++) {
		switch (squares_[i]->GetType()) {
		case SquareType::START:
			std::cout << "										  |P|\n";
			break;
		case SquareType::EMPTY:
			std::cout << "										  | |\n";
			break;
		case SquareType::ECONOMIC:
			std::cout << "										  |E|\n";
			break;
		case SquareType::STANDARD:
			std::cout << "										  |S|\n";
			break;
		case SquareType::LUXURY:
			std::cout << "										  |L|\n";
			break;
		}
	}
	for (int i = 21; i > 13; i--) {
		switch (squares_[i]->GetType()) {
		case SquareType::START:
			std::cout << "|P|   ";
			break;
		case SquareType::EMPTY:
			std::cout << "| |   ";
			break;
		case SquareType::ECONOMIC:
			std::cout << "|E|   ";
			break;
		case SquareType::STANDARD:
			std::cout << "|S|   ";
			break;
		case SquareType::LUXURY:
			std::cout << "|L|   ";
			break;
		}
	}
	for (int i = 27; i > 21; i--) {
		switch (squares_[i]->GetType()) {
		case SquareType::START:
			std::cout << "|P|\n";
			break;
		case SquareType::EMPTY:
			std::cout << "| |\n";
			break;
		case SquareType::ECONOMIC:
			std::cout << "|E|\n";
			break;
		case SquareType::STANDARD:
			std::cout << "|S|\n";
			break;
		case SquareType::LUXURY:
			std::cout << "|L|\n";
			break;
		}
	}
}
*/