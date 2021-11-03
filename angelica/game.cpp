#include "game.hpp"




//constructors
Game::Game() {
	board = { 'A', 'C', 'I', 'L', 'E', 'G', 'N', 'A', '0' };
	goal_state = { 'A', 'N', 'G', 'E', 'L', 'I', 'C', 'A', '0' };
}



//misc
int Game::get_blank() {
	int position;
	for(int i = 0; i < 10; ++i) {
		if(board[i] == '0') {
			position = i;
		}
	}
	return position;
}

void Game::draw_board() {
	for(int i = 0; i < 10; ++i) {
//		if(board[i] != '0') {
			std::cout << board[i] << " ";
//		}
		if(i == 2 || i == 5 || i == 8) {
			std::cout << "\n";
		}
	}
}

/*bool Game::is_goal() {
	if(board == goal_state) {
		return true;
	}
	return false;
}*/



//movement operators
void Game::move_up() {
	int pos = get_blank();

	if(pos <= 2) { return; }
	board[pos] = board[pos-3];
	board[pos-3] = '0';
}

void Game::move_down() {
	int pos = get_blank();

	if(pos >= 6) { return; }
        board[pos] = board[pos+3];
        board[pos+3] = '0';
}

void Game::move_left() {
	int pos = get_blank();

	if(pos == 0 || pos == 3 || pos == 6) { return; }
        board[pos] = board[pos-1];
        board[pos-1] = '0';
}

void Game::move_right() {
	int pos = get_blank();
	
	if(pos == 2 || pos == 5 || pos == 8) { return; }
	board[pos] = board[pos+1];
	board[pos+1] = '0';
}


