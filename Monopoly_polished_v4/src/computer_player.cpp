#include "..//include/computer_player.h"
#include "..//include/board.h"
#include <random>

ComputerPlayer::ComputerPlayer() {}

ComputerPlayer::ComputerPlayer(Board* board, int id) : Player(board, id) {}

void ComputerPlayer::PerformAction(Square* square) {
	int random_number;

	switch (square->GetType()) {
	case SquareType::START:
		//Do nothing, handled in the MovePlayer function.
		break;
	case SquareType::EMPTY:
		//Do nothing
		break;
	case SquareType::ECONOMIC:
		//Generate a random number between 1 and 100
		random_number = rand() % 100 + 1;

		//Check if the square is owned by some other player, in that case requires a payment accordignly to specifics.
		if (square->IsOwned() && square->GetOwner() != this->name_) {
			int payment = 0;
			//Checks for hotel or house on the square.
			if (square->HasHotel()) {
				payment = 4;
				std::cout << "You have passed on a propretary square, you need to pay" << payment << std::endl;
			}
			else if (square->HasHouse()) {
				payment = 2;
				std::cout << "You have passed on a propretary square, you need to pay" << payment << std::endl;
			}
			//Makes the change on the balance, this is the only moment where the player can be eliminated.
			this->balance_ -= payment;
			if (this->balance_ <= 0) {
				board_->AddPlayerToEliminate(this);
			}
			break;
		}

		//Checks if the squre is owned from the player that landed on it, in order to request house building and hotel building.
		else if (square->IsOwned() && square->GetOwner() == this->name_) {
			//Checks if the square allready has a house and if the balance of the player allows for house building.
			if (!square->HasHouse() && this->balance_ > 3 && random_number < 25) {
					square->BuildHouse();
					this->balance_ -= 3;
			}
			//If conditions are met build a hotel.
			if (square->HasHouse() && this->balance_ > 3 && random_number < 25) {
				square->BuildHotel();
				this->balance_ -= 3;
			}
		}

		//If the conditions are met buys the proprety
		else {
			if (this->balance_ > 6 && random_number < 25) {
				square->SetOwner(this->name_);
				//Keeps track of player possession (in terms of squares)
				this->propreties_.push_back(square);
				this->balance_ -= 6;
			}
		}
	case SquareType::STANDARD:
		//Generate a random number between 1 and 100
		random_number = rand() % 100 + 1;

		//Check if the square is owned by some other player, in that case requires a payment accordignly to specifics.
		if (square->IsOwned() && square->GetOwner() != this->name_) {
			int payment = 0;
			//Checks for hotel or house on the square.
			if (square->HasHotel()) {
				payment = 8;
				std::cout << "You have passed on a propretary square, you need to pay" << payment << std::endl;
			}
			else if (square->HasHouse()) {
				payment = 4;
				std::cout << "You have passed on a propretary square, you need to pay" << payment << std::endl;
			}
			//Makes the change on the balance, this is the only moment where the player can be eliminated.
			this->balance_ -= payment;
			if (this->balance_ <= 0) {
				board_->AddPlayerToEliminate(this);
			}
			break;
		}

		//Checks if the squre is owned from the player that landed on it, in order to request house building and hotel building.
		else if (square->IsOwned() && square->GetOwner() == this->name_) {
			//Checks if the square allready has a house and if the balance of the player allows for house building.
			if (!square->HasHouse() && this->balance_ > 5 && random_number < 25) {
				square->BuildHouse();
				this->balance_ -= 5;
			}
			//If conditions are met build a hotel.
			if (square->HasHouse() && this->balance_ > 5 && random_number < 25) {
				square->BuildHotel();
				this->balance_ -= 5;
			}
		}

		//If the conditions are met buys the proprety
		else {
			if (this->balance_ > 10 && random_number < 25) {
				square->SetOwner(this->name_);
				//Keeps track of player possession (in terms of squares)
				this->propreties_.push_back(square);
				this->balance_ -= 10;
			}
		}
	case SquareType::LUXURY:
		//Generate a random number between 1 and 100
		random_number = rand() % 100 + 1;

		//Check if the square is owned by some other player, in that case requires a payment accordignly to specifics.
		if (square->IsOwned() && square->GetOwner() != this->name_) {
			int payment = 0;
			//Checks for hotel or house on the square.
			if (square->HasHotel()) {
				payment = 14;
				std::cout << "You have passed on a propretary square, you need to pay" << payment << std::endl;
			}
			else if (square->HasHouse()) {
				payment = 7;
				std::cout << "You have passed on a propretary square, you need to pay" << payment << std::endl;
			}
			//Makes the change on the balance, this is the only moment where the player can be eliminated.
			this->balance_ -= payment;
			if (this->balance_ <= 0) {
				board_->AddPlayerToEliminate(this);
			}
			break;
		}

		//Checks if the squre is owned from the player that landed on it, in order to request house building and hotel building.
		else if (square->IsOwned() && square->GetOwner() == this->name_) {
			//Checks if the square allready has a house and if the balance of the player allows for house building.
			if (!square->HasHouse() && this->balance_ > 10 && random_number < 25) {
				square->BuildHouse();
				this->balance_ -= 10;
			}
			//If conditions are met build a hotel.
			if (square->HasHouse() && this->balance_ > 10 && random_number < 25) {
				square->BuildHotel();
				this->balance_ -= 10;
			}
		}

		//If the conditions are met buys the proprety
		else {
			if (this->balance_ > 20 && random_number < 25) {
				square->SetOwner(this->name_);
				//Keeps track of player possession (in terms of squares)
				this->propreties_.push_back(square);
				this->balance_ -= 20;
			}
		}
	}
}