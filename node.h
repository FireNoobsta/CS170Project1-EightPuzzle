#ifndef NODE_H
#define NODE_H
#include "eightpuzzle.h"
#include "heuristic.h"

class Node {
	public:
		Eightpuzzle puzzle;
		vector<Node*> children;
		Node* parent;
		int depth;
		int totalCost; //Sum of cost and chosen heuristic. F(n) = G(n) + H(n)
	
	public:
		Node() {
			parent = 0;
			depth = 0;
			totalCost = 0;
		}
		
		void expand() {
			if (children.size() > 0) {
				return;
			}
			
			Eightpuzzle p1, p2, p3, p4;
			p1 = puzzle;
			p2 = puzzle;
			p3 = puzzle;
			p4 = puzzle;
			
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
		
		void update_totalCost(Heuristic heur) {
			if (parent == 0) { //Root node, cost is zero
				totalCost = 0;
				return;
			}
			int h = 0;
			int index = 0;
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
				totalCost = depth + h;
				break;
				
				case MANHATTAN_DISTANCE:
				for (int i = 0; i < puzzle.board.size() - 1; ++i) {
					if (puzzle.board.at(i) == (i + 1)) {
						continue;
					}
					
					for (unsigned int j = 0; j < puzzle.board.size(); ++j) {
						if (puzzle.board.at(j) == (i + 1)) {
							index = j;
							break;
						}
					}
					
					h += abs((i % 3) - (index % 3));
					h += abs((i / 3) - (index / 3));
				}
				totalCost = depth + h;
				break;
				
				default:
				break;
			}
		}
};
#endif