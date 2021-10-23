#include <iostream>
#include <stdio.h>


#include "board.hpp"
#include "cell.hpp"


Board::Board() {
	for(int i = 0; i < size; i++) {
		cells[i][0] = new Cell(i);
	}
	cells[3][1] = new Cell(-1);
	cells[5][1] = new Cell(-1);
	cells[7][1] = new Cell(-1);
	for(int j = 0; j < 10; j++) {
		if(j == 3 || j == 5 || j == 7) {
			cells[j][1] = new Cell(-1);
		} else { cells[j][1] = new Cell(-2); }
	}		
} 

void Board::drawBoard() {
	for(int j = 1; j > -1; j--) {
		std::cout << "\n";
		for(int i = 0; i < 10; i++) {
			if(cells[i][j] != nullptr) {
				cells[i][j]->drawCell();
			}
		}
	}
}
