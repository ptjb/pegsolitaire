#include <tuple>

#include "peg.h"

Peg::Peg(Position position, MoveGenerator move_generator) : pos(position), _move_generator(move_generator)
{
	vict.x = 0;
	vict.y = 0;

	srand(time(NULL));
}

void Peg::rmove(Board c)
{
	std::vector<Move> moves = Peg::findmoves(c, pos, _move_generator);

	if (moves.size() == 0) return;

	int r = rand() % moves.size();

	Move random_move = moves[r];

	pos = random_move.new_position;
	vict = random_move.position_to_clear;

	return;	
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
		if (c.checksqpos(move.position_to_clear) && c.checksqpos(move.new_position) && c.checksqvalmid(move.position_to_clear) && c.checksqvalend(move.new_position))
		{
			valid_moves.push_back(move);
		}
	}

	return valid_moves;
}