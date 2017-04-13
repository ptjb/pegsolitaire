#include "movelist.h"

movelist::movelist (peg a, board b) : k(a), d(b)/*, t(0)*/ {

	//d.setval(k.x(), k.y(), t);
	/*std::cout << "\ntm" << std::endl;*/
	movelist::findmoveables();
}

void movelist::findmoveables (){

	moveables.clear();

	for (int j=0; j < d.getheight(); j++){
		
		for (int i=0; i < d.getwidth(); i++){

			//if (movelist::canmove(i,j)) moveables.push_back(i+(d.getwidth())*j);

			if (movelist::canmove(i,j)){

				moveables.push_back(i+(d.getwidth())*j);
				//std::cout << i << "\t" << j << "\t" << k.nummoves(d,i,j) << std::endl;		//pass
			} 
		}
	}

	//std::cout << "\n";


	return;
}

void movelist::reset (){

	//t=0;
	d.reset();
	moveables.clear();
	moves.clear();
	//k.reset();
	//d.setval(k.x(), k.y(), t);

	movelist::findmoveables();
	return;
}

void movelist::selectpeg (){
	//randomly select peg, update peg pos

	int r = rand() % moveables.size();
	movelist::setpeg((moveables[r] % d.getwidth()), (moveables[r] / d.getwidth()));		//integer division will kill x coord

	//std::cout << (moveables[r] % d.getwidth()) << "\t" << (moveables[r] / d.getwidth()) << std::endl;
	return;
}

void movelist::setpeg (int a, int b){

	if (!d.checksqpos(a,b)) {

		//std::cout << "\nInvalid position\n" << std::endl;
		return;
	}

	//d.setval(a,b,0);
	k.setpos(a,b);
	std::tuple<int,int,int,int> t = std::make_tuple(a,b,-1,-1);
	moves.push_back(t);
	return;
}

void movelist::movepeg (){

	/*int xo = k.x(), yo = k.y();
	
	std::cout << "\n" << xo << "\t" << yo << std::endl;*/
	d.setval(std::get<0>(moves.back()), std::get<1>(moves.back()), 0);		//here there is a valid move so prepare space as if it's moved off	

	k.rmove(d);

	//std::cout << "\n" << k.x() << "\t" << k.y() << "\t" << d.getval(k.x(), k.y());
	//std::cout << "\nmk" << std::endl;
	/*if (!d.checksquare(k.x(), k.y())) {

		k.setpos(xo, yo);
		movelist::movepeg();
		return;
	}*/

	//std::cout << "\nwalk" << std::endl;

	//t++;


	d.setval(k.x(), k.y(), 1);
	d.setval(k.x_v(), k.y_v(), 0);

	//std::cout << d.getval(std::get<0>(moves.back()), std::get<1>(moves.back())) << "\t" << d.getval(k.x_v(), k.y_v()) << "\t" << d.getval(k.x(), k.y()) << std::endl;
	
	//std::cout << "\t" << d.getval(k.x(), k.y());// << "\t" << k.kboardval(k.x(), k.y());


	//k.boardupdate(d);     //!!!!!!!!!!!

	//std::cout << "\t" << d.getval(k.x(), k.y()) << "\t" << k.kboardval(k.x(), k.y());

	//std::cout << "\n" << t << "\t" << d.getval(k.x(), k.y()) << std::endl;
	return;
}

bool movelist::canmove (int a, int b){

	/*std::pair<int,int> trans[8];
	trans[0] = std::make_pair(a+1,b+2);
	trans[1] = std::make_pair(a+2,b+1);
	trans[2] = std::make_pair(a+2,b-1);
	trans[3] = std::make_pair(a+1,b-2);
	trans[4] = std::make_pair(a-1,b-2);
	trans[5] = std::make_pair(a-2,b-1);
	trans[6] = std::make_pair(a-2,b+1);
	trans[7] = std::make_pair(a-1,b+2);

	for (int i=0; i<8; i++){

		//std::cout << "\ncm" << std::endl;
		if (d.checksquare(trans[i].first, trans[i].second)) return true;
	}

		//if (d.checksquare(trans[0].first, trans[0].second)) return true;*/
	if (d.getval(a,b) != 1) return false;
	if (k.nummoves(d,a,b) == 0) return false;

	return true;
}

void movelist::walkabout (){

	//int h=0;

	while (moveables.size() != 0){
	//while (h<11){
		//std::cout << "\nwb" << std::endl;
		movelist::selectpeg();
		movelist::movepeg();
		std::tuple<int,int,int,int> t = moves.back();
		std::get<2>(t) = k.x();
		std::get<3>(t) = k.y();
		moves.back() = t;

		//std::cout << "(" << std::get<0>(t) << "," << std::get<1>(t) << ") --> (" << std::get<2>(t) << "," << std::get<3>(t) << ")\n";		//pass
		movelist::findmoveables();

		//h++;

		
	}

	return;
}

int movelist::numpegs(){

	int a=0;

	for (int j=0; j < d.getheight(); j++){
		
		for (int i=0; i < d.getwidth(); i++){

			if (d.getval(i,j) == 1) a++;
		}
	}

	return a;
}

std::tuple<int,int,int,int> movelist::getmove(int a) {return moves[a];}

int movelist::getlength() {return moves.size();}