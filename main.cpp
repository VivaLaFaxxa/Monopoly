#include <iostream>
#include <fstream>
#include "board.h"


int main(int argc, char *argv[]) {

	//controlliamo la condizione per cui vengano passati argomenti in riga di comando
	if (argc != 2){
		if ((!(strcmp(argv[1], "computer") == 0)) || (!(strcmp(argv[1], "human") == 0))){
			std::cout << "Errore inserimento" << std::endl;
			return(0);
		}
	}

	//apertura file scrittura
	std::ofstream fout_c("computer_game.txt");
	std::ofstream fout_p("player_game.txt");
	
	//computer game
	if (strcmp(argv[1], "computer") == 0){	

		//qui non funziona 
		Board b;
		b.Show();
		
		fout_c <<"Entrato nel file computer_game.txt" << std::endl;
		
	}
		
		
	//player game
	else if (strcmp(argv[1], "human") == 0){
		std::cout << "in human if" <<std::endl;
	}

	else 
		std::cout << "Input data error" << std::endl;

	

	




	
	
	
	
	
	//closing log file
	fout_c.close();
	fout_p.close();
	return 0;
}
