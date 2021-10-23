#ifndef CELL_HPP
#define CELL_HPP

#include <iostream>
#include <vector>
#include <string>

class Cell {
	public:
		bool occupied;
		std::string cellID;
		bool possible;

		Cell(int value) {
			occupied = true;
			possible = true;
			if(value == -1) {
				occupied = false;
			}
			if(value == -2) {
				possible = false;
			}
			
			std::string s = std::to_string(value);			
			if(s != "-1") {
				s.insert(s.begin(),' ');
			}
			cellID = s;
		}

		void drawCell() {
			if(possible == false) {
				std::cout << "       ";
			} else { std::cout << "| " << cellID << " | "; }
		}
};
			



#endif //CELL_HPP
