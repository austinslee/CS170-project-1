#include "a.hpp"


int Node::mis_cost() {
	int ret = 0;
	for(int i = 0; i < 10; ++i) {
		if(game.board[i] != game.goal_state[i]) {
			if(game.board[i] != '0') {
				++ret;
			}
		}
	}
	return ret;	
}



