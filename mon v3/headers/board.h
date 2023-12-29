#ifndef board_h
#define board_h
#include "tile.h"
#include <vector>

class Board {
public:
	void SpawnRandom();

	void CreateStartTile();

	void CreateTile(Tile::Type a);

	void CreateRandomLateral();



private:
	int economy_flag = 0;
	int standard_flag = 0;
	int luxury_flag = 0;
	std::vector <Tile*> board_;
};



#endif 
