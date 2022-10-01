#ifndef PEG_H
#define PEG_H

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>
#include <time.h>

#include "position.h"
#include "board.h"

struct Peg
{
	Position pos;
	Position vict;		//victim - peg that gets removed
	std::vector<std::tuple<int,int,int,int> > moves;

	Peg(Position);
	void rmove(Board);
	int nummoves(Board,int,int);

	private:
		void findmoves(Board,int,int);
};

#endif