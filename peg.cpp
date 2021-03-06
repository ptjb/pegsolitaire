#include "peg.h"

/*peg::peg (board c, int a, int b) : d(c){

	pos.first = a;
	pos.second = b;

	opos.first = a;
	opos.second =b;

	//std::cout << "\npeg" << std::endl;
}*/

peg::peg (int a, int b){

	pos.first = a;
	pos.second = b;

	vict.first = 0;
	vict.second = 0;

	srand(time(NULL));

	//std::cout << "\npeg" << std::endl;
}


int peg::x () {return pos.first;}

int peg::y () {return pos.second;}

int peg::x_v () {return vict.first;}

int peg::y_v () {return vict.second;}

/*void peg::reset(){

	pos = opos;
	return;
}*/

void peg::setpos(int a, int b){

	pos.first = a;
	pos.second = b;
	return;
}

void peg::setvict(int a, int b){

	vict.first = a;
	vict.second = b;
	return;
}

void peg::rmove (board c){

	//std::cout << "\nrm" << std::endl;

	peg::findmoves(c, pos.first, pos.second);

	//std::cout << "\t" << moves.size() << std::endl;

	if (moves.size() == 0) return;

	
	int r = rand() % moves.size();

	/*std::pair<int,int> trans[8];
	trans[0] = std::make_pair(1,2);
	trans[1] = std::make_pair(2,1);
	trans[2] = std::make_pair(2,-1);
	trans[3] = std::make_pair(1,-2);
	trans[4] = std::make_pair(-1,-2);
	trans[5] = std::make_pair(-2,-1);
	trans[6] = std::make_pair(-2,1);
	trans[7] = std::make_pair(-1,2);*/

	//for (int i=0; i<8; i++){

	//	if ()
	//}

	peg::setpos(std::get<2>(moves[r]), std::get<3>(moves[r]));
	peg::setvict(std::get<0>(moves[r]), std::get<1>(moves[r]));

	moves.clear();

	return;	
}

int peg::nummoves(board c, int a, int b){

	peg::findmoves(c,a,b);
	int d = moves.size();
	moves.clear();
	return d;
}

void peg::findmoves(board c, int a, int b){

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

/*void peg::boardupdate(board c){

	///d.c.getwidth();
	//d.height = c.getheight();
	//d.field = c.getfield();

	d=c;
	
	return;
}*/

/*int peg::kboardval(int a, int b){

	int c=d.getval(a,b);
	return c;
}*/