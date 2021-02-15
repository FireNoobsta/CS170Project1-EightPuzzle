#include "eightpuzzle.h"
#include "node.h"
#include "searches.h"
#include<cstdlib>
#include<queue>
#include<list>
#include<unordered_set>

using namespace std;

void Queueing_Function (Node* node, queue<Node*> &nodes, unordered_set<int> &repeats, int queueFunc) {
	node->expand();
	//cout << "Expanding following state..." << endl;
	//node->puzzle.print_board();
	for (unsigned int i = 0; i < node->children.size(); ++i) {
		if (repeats.count(node->children.at(i)->puzzle.key) > 0) {
			
		}
		else {
			nodes.push(node->children.at(i));
			repeats.insert(node->children.at(i)->puzzle.key);
		}
	}
}

void trace_back_node (Node* node) {
	if (node == 0) {
		return;
	}
	node->puzzle.print_board();
	cout << endl;
	trace_back_node(node->parent);
}

bool puzzle_search(Eightpuzzle puzzle, int queueFunc) {
	queue<Node*> nodes;
	unordered_set<int> repeatedStates;
	Node* initialState = new Node;
	initialState->puzzle = puzzle;
	repeatedStates.insert(puzzle.key);
	nodes.push(initialState);
	while (1) {
		if (nodes.empty()) {
			return false; 
		}
		Node* n = nodes.front();
		nodes.pop();
		
		if (n->puzzle.isSolved()) {
			trace_back_node(n);
			return true;
		}
		
		Queueing_Function(n, nodes, repeatedStates, queueFunc);
	}
}