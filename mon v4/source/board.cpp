#include "../headers/board.h"
#include <random>

//Creates the whole board with static angulars and randomic lateral tiles.
//NOte is a std::vector of tile objects.
void Board::SpawnRandom() {
	Board::CreateStartTile();
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 6; j++) {
			Board::CreateRandomLateral();
		}
		Board::CreateTile(Tile::Type::EMPTY);
	}

}

//Creates the starting tile.
void Board::CreateStartTile() {
	Tile starting_tile(Tile::Type::START, "", 0, false);
	board_.push_back(&starting_tile);
}

//Creates a default tile of the requested type.
void Board::CreateTile(Tile::Type a) {
	Tile tile(a, "", 0, false);
	board_.push_back(&tile);
}

//Creates a rando lateral tile between(econmy, standard and luxury types).
void Board::CreateRandomLateral() {
	std::random_device rd;
	std::mt19937 gen(rd()); 
	//If economy flag is full, we don't need any more of those tiles, so rando generation is only possible between 2 and 3.
	if (economy_flag == 8) {
		std::uniform_int_distribution<> distr(2, 3);
		//Generating the number
		int n1 = distr(gen);

		//Updating flags accordignly.
		if (n1 == 2) {
			Board::CreateTile(Tile::Type::STANDARD);
			standard_flag++;
		}
		else {
			Board::CreateTile(Tile::Type::LUXURY);
			luxury_flag++;
		}
	}
	
	//Standard tiles spaces filled scenario.
	if (standard_flag == 10) {
		std::uniform_int_distribution<> distr(0, 1);
		int n1 = distr(gen);//Generate a random number (0 or 1)
		n1 = 2 * n1 + 1; //Convert to 1 or 3
		//Updating flags accordignly.
		if (n1 == 1) {
			Board::CreateTile(Tile::Type::ECONOMIC);
			economy_flag++;
		}
		else {
			Board::CreateTile(Tile::Type::LUXURY);
			luxury_flag++;
		}

	}

	//Luxury tiles spaces filled scenario.
	if (luxury_flag == 6) {
		std::uniform_int_distribution<> distr(1, 2);
		//Generating the number
		int n1 = distr(gen);

		//Updating flags accordignly.
		if (n1 == 1) {
			Board::CreateTile(Tile::Type::ECONOMIC);
			economy_flag++;
		}
		else {
			Board::CreateTile(Tile::Type::STANDARD);
			standard_flag++;
		}
	}
}


