#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "Player.h"
#include "ComputerPlayer.h"
#include <iostream>
#include <string>

class GameEngine {
private:
    Player* humanPlayer;
    ComputerPlayer* computerPlayer;
    int totalRounds = 0;
    int currentRound = 0;
    int humanWins = 0;
    int computerWins = 0;
    int ties = 0;

public:
    GameEngine(Player* human, ComputerPlayer* computer);
    int determineWinner(Choice userChoice, Choice computerChoice);
    void setTotalRounds(int rounds);
    void startGame();
    std::string playRound(Choice userChoice);
    void endGame();
    void displayCurrentScore();
    static std::string choiceToString(Choice c);
    int getTotalRounds() const;
};

#endif // GAMEENGINE_H
