#ifndef __MAIN_CPP__
#define __MAIN_CPP__

#include <iostream>
#include <stdio.h>
#include <chrono>

#include "game.hpp"
#include "a.hpp"

class MyCompare {
	public:
	bool operator()(Node *a, Node *b) {
		return a->tot_cost > b->tot_cost;
	}
};

Node* uniform_cost_search (Node* initial) {
	std::priority_queue<Node*, std::vector<Node*>, MyCompare> que;
	std::vector<Node*> explored; //to avoid duplicates so no infinite loop
	que.push(initial);
	int nodes_explored = 0;
	Node* test;
	Node* temp;

	int which = 0;

	int miscost = initial->mis_cost();
	initial->tot_cost = initial->g_cost + initial->mis_cost();
	while(1) {
		++nodes_explored;
		if(que.empty()) {
			std::cout << "\n you fucked up, que empty \n";
			return NULL;
		}

		starty:

		test = que.top();
		que.pop();
		for(int i = 0; i < explored.size(); ++i) {
			if(test->game.board == explored.at(i)->game.board) {
				goto starty;
			}
		}
		//test->game.draw_board();
		explored.push_back(test);
		//std::cout << "\n" << test->tot_cost << "\n";

		if(test->game.board == test->game.goal_state) {
		
			std::cout << "\n Solved \n";
			std::cout << "g_cost = " << test->g_cost;
			std::cout << "\n Route taken: \n:";
			temp = test;
			while(temp->parent != NULL) {
				temp->game.draw_board();
				temp = temp->parent;
			}
				
			return test;
		}
		
		temp = new Node(test->game);
		if(temp->game.get_blank() != 0 && temp->game.get_blank() != 1 && temp->game.get_blank() != 2) {
			temp->game.move_up();
			temp->parent = test;
			if(temp->parent != NULL) {
				temp->g_cost = temp->parent->g_cost + 1;
			}
			temp->tot_cost = temp->g_cost + temp->mis_cost();
			que.push(temp);
		}
		
                temp = new Node(test->game);
		if(temp->game.get_blank() != 0 && temp->game.get_blank() != 3 && temp->game.get_blank() != 6) {
			temp->game.move_left();
			temp->parent = test;
			if(temp->parent != NULL) {
				temp->g_cost = temp->parent->g_cost + 1;
			}
			temp->tot_cost = temp->g_cost + temp->mis_cost();
			que.push(temp);
		}
		
                temp = new Node(test->game);
		if(temp->game.get_blank() != 6 && temp->game.get_blank() != 7 && temp->game.get_blank() != 8) {
			temp->game.move_down();
			temp->parent = test;
			if(temp->parent != NULL) {
				temp->g_cost = temp->parent->g_cost + 1;
			}
			temp->tot_cost = temp->g_cost + temp->mis_cost();
			que.push(temp);
                }
		
		temp = new Node(test->game);
                if(temp->game.get_blank() != 2 && temp->game.get_blank() != 5 && temp->game.get_blank() != 8) {  
			temp->game.move_right();
			temp->parent = test;
			if(temp->parent != NULL) {
				temp->g_cost = temp->parent->g_cost + 1;
			}
			temp->tot_cost = temp->g_cost + temp->mis_cost();
			que.push(temp);
		}
		/*if(dept == 50) {
			while(!que.empty()) {
				temp = que.top();
				que.pop();
				std::cout << "\n " << temp->mis_cost() << "\n";
			}
			return NULL;
		}*/

	}
}

/*Search is not working currently because it is just hill climbing right now and is getting stuck. Need to 
implement the uniform cost thing into it.*/


int main() {
	Game test;
	Astar algo;
	Node* start = new Node(test);
	Node* one = new Node(test);
	one->game.move_up();
	one->game.move_up();


	Node* two = new Node(test);
	two->game.move_left();
	two->game.move_up();
	two->game.move_up();
	two->game.move_left();
	
	

	uniform_cost_search(start);
	
	Node* temp;
	std::priority_queue<Node*, std::vector<Node*>, MyCompare> que;
	que.push(start);
	que.push(one);
	que.push(two);
/*	while(!que.empty()) {
		temp = que.top();
		std::cout << "\n" << temp->mis_cost() << "\n";
		que.pop();
	}*/
		
	Node* temp123;
	/*while(1) {
		if(test.board == test.goal_state) {
			std::cout << "\n Solved \n";
			break;
		}
		char input;
		test.draw_board();


        std::cout << "\n goal state \n";
        for(int i = 0; i < 10; ++i) {
			std::cout << test.goal_state[i] << " ";
		if(i == 2 || i == 5 || i == 8) {
			std::cout << "\n";
		}
	}
	std::cout << "\n";


		std::cin >> input;
		if(input == 'w') {
			test.move_up();
		}
		else if(input == 'a') { test.move_left(); }
		else if(input == 's') { test.move_down(); }
		else if(input == 'd') { test.move_right(); }
		

		//outputting misplaced cost
		temp123 = new Node(test);
		std::cout << "\n mis: " << temp123->mis_cost() << "\n";
	}*/
}

#endif //__MAIN_CPP__
