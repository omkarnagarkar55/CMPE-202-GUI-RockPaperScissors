#ifndef FREQUENCYMAP_H
#define FREQUENCYMAP_H

#include <unordered_map>
#include "Choice.h"
#include <string>

class FrequencyMap {
private:
    const int N = 5; // Lookback window for patterns
    //std::string sequence;  // Stores the last N-1 moves
    
public:
    std::string sequence;
    void updateFrequencyMap(char move);
    Choice predictNextMove();
    std::unordered_map<std::string, std::unordered_map<char, int>> frequencyMap; // Frequency of patterns
};

#endif // FREQUENCYMAP_H
