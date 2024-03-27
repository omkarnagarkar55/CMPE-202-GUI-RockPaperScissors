#include "../include/RandomStrategy.h"
#include <cstdlib>
#include <ctime>

RandomStrategy::RandomStrategy() {
    // Initialize random seed
    srand(static_cast<unsigned int>(time(nullptr)));
}

Choice RandomStrategy::makeChoice() {
    // Implementation for making a random choice
    return static_cast<Choice>(rand() % 3);
}
