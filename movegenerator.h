#ifndef MOVEGENERATOR_H
#define MOVEGENERATOR_H

#include "position.h"
#include "move.h"

class MoveGenerator
{
    public:
        Move GenerateNorthMove(Position);
        Move GenerateEastMove(Position);
        Move GenerateSouthMove(Position);
        Move GenerateWestMove(Position);
};

#endif