#ifndef HUMAN_PLAYER_H
#define HUMAN_PLAYER_H

#include "player.h"

class Board;

class HumanPlayer : public Player{
public:
	HumanPlayer(Board* board);

	HumanPlayer(Board* board, int id);

	HumanPlayer();

	void PerformAction(Square* square);

	

private:

};

#endif


//La strada giusta secondo me, sarebbe farla static, cosi che non devi avere un oggetto per invocarla
//Motiviamo lo static: la board e' una a partita, e' correlata alla classe non ad un oggetto specifico
//Se prende qualcosa in input deve essere il vettore board, board e' un array di puntatori ad oggetti square, 
//show(std::vector <square*> board_), che e' variabile membro della board
//Se invece non prende in input, puo essere tranquillamente una funzione della classe board stessa, cosi da poter accedere
//direttamente al vettore squares_, senza dover chiedere in input qualcosa.
//Hai accesso al vettore senza chiederlo.
//Il gioco e' da terminale, il giocatore che usa show, lo deve poter usare terminale, check per eventuali input di comando
