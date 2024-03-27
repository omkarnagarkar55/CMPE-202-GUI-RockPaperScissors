#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include "Player.h"
#include "Strategy.h"
#include <memory>
class ComputerPlayer : public Player {
public:
    ComputerPlayer(std::unique_ptr<Strategy> strategy);// Constructor that takes a strategy pointer
    Choice makeMove() override; // Override the makeMove method

private:
    std::unique_ptr<Strategy> strategy; // Pointer to a strategy object
};

#endif // COMPUTERPLAYER_H
