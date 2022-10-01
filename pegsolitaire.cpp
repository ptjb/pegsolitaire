#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <time.h>
#include <tuple>
#include <string>

#include "peg.h"
#include "board.h"
#include "movelist.h"

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cout << "\nInvalid number of arguments\nFormat Name\n" << std::endl;
	}

	std::string name = argv[1];

	Board camelot(name.c_str());
	Peg lancelot(0, 0);
	MoveList arthur(lancelot, camelot);

	long long int w=0;

	while (arthur.numpegs() != 1){

		arthur.reset();
		arthur.walkabout();
		w++;
		if (w % (long long int)1000 == (long long int)0) std::cout << w << std::endl;

	}

	std::stringstream outname;
	outname << "solution_for_" << name << "_" << time(NULL) << ".txt";

	std::ofstream sol;
	sol.open((outname.str()).c_str());

	std::tuple<int,int,int,int> t;

	for (int i=0; i<arthur.getlength(); i++){

		t = arthur.getmove(i);

		sol << "(" << std::get<0>(t) << "," << std::get<1>(t) << ") --> (" << std::get<2>(t) << "," << std::get<3>(t) << ")\n"; 

	}

	sol.close();
	return 0;
}