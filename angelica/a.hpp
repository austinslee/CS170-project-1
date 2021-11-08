#ifndef A_CPP
#define A_CPP

#include<iostream>
#include<stdio.h>
#include<stdlib.h> //for abs
#include<queue>
#include "game.hpp"

class Astar {
	public:
		//heuristics
//		int mis_cost(Game); //misplace tiles
//		int man_cost(Game); //manhattan distance
};

class Node {
        public:
                Node* parent = NULL;
                Game game;


		int tot_cost = 0;
		int g_cost = 0;

                Node(Game enter) {
                        game = enter;
                };
                int depth = 0;
                int mis_cost();
		int man_cost();

};


/*bool operator<(Node n1, Node n2) {
	return n1.mis_cost() < n2.mis_cost();
}*/


/*Node* uniform_cost_search (Node* initial) {
	std::priority_queue<Node*> que;
	que.push(initial);
	int dept = 0;
	Node* test;
	Node* temp;

	int which = 0;

	int miscost = initial->mis_cost();
	while(1) {
		
		if(que.empty()) {
			return NULL;
		}
		test = que.top();
		que.pop();
		++dept;
		if(test->game.board == test->game.goal_state) {
			test->depth = dept;
			return test;
		}
		
		temp = new Node(test->game);
		if(temp->game.get_blank() != 0 && temp->game.get_blank() != 1 && temp->game.get_blank() != 2) {
			temp->game.move_up();
			que.push(temp);
		}
		
                temp = new Node(test->game);
		if(temp->game.get_blank() != 0 && temp->game.get_blank() != 3 && temp->game.get_blank() != 6) {
			temp->game.move_left();
			que.push(temp);
		}
		
                temp = new Node(test->game);
		if(temp->game.get_blank() != 6 && temp->game.get_blank() != 7 && temp->game.get_blank() != 8) {
			temp->game.move_down();
			que.push(temp);
                }
		
		temp = new Node(test->game);
                if(temp->game.get_blank() != 2 && temp->game.get_blank() != 5 && temp->game.get_blank() != 8) {  
			temp->game.move_right();
			que.push(temp);
		}
		std::cout << "reached end \n";
	}
}*/
		
		
	


/*class Node {
	public:
		Node* parent;
		Game game;
		Node(Game enter) {
			game = enter;
		}:
		int depth = 0;	
		int mis_cost();
};*/


#endif //A_CPP
