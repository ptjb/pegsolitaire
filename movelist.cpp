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

	MoveList::findmoveables();
	return;
}

Position MoveList::selectpeg()
{
	//randomly select peg, update peg pos

	int r = rand() % moveables.size();
	Position position{.x=(moveables[r] % board.getwidth()),.y=(moveables[r] / board.getwidth())}; //integer division will kill x coord
	return position;
}

void MoveList::movepeg(Position position)
{
	peg.pos = position;
	board.setval(peg.pos, 0);//here there is a valid move so prepare space as if it's moved off	

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

std::vector<PegMove> MoveList::walkabout()
{
	std::vector<PegMove> move_sequence;
	while (moveables.size() != 0)
	{
		Position initial_peg_position = MoveList::selectpeg();
		MoveList::movepeg(initial_peg_position);
		PegMove t{.initial_position=initial_peg_position,.final_position=peg.pos};
		move_sequence.push_back(t);

		MoveList::findmoveables();
	}

	return move_sequence;
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