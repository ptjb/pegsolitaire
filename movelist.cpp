#include "movelist.h"

MoveList::MoveList (Peg a, Board b) : peg(a), board(b)
{
	MoveList::findmoveables();
}

void MoveList::findmoveables (){

	moveables.clear();

	for (int j=0; j < board.getheight(); j++)
	{
		for (int i=0; i < board.getwidth(); i++)
		{
			if (MoveList::canmove(i,j)){

				moveables.push_back(i+(board.getwidth())*j);
			} 
		}
	}

	return;
}

void MoveList::reset ()
{
	board.reset();
	moveables.clear();
	moves.clear();

	MoveList::findmoveables();
	return;
}

void MoveList::selectpeg ()
{
	//randomly select peg, update peg pos

	int r = rand() % moveables.size();
	MoveList::setpeg((moveables[r] % board.getwidth()), (moveables[r] / board.getwidth()));		//integer division will kill x coord

	return;
}

void MoveList::setpeg (int a, int b){

	if (!board.checksqpos(a,b))
	{
		return;
	}

	peg.setpos(a,b);
	std::tuple<int,int,int,int> t = std::make_tuple(a,b,-1,-1);
	moves.push_back(t);
	return;
}

void MoveList::movepeg ()
{
	board.setval(std::get<0>(moves.back()), std::get<1>(moves.back()), 0);		//here there is a valid move so prepare space as if it's moved off	

	peg.rmove(board);

	board.setval(peg.x(), peg.y(), 1);
	board.setval(peg.x_v(), peg.y_v(), 0);

	return;
}

bool MoveList::canmove (int a, int b)
{
	if (board.getval(a,b) != 1) return false;
	if (peg.nummoves(board,a,b) == 0) return false;

	return true;
}

void MoveList::walkabout ()
{
	while (moveables.size() != 0)
	{
		MoveList::selectpeg();
		MoveList::movepeg();
		std::tuple<int,int,int,int> t = moves.back();
		std::get<2>(t) = peg.x();
		std::get<3>(t) = peg.y();
		moves.back() = t;

		MoveList::findmoveables();
	}

	return;
}

int MoveList::numpegs(){

	int a=0;

	for (int j=0; j < board.getheight(); j++)
	{
		for (int i=0; i < board.getwidth(); i++)
		{
			if (board.getval(i,j) == 1) a++;
		}
	}

	return a;
}

std::tuple<int,int,int,int> MoveList::getmove(int a) {return moves[a];}

int MoveList::getlength() {return moves.size();}