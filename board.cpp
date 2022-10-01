#include "board.h"

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

void Board::setval(int a, int b, int c)
{
	if (Board::checksqpos(a,b))
	{
		field[a+width*b] = c;
		return;
	}
	abort();
}

int Board::getval(int a, int b)
{
	if(Board::checksqpos(a,b))
	{
		int c = field[a+width*b];
		return c;
	}
	abort();
}

bool Board::checksqpos(int a, int b)
{
	if (a<0 || a>(width-1) || b<0 || b>(height-1)) return false;
	return true;
}

bool Board::checksqvalmid(int a, int b)
{
	if (Board::getval(a,b) == 1) return true;
	return false;
}

bool Board::checksqvalend(int a, int b)
{
	if (Board::getval(a,b) == 0) return true;
	return false;
}

int Board::getwidth(){return width;}

int Board::getheight(){return height;}
