#ifndef movelist_H
#define movelist_H

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <utility>
#include <tuple>

#include "peg.h"
#include "board.h"

class movelist
{
	peg k;
	board d;
	std::vector<int> moveables;
	std::vector<std::tuple<int,int,int,int> > moves;
	//int t;
	public:
		movelist(peg, board);
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