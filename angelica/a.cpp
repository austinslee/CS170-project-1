#include "a.hpp"


int Node::mis_cost() {
	int ret = 0;
	for(int i = 0; i < game.board.size(); ++i) {
		if(game.board[i] != game.goal_state[i]) {
			if(game.board[i] != '0') {
				++ret;
			}
		}
	}
	return ret;	
}

int Node::man_cost() {
	//I made my board a 1d array so pain for me.

	int ret = 0;
	int currX = 0;
	int currY = 0;
	int goalX = 0;
	int goalY = 0;
	int temp = 0;


	int firstA = -1;
	int secondA = -1;
	int firstsum = -1;
	int secondsum = -1;
	int firstTemp = -1;
	int secondTemp = -1;

	bool ftime = true;


	for(int i = 0; i < game.board.size(); ++i) {
		if(game.board[i] == '0') {
			goto skip;
		}
		currX = i% 3; 
		currY = i/3;
		
		if(game.board[i] != 'A') {
			for(int j = 0; j < game.board.size(); ++j) {
				if(game.goal_state[j] == game.board[i]) {
					goalX = j%3;
					goalY = j/3;
				}
			}
			ret += abs(currX - goalX) + abs(currY - goalY);


		}

/*		if(game.board[i] == 'A') {
			if(i == 0 || i == 1 || i == 2 || i == 3) {
				ret += abs(currX) + abs(currY);
			} else {
				ret += abs(currX)
*/
			


		//How would I do manhattan distance for A? When there are two different A's
		//My idea would be to calculate the distance for both ways for A's, take the sum and choose the lower sum.
		//gonna be a pain to implement zzzzz and idk if it would be accepted? cuz it's a slightly tweaked algo




		if(game.board[i] == 'A' && ftime == true) {
			ftime = false;
			firstA = i;
			for(int q = 0; q < game.board.size(); ++q) {
				if(game.board[q] == 'A' && q != firstA) {
					secondA = q;
					std::cout << "a " << secondA << std::endl;
				}
			}


			currX = firstA%3;
			currY = firstA/3;

			firstTemp = abs(currX) + abs(currY);
			
			currX = secondA%3;
			currY = secondA/3;

			secondTemp = abs(currX - 1) + abs(currY - 2);

			firstsum = firstTemp + secondTemp;

			currX = secondA%3;
			currY = secondA/3;
			firstTemp = abs(currX) + abs(currY);
			currX = firstA%3;
			currY = firstA/3;
			secondTemp = abs(currX - 1) + abs(currY - 2);

			secondsum = firstTemp + secondTemp;


			if(firstsum > secondsum) {
				std::cout << "\n second sum: " << secondsum << std::endl;
				ret += secondsum;
			} else {
				std::cout << "\n first sum: " << firstsum << std::endl;
				ret += firstsum;
			}	
		}
		


		skip:
		ret += 0;
	}
	return ret;
}
			
		
