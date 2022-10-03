#include <iostream>
#include <cstdlib>
#include <cmath>
#include <time.h>
#include <tuple>
#include <string>

#include "peg.h"
#include "board.h"
#include "movelist.h"
#include "move.h"
#include "pegmove.h"

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cout << "\nInvalid number of arguments\nFormat Name\n" << std::endl;
		return -1;
	}

	std::string name = argv[1];

	Board camelot(name.c_str());
	MoveGenerator move_generator;
	MoveValidator move_validator;
	Peg lancelot(move_generator, move_validator);
	MoveList arthur(lancelot, camelot);

	long long int w=0;

	std::vector<PegMove> move_sequence;
	while (arthur.numpegs() != 1){

		arthur.reset();
		move_sequence = arthur.walkabout();
		w++;
		if (w % (long long int)1000 == (long long int)0) std::cout << w << std::endl;

	}

	for (PegMove move : move_sequence)
	{
		std::cout << "(" << move.initial_position.x << "," << move.initial_position.y << ") --> (" << move.final_position.x << "," << move.final_position.y << ")" << std::endl; 
	}

	return 0;
}