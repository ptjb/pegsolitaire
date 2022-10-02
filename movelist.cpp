#include "movelist.h"
#include "position.h"
#include "move.h"

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

Move MoveList::movepeg(Position position)
{
	peg.pos = position;
	Move move = peg.rmove(board);

	board.setval(move.peg_move.initial_position, 0);
	board.setval(move.position_to_clear, 0);
	board.setval(move.peg_move.final_position, 1);

	return move;
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
		Move move_taken = MoveList::movepeg(initial_peg_position);
		move_sequence.push_back(move_taken.peg_move);

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