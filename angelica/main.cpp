#include <iostream>

#include "game.hpp"


int main() {
	Game test;
	while(1) {
		char input;
		test.draw_board();
		std::cin >> input;
		if(input == 'w') {
			test.move_up();
		}
		else if(input == 'a') { test.move_left(); }
		else if(input == 's') { test.move_down(); }
		else if(input == 'd') { test.move_right(); }
	}
}
