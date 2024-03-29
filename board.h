#ifndef BOARD_H
#define BOARD_H

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <fstream>

#include "position.h"

class Board
{
	int width, height;
	std::vector<int> field;
	std::vector<int> ofield;

	public:
		Board(const char*); //give filename of board
		void reset();
		void setval(Position,int);
		int getval(Position);
		bool IsOccupiedSpace(Position);
		bool IsEmptySpace(Position);
		int getwidth();
		int getheight();
	private:
		int _GetFieldIndex(Position);
		bool _IsWithinBounds(Position);
};

#endif