#include "human_player.h"
#include "board.h"
//Constructor
HumanPlayer::HumanPlayer(Board* board) {}

HumanPlayer::HumanPlayer(Board* board, int id) : Player(board, id) {}

HumanPlayer::HumanPlayer() {}

void HumanPlayer::PerformAction(Square* square) {
	switch (square->GetType()) {
	case SquareType::START:
		//Do nothing, handled in the MovePlayer function.
		break;
	case SquareType::EMPTY:
		//Do nothing
		break;
	case SquareType::ECONOMIC:
		//Check if the square is owned by some other player, in that case requires a payment accordignly to specifics.
		if (square->IsOwned() && square->GetOwner() != this->name_) {
			int payment = 0;
			//Checks for hotel or house on the square.
			if (square->HasHotel()) {
				payment = 4;
				std::cout << "Sei passato su una casella con Hotel, devi pagare " << payment << std::endl;
				fout << "Sei passato su una casella con Hotel, devi pagare " << payment << std::endl;
			}
			else if (square->HasHouse()) {
				payment = 2;
				std::cout << "Sei passato su una casella con casa, devi pagare " << payment << std::endl;
				fout << "Sei passato su una casella con casa, devi pagare " << payment << std::endl;
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
			if (!square->HasHouse() && this->balance_ > 3) {
				char key = 0;
				do {
					std::cout << "Questa proprietà è tua, vuoi costruire una casa? [y/n]\n";
					std::cin >> key;
					//Deals with the input of the user, and checks for invalid input.
					switch (key) {
					case 'y':
						square->BuildHouse();
						std::cout << "Hai costruito una casa!\n";
						this->balance_ -= 3;
						break;
					case 'n':
						//Do nothing
						break;
					default:
						std::cout << "Invalid input. Please enter 'y' for yes or 'n' for no. \n";
					}
				} while (key != 'y' && key != 'n');
			}
			else if (square->HasHouse() && this->balance_ > 3) {
				char key = 0;
				do {
					std::cout << "Hai già una casa sulla proprietà, vuoi costruire un Hotel? [y/n]\n";
					std::cin >> key;
					//Deals with the input of the user, and checks for invalid input.
					switch (key) {
					case 'y':
						square->BuildHotel();
						std::cout << "Hai costruito un Hotel!\n";
						this->balance_ -= 3;
						break;
					case 'n':
						//Do nothing
						break;
					default:
						std::cout << "Invalid input. Please enter 'y' for yes or 'n' for no. \n";
					}
				} while (key != 'y' && key != 'n');
			}
			} else {
			char key = 0;
			do {
				std::cout << "Vuoi comprare questa proprietà? [y/n]\n";
				std::cin >> key;
				if (key == 'y') {
					if (balance_ > 6) {
						balance_ -= 6;
						square->SetOwner(this->name_);
						//Keep track of all possesions of the player (in terms of squares)
						this->propreties_.push_back(square);			
						std::cout << "Congratulazioni, hai comprato la proprietà!\n";
					}
					else {
						std::cout << "Mi dispiace non hai abbastanza denaro.\n";
					}
				}
				else if (key == 'n') {
					//Do nothing
				}
				else {
					std::cout << "Invalid input. Please enter 'y' for yes or 'n' for no. \n";
				}
			} while (key != 'y' && key != 'n');
			break;
		}
	case SquareType::STANDARD:
		//Check if the square is owned by some other player, in that case requires a payment accordignly to specifics.
		if (square->IsOwned() && square->GetOwner() != this->name_) {
			int payment = 0;
			//Checks for hotel or house on the square.
			if (square->HasHotel()) {
				payment = 8;
				std::cout << "Sei passato su una casella con Hotel, devi pagare " << payment << std::endl;
				fout << "Sei passato su una casella con Hotel, devi pagare " << payment;
			}
			else if (square->HasHouse()) {
				payment = 4;
				std::cout << "Sei passato su una casella con casa, devi pagare " << payment << std::endl;
				fout << "Sei passato su una casella con casa, devi pagare " << payment;
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
			if (!square->HasHouse() && this->balance_ > 5) {
				char key = 0;
				do {
					std::cout << "Questa proprietà è tua vuoi costruire una casa? [y/n]\n";
					std::cin >> key;
					//Deals with the input of the user, and checks for invalid input.
					switch (key) {
					case 'y':
						square->BuildHouse();
						std::cout << "Hai costruito una casa!\n";
						this->balance_ -= 5;
						break;
					case 'n':
						//Do nothing
					default:
						std::cout << "Invalid input. Please enter 'y' for yes or 'n' for no. \n";
					}
				} while (key != 'y' && key != 'n');
			}
			else if (square->HasHouse() && this->balance_ > 5) {
				char key = 0;
				do {
					std::cout << "You allready have a house on this square, do you want to upgrade to an hotel? [y/n]";
					std::cin >> key;
					//Deals with the input of the user, and checks for invalid input.
					switch (key) {
					case 'y':
						square->BuildHotel();
						std::cout << "You have improved to an hotel!";
						this->balance_ -= 5;
						break;
					case 'n':
						//Do nothing
					default:
						std::cout << "Invalid input. Please enter 'y' for yes or 'n' for no. \n";
					}
				} while (key != 'y' && key != 'n');
			}
		}
		else {
			char key = 0;
			do {
				std::cout << "Vuoi comprare questa proprietà ? [y/n]\n";
				std::cin >> key;
				if (key == 'y') {
					if (balance_ > 10) {
						balance_ -= 10;
						square->SetOwner(this->name_);
						//Keep track of all possesions of the player (in terms of squares)
						this->propreties_.push_back(square);
						std::cout << "Congratulazioni hai comprato la proprietà!\n";
					}
					else {
						std::cout << "Mi dispiace non hai abbastanza denaro.\n";
					}
				}
				else if (key == 'n') {
					//Do nothing
					break;
				}
				else {
					std::cout << "Input non valido. Inserisci 'y' per si o 'n' per no. \n";
				}
			} while (key != 'y' && key != 'n');
			break;
		}
	case SquareType::LUXURY:
		//Check if the square is owned by some other player, in that case requires a payment accordignly to specifics.
		if (square->IsOwned() && square->GetOwner() != this->name_) {
			int payment = 0;
			//Checks for hotel or house on the square.
			if (square->HasHotel()) {
				payment = 14;
				std::cout << "Sei passato su una casella con Hotel, devi pagare " << payment << std::endl;
				fout << "Sei passato su una casella con Hotel, devi pagare " << payment;
			}
			else if (square->HasHouse()) {
				payment = 7;
				std::cout << "Sei passato su una casella con casa, devi pagare " << payment << std::endl;
				fout << "Sei passato su una casella con casa, devi pagare " << payment;
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
			if (!square->HasHouse() && this->balance_ > 10) {
				char key = 0;
				do {
					std::cout << "This square is yours, do you want to build a house? [y/n]";
					std::cin >> key;
					//Deals with the input of the user, and checks for invalid input.
					switch (key) {
					case 'y':
						square->BuildHouse();
						std::cout << "Hai costruito una casa";
						this->balance_ -= 10;
						break;
					case 'n':
						//Do nothing
					default:
						std::cout << "Invalid input. Please enter 'y' for yes or 'n' for no. \n";
					}
				} while (key != 'y' && key != 'n');
			}
			else if (square->HasHouse() && this->balance_ > 10) {
				char key = 0;
				do {
					std::cout << "You allready have a house on this square, do you want to upgrade to an hotel? [y/n]";
					std::cin >> key;
					//Deals with the input of the user, and checks for invalid input.
					switch (key) {
					case 'y':
						square->BuildHotel();
						std::cout << "You have improved to an hotel!";
						this->balance_ -= 10;
						break;
					case 'n':
						//Do nothing
					default:
						std::cout << "Invalid input. Please enter 'y' for yes or 'n' for no. \n";
					}
				} while (key != 'y' && key != 'n');
			}
		}
		else {
			char key = 0;
			do {
				std::cout << "Do you want to buy this square ? [y/n]\n";
				std::cin >> key;
				if (key == 'y') {
					if (balance_ > 20) {
						balance_ -= 20;
						square->SetOwner(this->name_);
						//Keep track of all possesions of the player (in terms of squares)
						this->propreties_.push_back(square);
						std::cout << "You succesfully bought this square, congratulations!";
					}
					else {
						std::cout << "Sorry, you don't have enough balance to buy this square.";
					}
				}
				else if (key == 'n') {
					//Do nothing
				}
				else {
					std::cout << "Invalid input. Please enter 'y' for yes or 'n' for no. \n";
				}
			} while (key != 'y' && key != 'n');
			break;
		}
	}
}

