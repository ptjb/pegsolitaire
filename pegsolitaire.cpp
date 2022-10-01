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

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cout << "\nInvalid number of arguments\nFormat Name\n" << std::endl;
		return -1;
	}

	std::string name = argv[1];

	Board camelot(name.c_str());
	Position initial_peg_position{.x=0,.y=0};
	MoveGenerator move_generator;
	Peg lancelot(initial_peg_position, move_generator);
	MoveList arthur(lancelot, camelot);

	long long int w=0;

	while (arthur.numpegs() != 1){

		arthur.reset();
		arthur.walkabout();
		w++;
		if (w % (long long int)1000 == (long long int)0) std::cout << w << std::endl;

	}

	Move t;

	for (int i=0; i<arthur.getlength(); i++){

		t = arthur.getmove(i);
		std::cout << "(" << t.position_to_clear.x << "," << t.position_to_clear.y << ") --> (" << t.new_position.x << "," << t.new_position.y << ")" << std::endl; 
	}

	return 0;
}