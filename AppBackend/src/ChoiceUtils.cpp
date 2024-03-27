#include "../include/ChoiceUtils.h"
#include <string>


// Converts a Choice to its string representation
std::string choiceToString(Choice c) {
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

// Converts a character to a Choice
Choice charToChoice(char c) {
    switch (c) {
    case 'R':
        return ROCK;
    case 'P':
        return PAPER;
    case 'S':
        return SCISSORS;
    default:
        return ROCK; // Default to ROCK if the character is unrecognized
    }
}

