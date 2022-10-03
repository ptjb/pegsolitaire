#ifndef movelist_H
#define movelist_H

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <utility>
#include <tuple>

#include "position.h"
#include "peg.h"
#include "board.h"
#include "pegmove.h"

class MoveList
{
	Peg peg;
	Board board;
	std::vector<int> moveables;
	public:		
		MoveList(Peg, Board);
		//std::vector<Move> FindAvailableMoves(Board);
		void findmoveables();
		void reset();
		Position selectpeg();
		Move movepeg(Position);
		bool canmove(Position);
		std::vector<PegMove> walkabout();
		int numpegs();
};

#endif