#ifndef PEG_H
#define PEG_H

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>
#include <time.h>

#include "position.h"
#include "move.h"
#include "board.h"
#include "movegenerator.h"

struct Peg
{
	Position pos;
	Position vict;		//victim - peg that gets removed
	MoveGenerator _move_generator;

	Peg(Position, MoveGenerator);
	void rmove(Board);
	int nummoves(Board,Position);

	private:
		std::vector<Move> findmoves(Board,Position,MoveGenerator);
};

#endif