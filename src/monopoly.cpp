#include <iostream>
#include <string.h>
#include <typeinfo>
#include "board.h"


int main(int argc, char *argv[]) {


	//controlliamo argomenti in riga di comando
    std::string input_type;
	if (argc <= 2){
        input_type = argv[1];
		if (input_type != "computer" && input_type != "human"){
			std::cout << "Errore input in riga di comando" << std::endl;
            std::cout << "Per giocare a monopoli inserire da tastiera ('computer' o 'human'): " << std::endl;
            std::cin >> input_type;
            std::cin.ignore(1, '\n'); 
            if (input_type != "computer" && input_type != "human"){
                std::cout << "Errore inserimento dati, riprovare da riga di comando!" << std::endl;
                exit(0);
            }	    
		}
	}
    else {
        std::cout<< "Errore input! Troppi argomenti in riga di comando!" << std::endl;
        std::cout<< "Riprovare con un solo argomento ('computer' o 'human')!" << std::endl;
        exit(0);
    }

    Player * p1;

/*
	std::ofstream foutc("computer_game.txt");
*/	

	if (input_type == "computer"){      //computer game
        p1 = new ComputerPlayer();
        std::cout << "Computer monopoli Game!" << std::endl;
    }
    else if (input_type == "human"){    //player game
        p1 = new HumanPlayer();
        std::cout << "Human monopoli Game!" << std::endl;
    }

    ComputerPlayer* p2;
    ComputerPlayer* p3;
    ComputerPlayer* p4;

    Board b(p1,p2,p3,p4);
    b.SetupBoard();
    b.Show();

    srand(static_cast<unsigned int>(std::time(0)));
             
    const int COUNT = 2*4;      //max numbers of throws
    int n_rolls = 0;            //lancio dadi

    bool done = false;                  
    int player_turn = 0;                //to keep up with the turn
 
    while (!done){
        if (n_rolls==COUNT) break;
        if (player_turn == 4) player_turn = 0;

        Player* curr_player;
        curr_player = b.GetPlayer(player_turn);
        b.MovePlayer(*curr_player,curr_player->RollDice()); 
        player_turn += 1;        
        n_rolls+=1;
        }


	return 0;

}     //fine main






/*
#include "../src/board.cpp"
#include "../src/cpuplayer.cpp"
#include "../src/humanplayer.cpp"
#include "../src/player.cpp"

int main(int argc, char* argv[]){
    std::string type;
    if (argc >= 2)  type = argv[1];

    Player* p1;
    int count;
    int number_of_turns;

    if (type != "computer" && type != "Computer" && type!= "human" && type != "Human"){

        std::cout << "Errore nell'acquisizione di input via riga di comando. Procedo via input da terminale: \n";
        std::cout << "Si vuole procedere con una partita di soli giocatori CPU o con un player umano? ['computer'/'human']: ";
        std::cin >> type;
        std::cin.ignore(1, '\n'); 
    }
    if (type == "computer" || type == "Computer"){

        p1 = new CPUPlayer();
    }
    else if (type == "human" || type == "Human"){

        std::cout << "Se si vuole, inserire il nome per il proprio giocatore, altrimenti continuare [ENTER]: ";

        std::getline(std::cin, type);

        p1 = new HumanPlayer();         
        if (type.length() != 0)   p1 -> set_name(type);
    }
    else {
        std::cout << "Errore nell'acquistizione di input. Riprovare da riga di comando" << "\n";
        exit(0);
    }


    std::cout << "Inserire numero massimo di round, o continuare [ENTER] per un assegnazione automatica: ";
    //riciclo type
    std::getline(std::cin, type);

    if (type.length() == 0)   number_of_turns = 10;
    else if (std::stoi(type) > 0)   number_of_turns = std::stoi(type);
    else{
        std::cout << "Valore non valido, procedo in automatico (10 turni)" << "\n";
        number_of_turns = 10;
    }
    CPUPlayer p2;
    CPUPlayer p3;
    CPUPlayer p4;

    Board board(*p1, p2, p3, p4);
    board.set_total_turns(number_of_turns);

    std::cout << "Inserire nome file di log degli eventi, oppure continuare [ENTER] per crearne uno in automatico: ";
    std::getline(std::cin, type);

    if (type.length() != 0)   board.set_output_file(type);

    std::cout << "\n";
    bool done = false;
    while (!done){
        if ( (done = board.next()) )    break;
        std::cout << "Continuare [ENTER] ";
        std::getline(std::cin, type);
    }

    delete p1;
    p1 = nullptr;
    
    return 0;
}

    
*/


