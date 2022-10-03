#include "board.h"
#include "position.h"

Board::Board (const char* a){

	std::ifstream file;
	file.open(a);
	char c;
	height = 0;
	width = 0;

	while(!file.eof()){

		file.get(c);
		if (c == '1') ofield.push_back(1);
		if (c == '0') ofield.push_back(0);
		if (c == '-'){

			ofield.push_back(-1);
			file.ignore();
		}
		if (c == '\n') height++;
	}
	file.close();

	height++;		//as the last line had EOF not /n
	width = ofield.size()/height;

	Board::reset();
}

void Board::reset()
{
	field = ofield;
	return;
}

void Board::setval(Position position, int c)
{
	if (!Board::_IsWithinBounds(position))
	{
		return;
	}
	field[Board::_GetFieldIndex(position)] = c;
	return;
}

int Board::getval(Position position)
{
	if(!Board::_IsWithinBounds(position))
	{
		return -1;
	}
	return field[Board::_GetFieldIndex(position)];
}

bool Board::IsOccupiedSpace(Position position)
{
	return Board::getval(position) == 1;
}

bool Board::IsEmptySpace(Position position)
{
	return Board::getval(position) == 0;
}

int Board::getwidth(){return width;}

int Board::getheight(){return height;}

int Board::_GetFieldIndex(Position position)
{
	return position.x+width*(position.y);
}

bool Board::_IsWithinBounds(Position position)
{
	return position.x>=0 && position.x<=(width-1) && position.y>=0 && position.y<=(height-1);
}
