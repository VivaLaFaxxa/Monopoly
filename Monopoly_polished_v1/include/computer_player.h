#ifndef COMPUTER_PLAYER_H
#define COMPUTER_PLAYER_H

#include "..//include/player.h"

class ComputerPlayer : public Player {
public:
	void PerformAction(Square* square) override;

private:

};

#endif
