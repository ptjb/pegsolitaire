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

class Peg
{
	std::pair<int,int> pos;
	std::pair<int,int> vict;		//victim - peg that gets removed
	std::vector<std::tuple<int,int,int,int> > moves;

	public:
		Peg(int,int);
		int x();
		int y();
		int x_v();
		int y_v();
		void setpos(int,int);
		void setvict(int,int);
		void rmove(Board);
		int nummoves(Board,int,int);

	private:
		void findmoves(Board,int,int);
};

#endif