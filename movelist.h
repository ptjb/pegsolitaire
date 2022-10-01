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

class MoveList
{
	Peg peg;
	Board board;
	std::vector<int> moveables;
	std::vector<std::tuple<int,int,int,int> > moves;
	public:
		MoveList(Peg, Board);
		void findmoveables();
		void reset();
		void selectpeg();
		void setpeg(int,int);
		void movepeg();
		bool canmove(int,int);
		void walkabout();
		int numpegs();
		std::tuple<int,int,int,int> getmove(int);
		int getlength();
};

#endif