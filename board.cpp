#include "board.h"

board::board (const char* a){

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

	board::reset();
}

void board::reset()
{
	field = ofield;
	return;
}

void board::setval(int a, int b, int c)
{
	if (board::checksqpos(a,b))
	{
		field[a+width*b] = c;
		return;
	}
	
	abort();
}

int board::getval(int a, int b)
{
	if(board::checksqpos(a,b))
	{
		int c = field[a+width*b];
		return c;
	}
	abort();
}

bool board::checksqpos(int a, int b)
{
	if (a<0 || a>(width-1) || b<0 || b>(height-1)) return false;
	return true;
}

bool board::checksqvalmid(int a, int b)
{
	if (board::getval(a,b) == 1) return true;
	return false;
}

bool board::checksqvalend(int a, int b)
{
	if (board::getval(a,b) == 0) return true;
	return false;
}
int board::getwidth(){return width;}

int board::getheight(){return height;}
