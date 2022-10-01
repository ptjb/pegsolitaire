#ifndef MOVE_H
#define MOVE_H

#include "position.h"

struct Move
{
    Position new_position;
    Position position_to_clear;
};

#endif