#ifndef SMARTSTRATEGY_H
#define SMARTSTRATEGY_H

#include "Strategy.h"
#include "FrequencyMap.h"

class SmartStrategy : public Strategy {
public:
    SmartStrategy(FrequencyMap* frequencyMap);
    Choice makeChoice() override;
    Choice winningChoiceAgainst(Choice choice);
private:
    FrequencyMap* frequencyMap;
};

#endif // SMARTSTRATEGY_H
