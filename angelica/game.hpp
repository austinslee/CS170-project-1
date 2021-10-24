#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <algorithm>
#include <iostream>
#include <stdlib.h>

class Game {
	public:
		std::vector<char> board;
		bool goal = false;
		std::vector<char> goal_state = {'A', 'N', 'G', 'E', 'L', 'I', 'C', 'A', '0'};

		//movement operators
		void move_up();
		void move_left();
		void move_right();
		void move_down();
	
		//constructors
		Game();
//		Game(char one, char two, char three, char four, char five, char six, char seven, char eight, char nine);
//		Game(std::vector<char> state);
		
		//misc
		int get_blank();
		void draw_board();
};
		



#endif //GAME_HPP
