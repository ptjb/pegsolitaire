#ifndef PEG_H
#define PEG_H

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>
#include <time.h>
#include <tuple>

#include "board.h"

class peg
{
	std::pair<int,int> pos;
	std::pair<int,int> vict;		//victim - peg that gets removed
	//std::pair<int,int> opos;
	std::vector<std::tuple<int,int,int,int> > moves;

	public:
		peg(int,int);
		int x();
		int y();
		int x_v();
		int y_v();
		//void reset();
		void setpos(int,int);
		void setvict(int,int);
		void rmove(board);
		int nummoves(board,int,int);

	private:
		void findmoves(board,int,int);
};

#endif