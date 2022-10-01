#ifndef BOARD_H
#define BOARD_H

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <fstream>

class board
{
	int width, height;
	std::vector<int> field;
	std::vector<int> ofield;

	public:
		board(const char*);		//give filename of board
		void reset();
		void setval(int,int,int);
		int getval(int,int);
		bool checksqpos(int,int);
		bool checksqvalmid(int,int);
		bool checksqvalend(int,int);
		int getwidth();
		int getheight();
};

#endif