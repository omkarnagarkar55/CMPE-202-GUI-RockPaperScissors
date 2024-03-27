#include <iostream>
#include <memory>
#include <cctype> // For std::toupper
#include "include/GameEngine.h"
#include "include/HumanPlayer.h"
#include "include/RandomStrategy.h"
#include "include/SmartStrategy.h"
#include "include/Strategy.h"
#include "include/Player.h"
#include "include/FrequencyMap.h"
#include "include/FileHandler.h"


// Function to convert character input to Choice enum
Choice charToChoice(char c) {
    switch (std::toupper(c)) {
        case 'R':
            return ROCK;
        case 'P':
            return PAPER;
        case 'S':
            return SCISSORS;
        default:
            return ROCK; // Default choice
    }
}

int main() {
    std::cout << "Welcome to Rock-Paper-Scissors game!" << std::endl;
    std::cout << "Choose a strategy for the computer player:" << std::endl;
    std::cout << "1. Random strategy" << std::endl;
    std::cout << "2. Smart strategy" << std::endl;
    std::cout << "Enter your choice (1 or 2): ";
    
    int choice;
    std::cin >> choice;
    
    std::unique_ptr<Strategy> strategy;
    FileHandler fileHandler;
    FrequencyMap frequencyMap;
    
    if (choice == 1) {
        strategy = std::make_unique<RandomStrategy>();
    } else if (choice == 2) {
        fileHandler.readFrequenciesFromFile("frequencies.txt",frequencyMap.frequencyMap);
        strategy = std::make_unique<SmartStrategy>(&frequencyMap);
    } else {
        std::cerr << "Invalid choice. Exiting the game." << std::endl;
        return 1;
    }

    Player* computerPlayer = new ComputerPlayer(std::move(strategy));
    
    // Create human player object
    HumanPlayer humanPlayer;
    
    // Create the game engine and start the game
    GameEngine gameEngine(&humanPlayer, dynamic_cast<ComputerPlayer*>(computerPlayer));
    gameEngine.startGame();
    
    for (int round = 1; round <= gameEngine.getTotalRounds(); ++round) {
        char userInput;
        std::cout << "\nPress R for Rock, P for Paper, S for Scissors, or Q to quit: ";
        std::cin >> userInput;
        userInput = std::toupper(userInput); // Convert input to uppercase
        
        if (userInput == 'Q') {
            std::cout << "Exiting the game early." << std::endl;
            break;
        } else {
            Choice userChoice = charToChoice(userInput);
            gameEngine.playRound(userChoice);
        }
    }
    
    gameEngine.endGame();

    
    // End the game
    gameEngine.endGame();
    
    // Clean up dynamically allocated memory
    delete computerPlayer;
    
    return 0;
}
