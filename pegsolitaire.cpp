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
	/*if (argc < 3)
	{
		std::cout << "\nInvalid number of arguments\nFormat X Y (xo yo)\n" << std::endl;
		return 0;
	}

	int X = atoi(argv[1]);			//Board size
	int Y = atoi(argv[2]);

	int xo = 0;
	int yo = 0;

	if (argc == 5)
	{
		xo = atoi(argv[3]);
		yo = atoi(argv[4]);

		if (xo < 0 || xo > X-1 || yo < 0 || yo > Y-1)
		{
			std::cout << "\nInvalid initial position\n" << std::endl;
			return 0;
		}
	}*/

	if (argc < 2)
	{
		std::cout << "\nInvalid number of arguments\nFormat Name\n" << std::endl;
	}

	std::string name = argv[1];

	

	board camelot(name.c_str());
	peg lancelot(0, 0);
	movelist arthur(lancelot, camelot);

	long long int w=0;

	while (arthur.numpegs() != 1){

		arthur.reset();
		arthur.walkabout();
		//std::cout << "\nhit" << std::endl;
		//std::cout << "Path of length: " << arthur.walklength() << std::endl;
		//std::cout << arthur.numpegs() << std::endl;
		w++;
		if (w % (long long int)1000 == (long long int)0) std::cout << w << std::endl;

	}

	/*for (int j=0; j<Y; j++){

		sol << "\n";

		for (int i=0; i<X; i++){

			sol << arthur.boardval(i,j) << "\t";
		}
	}*/

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