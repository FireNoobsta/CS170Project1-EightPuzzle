#ifndef NODE_H
#define NODE_H
#include "eightpuzzle.h"
class Node {
	public:
		Eightpuzzle puzzle;
		vector<Node*> children;
		Node* parent;
	
	public:
		Node() {
			parent = 0;
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
				children.push_back(n1);
			}
			
			if (p2.move_down()) {
				Node* n2 = new Node;
				n2->puzzle = p2;
				n2->parent = this;
				children.push_back(n2);
			}
			
			if (p3.move_left()) {
				Node* n3 = new Node;
				n3->puzzle = p3;
				n3->parent = this;
				children.push_back(n3);
			}
			
			if (p4.move_right()) {
				Node* n4 = new Node;
				n4->puzzle = p4;
				n4->parent = this;
				children.push_back(n4);
			}
		}
};
#endif