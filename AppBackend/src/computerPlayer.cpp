#include "../include/ComputerPlayer.h"
#include "../include/Strategy.h"

ComputerPlayer::ComputerPlayer(std::unique_ptr<Strategy> strategy)
    : strategy(std::move(strategy)) {
}

// Use the strategy object to make a move
Choice ComputerPlayer::makeMove() {
    return strategy->makeChoice();
}
