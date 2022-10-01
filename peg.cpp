#include <tuple>

#include "peg.h"

Peg::Peg(Position position) : pos(position)
{
	vict.x = 0;
	vict.y = 0;

	srand(time(NULL));
}

void Peg::rmove(Board c)
{
	Peg::findmoves(c, pos.x, pos.y);

	if (moves.size() == 0) return;

	int r = rand() % moves.size();

	Position newpos {.x=std::get<2>(moves[r]),.y=std::get<3>(moves[r])};
	pos = newpos;
	Position newvict {.x=std::get<0>(moves[r]),.y=std::get<1>(moves[r])};
	vict = newvict;

	moves.clear();

	return;	
}

int Peg::nummoves(Board c, int a, int b)
{
	Peg::findmoves(c,a,b);
	int d = moves.size();
	moves.clear();
	return d;
}

void Peg::findmoves(Board c, int a, int b)
{
	moves.clear();

	std::tuple<int,int,int,int> trans[4];		//(jumped_over_x,jumped_over_y,moved_to_x,moved_to_y)
	trans[0] = std::make_tuple(a,b+1,a,b+2);	//						0
	trans[1] = std::make_tuple(a+1,b,a+2,b);	//						|
	trans[2] = std::make_tuple(a,b-1,a,b-2);	//					 3--x--1
	trans[3] = std::make_tuple(a-1,b,a-2,b);	//						|
												//						2
	for (int i=0; i<4; i++){

		if (c.checksqpos(std::get<0>(trans[i]), std::get<1>(trans[i])) && c.checksqpos(std::get<2>(trans[i]), std::get<3>(trans[i])) && c.checksqvalmid(std::get<0>(trans[i]), std::get<1>(trans[i])) && c.checksqvalend(std::get<2>(trans[i]), std::get<3>(trans[i]))) moves.push_back(trans[i]);
	}	//run checks on leapt over position and leapt to position and make sure they are both valid

	return;
}