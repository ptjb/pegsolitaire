#include "movelist.h"

movelist::movelist (peg a, board b) : k(a), d(b)
{
	movelist::findmoveables();
}

void movelist::findmoveables (){

	moveables.clear();

	for (int j=0; j < d.getheight(); j++)
	{
		for (int i=0; i < d.getwidth(); i++)
		{
			if (movelist::canmove(i,j)){

				moveables.push_back(i+(d.getwidth())*j);
			} 
		}
	}

	return;
}

void movelist::reset ()
{
	d.reset();
	moveables.clear();
	moves.clear();

	movelist::findmoveables();
	return;
}

void movelist::selectpeg ()
{
	//randomly select peg, update peg pos

	int r = rand() % moveables.size();
	movelist::setpeg((moveables[r] % d.getwidth()), (moveables[r] / d.getwidth()));		//integer division will kill x coord

	return;
}

void movelist::setpeg (int a, int b){

	if (!d.checksqpos(a,b))
	{
		return;
	}

	k.setpos(a,b);
	std::tuple<int,int,int,int> t = std::make_tuple(a,b,-1,-1);
	moves.push_back(t);
	return;
}

void movelist::movepeg ()
{
	d.setval(std::get<0>(moves.back()), std::get<1>(moves.back()), 0);		//here there is a valid move so prepare space as if it's moved off	

	k.rmove(d);

	d.setval(k.x(), k.y(), 1);
	d.setval(k.x_v(), k.y_v(), 0);

	return;
}

bool movelist::canmove (int a, int b)
{
	if (d.getval(a,b) != 1) return false;
	if (k.nummoves(d,a,b) == 0) return false;

	return true;
}

void movelist::walkabout ()
{
	while (moveables.size() != 0)
	{
		movelist::selectpeg();
		movelist::movepeg();
		std::tuple<int,int,int,int> t = moves.back();
		std::get<2>(t) = k.x();
		std::get<3>(t) = k.y();
		moves.back() = t;

		movelist::findmoveables();
	}

	return;
}

int movelist::numpegs(){

	int a=0;

	for (int j=0; j < d.getheight(); j++)
	{
		for (int i=0; i < d.getwidth(); i++)
		{
			if (d.getval(i,j) == 1) a++;
		}
	}

	return a;
}

std::tuple<int,int,int,int> movelist::getmove(int a) {return moves[a];}

int movelist::getlength() {return moves.size();}