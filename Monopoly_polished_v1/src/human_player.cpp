#include "..//include/human_player.h"

void HumanPlayer::PerformAction(Square* square) {
	switch (square->GetType()) {
	case SquareType::START:
		std::cout << "You went through the start, you got 20 fiorini! \n";
		this->balance_ += 20;
		break;
	case SquareType::EMPTY:
		//Do nothing
		break;
	case SquareType::ECONOMIC:
		if (square->IsOwned()) {

			//To be completed...
			int amount = 0;
			std::cout << "You are passed on a propretary square, you need to pay";
				break;
		}
	}
}