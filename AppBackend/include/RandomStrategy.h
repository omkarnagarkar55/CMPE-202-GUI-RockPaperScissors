#ifndef RANDOMSTRATEGY_H
#define RANDOMSTRATEGY_H

#include "Strategy.h"

class RandomStrategy : public Strategy {
public:
    RandomStrategy();
    Choice makeChoice() override;
};

#endif // RANDOMSTRATEGY_H