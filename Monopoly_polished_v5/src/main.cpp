#include <iostream>
#include "..//include/board.h"

int main() {
	Board b;
	b.SetupBoard();
	b.Show();
	std::cout << "\nIm the main file" << std::endl;
	return 0;
}