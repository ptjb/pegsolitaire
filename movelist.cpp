#include "movelist.h"
#include "position.h"

MoveList::MoveList(Peg a, Board b) : peg(a), board(b)
{
	MoveList::findmoveables();
}

void MoveList::findmoveables(){

	moveables.clear();

	for (int j=0; j < board.getheight(); j++)
	{
		for (int i=0; i < board.getwidth(); i++)
		{
			Position position{.x=i,.y=j};
			if (MoveList::canmove(position))
			{
				moveables.push_back(i+(board.getwidth())*j);
			} 
		}
	}

	return;
}

void MoveList::reset()
{
	board.reset();
	moveables.clear();
	move_sequence.clear();

	MoveList::findmoveables();
	return;
}

void MoveList::selectpeg()
{
	//randomly select peg, update peg pos

	int r = rand() % moveables.size();
	Position position{.x=(moveables[r] % board.getwidth()),.y=(moveables[r] / board.getwidth())}; //integer division will kill x coord
	MoveList::setpeg(position);		

	return;
}

void MoveList::setpeg(Position position)
{
	if (!board.checksqpos(position))
	{
		return;
	}

	peg.pos = position;
	Position new_position{.x=-1,.y=-1};
	Move t{.new_position=new_position,.position_to_clear=position};//this is dodgey
	move_sequence.push_back(t);
	return;
}

void MoveList::movepeg()
{
	board.setval(move_sequence.back().position_to_clear, 0);		//here there is a valid move so prepare space as if it's moved off	

	peg.rmove(board);

	board.setval(peg.pos, 1);
	board.setval(peg.vict, 0);

	return;
}

bool MoveList::canmove(Position position)
{
	if (board.getval(position) != 1) return false;
	if (peg.nummoves(board,position) == 0) return false;

	return true;
}

void MoveList::walkabout()
{
	while (moveables.size() != 0)
	{
		MoveList::selectpeg();
		MoveList::movepeg();
		Move t = move_sequence.back();
		t.new_position = peg.pos;
		move_sequence.back() = t;

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
			Position position{.x=i,.y=j};
			if (board.getval(position) == 1) a++;
		}
	}

	return a;
}

Move MoveList::getmove(int a) {return move_sequence[a];}

int MoveList::getlength() {return move_sequence.size();}