#include "../include/HumanPlayer.h"
#include <iostream>


Choice HumanPlayer::makeMove() {
    std::cout << "Enter your choice (R for Rock, P for Paper, S for Scissors): ";
    char userInput;
    std::cin >> userInput;
    userInput = std::toupper(userInput);

    switch (userInput) {
        case 'R':
            return ROCK;
        case 'P':
            return PAPER;
        case 'S':
            return SCISSORS;
        default:
            std::cerr << "Invalid choice. Defaulting to Rock." << std::endl;
            return ROCK; // Default choice
    }
}
