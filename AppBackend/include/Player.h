#ifndef PLAYER_H
#define PLAYER_H

#include "Choice.h"

class Player {
public:
    virtual Choice makeMove() = 0;
};

#endif // PLAYER_H
