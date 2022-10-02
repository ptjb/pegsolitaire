#include <tuple>

#include "peg.h"

Peg::Peg(MoveGenerator move_generator) : _move_generator(move_generator)
{
	srand(time(NULL));
}

Move Peg::rmove(Board c, Position peg_position)
{
	std::vector<Move> moves = Peg::findmoves(c, peg_position, _move_generator);

	if (moves.size() == 0) abort();

	int r = rand() % moves.size();

	return moves[r];
}

int Peg::nummoves(Board c, Position position)
{
	std::vector<Move> moves = Peg::findmoves(c,position,_move_generator);
	return moves.size();
}

std::vector<Move> Peg::findmoves(Board c, Position position, MoveGenerator move_generator)
{
	Move moves[] =
	{
		move_generator.GenerateNorthMove(position),
		move_generator.GenerateEastMove(position),
		move_generator.GenerateSouthMove(position),
		move_generator.GenerateWestMove(position)
	};

	std::vector<Move> valid_moves;
	for (Move move : moves)
	{
		if (c.checksqpos(move.position_to_clear) && c.checksqpos(move.peg_move.final_position) && c.checksqvalmid(move.position_to_clear) && c.checksqvalend(move.peg_move.final_position))
		{
			valid_moves.push_back(move);
		}
	}

	return valid_moves;
}