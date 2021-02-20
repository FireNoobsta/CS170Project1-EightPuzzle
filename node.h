#ifndef NODE_H
#define NODE_H
#include "eightpuzzle.h"
#include "heuristic.h"

//Nodes used for the tree
class Node {
	public:
		Eightpuzzle puzzle; //state stored in puzzle
		vector<Node*> children; //children of this node
		Node* parent; //parent of this node
		int depth; //depth in tree, since each move has the same cost this is essentially G(n)
		int totalCost; //Sum of cost and chosen heuristic. F(n) = G(n) + H(n)
	
	public:
		//default constructor makes a root node by setting parent node pointer to 0
		Node() {
			parent = 0;
			depth = 0;
			totalCost = 0;
		}
		
		//expand node by attempting every possible move
		void expand() {
			if (children.size() > 0) {
				//node is already expanded if children is non-empty
				return;
			}
			
			Eightpuzzle p1, p2, p3, p4;
			p1 = puzzle;
			p2 = puzzle;
			p3 = puzzle;
			p4 = puzzle;
			
			//if a move is legal, make a new node and populate it accordingly
			if (p1.move_up()) {
				Node* n1 = new Node;
				n1->puzzle = p1;
				n1->parent = this;
				n1->depth = depth + 1;
				children.push_back(n1);
			}
			
			if (p2.move_down()) {
				Node* n2 = new Node;
				n2->puzzle = p2;
				n2->parent = this;
				n2->depth = depth + 1;
				children.push_back(n2);
			}
			
			if (p3.move_left()) {
				Node* n3 = new Node;
				n3->puzzle = p3;
				n3->parent = this;
				n3->depth = depth + 1;
				children.push_back(n3);
			}
			
			if (p4.move_right()) {
				Node* n4 = new Node;
				n4->puzzle = p4;
				n4->parent = this;
				n4->depth = depth + 1;
				children.push_back(n4);
			}
		}
		
		//update the total cost of a node, depending on the chosen heuristic
		void update_totalCost(Heuristic heur) {
			if (parent == 0) { //Root node, cost is zero
				totalCost = 0;
				return;
			}
			int h = 0; //H(n)
			int index = 0; //used for calculating manhattan distance
			switch (heur) {
				case UNIFORM_COST:
				totalCost = depth; //H(n) is 0, F(n) = G(n) + 0, F(n) = depth of node
				break;
				
				case MISPLACED_TILE:
				for (unsigned int i = 0; i < puzzle.board.size() - 1; ++i) {
					if (puzzle.board.at(i) == (i + 1)) {
						continue;
					}
					++h;
				}
				totalCost = depth + h; //H(n) is number of misplaced tiles
				break;
				
				case MANHATTAN_DISTANCE:
				for (int i = 0; i < puzzle.board.size() - 1; ++i) {
					if (puzzle.board.at(i) == (i + 1)) {
						continue;
					}
					
					//find the index of the tile you expected to be at ith position
					for (unsigned int j = 0; j < puzzle.board.size(); ++j) {
						if (puzzle.board.at(j) == (i + 1)) {
							index = j;
							break;
						}
					}
					
					//add the horizontal distance and vertical distance to the proper spot
					h += abs((i % 3) - (index % 3));
					h += abs((i / 3) - (index / 3));
				}
				totalCost = depth + h; //H(n) is sum total of the manhattan distances of each tile to its proper spot
				break;
				
				default:
				break;
			}
		}
};
#endif