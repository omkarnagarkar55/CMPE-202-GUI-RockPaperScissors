#include "../include/GameEngine.h"
#include <iostream>
#include <string>

GameEngine::GameEngine(Player* human, ComputerPlayer* computer) : humanPlayer(human), computerPlayer(computer) {
}

void GameEngine::setTotalRounds(int rounds) {
    this->totalRounds = rounds;
}

void GameEngine::startGame() {
    // std::cout << "Rock, Paper, Scissors Game against the Computer!\n";
    // std::cout << "Enter the number of rounds you want to play: ";
    int rounds = 20;
    // std::cin >> rounds;
    setTotalRounds(rounds);
}

std::string GameEngine::playRound(Choice userChoice) {
    currentRound++;
    std::cout << "\nRound " << currentRound << " of " << totalRounds << std::endl;
    
    Choice computerChoice = computerPlayer->makeMove();
    std::cout << "User chose: " << choiceToString(userChoice) << std::endl;
    std::cout << "Computer chose: " << choiceToString(computerChoice) << std::endl;
    
    int winner = determineWinner(userChoice, computerChoice);
    
    if (winner == 0) {
        std::cout << "It's a draw!\n";
        ties++;
        return "Tie";
    } else if (winner == 1) {
        std::cout << "You win!\n";
        humanWins++;
        return "Human";
    } else {
        std::cout << "Computer wins!\n";
        computerWins++;
        return "Computer";
    }

    //displayCurrentScore();
}

void GameEngine::displayCurrentScore() {
    std::cout << "Current Score after " << currentRound << " rounds: \n";
    std::cout << "Human Wins: " << humanWins << "\n";
    std::cout << "Computer Wins: " << computerWins << "\n";
    std::cout << "Ties: " << ties << "\n";
}

void GameEngine::endGame() {
    std::cout << "\nGame ended!\nFinal Score:\n";
    displayCurrentScore();
    // Any additional cleanup can be added here
}

int GameEngine::getTotalRounds() const {
    return totalRounds;
}

int GameEngine::determineWinner(Choice userChoice, Choice computerChoice) {
    // Check for a draw
    if (userChoice == computerChoice) {
        return 0; // Draw
    }
    
    // Check for cases where the user wins
    if ((userChoice == ROCK && computerChoice == SCISSORS) ||
        (userChoice == PAPER && computerChoice == ROCK) ||
        (userChoice == SCISSORS && computerChoice == PAPER)) {
        return 1; // User wins
    }

    // If none of the above, computer wins
    return -1; // Computer wins
}

std::string GameEngine::choiceToString(Choice c) {
    switch (c) {
        case ROCK:
            return "Rock";
        case PAPER:
            return "Paper";
        case SCISSORS:
            return "Scissors";
        default:
            return "Unknown";
    }
}
