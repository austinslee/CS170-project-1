#ifndef __MAIN_CPP__
#define __MAIN_CPP__

#include <iostream>
#include <stdio.h>

#include "game.hpp"
#include "a.hpp"

bool operator<(Node n1, Node n2) {                                                                                    return n1.mis_cost() < n2.mis_cost();
}


int main() {
	Game test;
	Astar algo;
	Node* start = new Node(test);
	uniform_cost_search(start);

/*	while(1) {
		char input;
		test.draw_board();
		std::cin >> input;
		if(input == 'w') {
			test.move_up();
		}
		else if(input == 'a') { test.move_left(); }
		else if(input == 's') { test.move_down(); }
		else if(input == 'd') { test.move_right(); }
		

		//outputting misplaced cost
		std::cout << "\n mis: " << algo.mis_cost(test) << "\n";
	}*/
}

#endif //__MAIN_CPP__
