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
		std::vector<PegMove> move_sequence;
		
		MoveList(Peg, Board);
		void findmoveables();
		void reset();
		Position selectpeg();
		void movepeg(Position);
		bool canmove(Position);
		void walkabout();
		int numpegs();
};

#endif