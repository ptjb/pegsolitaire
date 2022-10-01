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
#include "move.h"

class MoveList
{
	Peg peg;
	Board board;
	std::vector<int> moveables;
	std::vector<Move> move_sequence;
	public:
		MoveList(Peg, Board);
		void findmoveables();
		void reset();
		void selectpeg();
		void setpeg(Position);
		void movepeg();
		bool canmove(Position);
		void walkabout();
		int numpegs();
		Move getmove(int);
		int getlength();
};

#endif