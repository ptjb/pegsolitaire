#include "peg.h"

Peg::Peg (int a, int b)
{
	pos.first = a;
	pos.second = b;

	vict.first = 0;
	vict.second = 0;

	srand(time(NULL));
}


int Peg::x () {return pos.first;}

int Peg::y () {return pos.second;}

int Peg::x_v () {return vict.first;}

int Peg::y_v () {return vict.second;}

void Peg::setpos(int a, int b)
{
	pos.first = a;
	pos.second = b;
	return;
}

void Peg::setvict(int a, int b)
{
	vict.first = a;
	vict.second = b;
	return;
}

void Peg::rmove (Board c)
{
	Peg::findmoves(c, pos.first, pos.second);

	if (moves.size() == 0) return;

	int r = rand() % moves.size();

	Peg::setpos(std::get<2>(moves[r]), std::get<3>(moves[r]));
	Peg::setvict(std::get<0>(moves[r]), std::get<1>(moves[r]));

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