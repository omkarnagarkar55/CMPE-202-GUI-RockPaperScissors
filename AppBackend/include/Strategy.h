#ifndef STRATEGY_H
#define STRATEGY_H

#include "Choice.h"

class Strategy{
public:
    virtual ~Strategy() = default;
    virtual Choice makeChoice() = 0;
};

#endif