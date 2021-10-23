#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <list>

#include "cell.hpp"

class Board {
	public:
		Cell* cells[11][2] = {nullptr};
		int size = 11;
		Board();
	

		void drawBoard();
};






#endif //BOARD_HPP
