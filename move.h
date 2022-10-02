#ifndef MOVE_H
#define MOVE_H

#include "position.h"
#include "pegmove.h"

struct Move
{
    PegMove peg_move;
    Position position_to_clear;
};

#endif