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

		//std::cout << ofield.back() << std::endl;			//pass
		//std::cout << height << std::endl;					//pass
	}
	file.close();

	height++;		//as the last line had EOF not /n
	width = ofield.size()/height;

	//std::cout << height << "\t" << width << std::endl;	//pass

	board::reset();
	//std::cout << "\nboard" << std::endl;
}

void board::reset(){

	//field.assign(width*height, -1);
	field = ofield;
	return;
}

void board::setval(int a, int b, int c){

	if (board::checksqpos(a,b)) {
		field[a+width*b] = c;

		//std::cout << "\t" << a+width*b << "\t" << field[a+width*b];

		return;
	}
	
	abort();
}

int board::getval(int a, int b){

	if(board::checksqpos(a,b)){
		int c = field[a+width*b];
		return c;
	}
	abort();
}

bool board::checksqpos(int a, int b){

	//std::cout << "\ncs" << std::endl;

	if (a<0 || a>(width-1) || b<0 || b>(height-1)) return false;
	
	//std::cout << "\ncs2" << std::endl;


	//if (board::getvallegal(a,b) != -1) return false;

	//std::cout << "\ncs3" << std::endl;

	return true;
}

bool board::checksqvalmid(int a, int b){

	//if (board::getval(a,b) != -1) std::cout << "\t" << board::getval(a,b);
	//std::cout << a << "/" << b << "/" << board::getval(a,b) << ",";


	if (board::getval(a,b) == 1) return true;

	return false;
	//return false;
}

bool board::checksqvalend(int a, int b){

	//if (board::getval(a,b) != -1) std::cout << "\t" << board::getval(a,b);
	//std::cout << a << "/" << b << "/" << board::getval(a,b) << ",";


	if (board::getval(a,b) == 0) return true;

	return false;
	//return false;
}
int board::getwidth(){return width;}

int board::getheight(){return height;}

//std::vector<int> board::getfield(){return field;}

/*board board::operator= (const board& c){

	board e(width, height);

	e.field = c.field;
		
	return e;
}*/

/*int board::getvallegal(int a, int b){

	int c = field[a+width*b];
	return c;
}*/
