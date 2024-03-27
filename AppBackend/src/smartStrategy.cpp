#include "../include/SmartStrategy.h"

SmartStrategy::SmartStrategy(FrequencyMap* frequencyMap): frequencyMap(frequencyMap){}

Choice SmartStrategy::makeChoice() {
    Choice choice = frequencyMap->predictNextMove();
    return winningChoiceAgainst(choice);

}

Choice SmartStrategy::winningChoiceAgainst(Choice choice) {
    switch (choice) {
    case ROCK:
        return PAPER;
    case PAPER:
        return SCISSORS;
    case SCISSORS:
        return ROCK;
    default:
        return ROCK;
    }
}