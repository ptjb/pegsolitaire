#ifndef MOVEVALIDATOR_H
#define MOVEVALIDATOR_H

#include "board.h"
#include "move.h"

class MoveValidator
{
    public:
        bool IsValidMove(Board, Move);
};

#endif