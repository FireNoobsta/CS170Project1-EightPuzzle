#include "eightpuzzle.h"
#include "searches.h"
#include<cstdlib>
#include<queue>
#include<list>
#include<unordered_set>

using namespace std;

int largestQueueSize;
int nodesExpanded;

bool insert_node_sorted(Node* node, list<Node*> &nodes) {
	int key = node->totalCost;
	
	if (nodes.empty() || (key >= nodes.back()->totalCost)) {
		nodes.push_back(node);
		return true;
	}
	
	list<Node*>::iterator iter;
	for (iter = nodes.begin(); iter != nodes.end(); ++iter) {
		if (key <= (*iter)->totalCost) {
			nodes.insert(iter, node);
			return true;
		}
	}
	return false;
}

void Queueing_Function (Node* node, list<Node*> &nodes, unordered_set<int> &repeats, Heuristic heur) {
	node->expand();
	nodesExpanded++;
	//cout << "Expanding following state. With h(n) = "<< node->totalCost - node->depth << endl;
	//node->puzzle.print_board();
	for (unsigned int i = 0; i < node->children.size(); ++i) {
		if (repeats.count(node->children.at(i)->puzzle.key) > 0) {
			//Don't add repeated states to queue
		}
		else {
			node->children.at(i)->update_totalCost(heur);
			insert_node_sorted(node->children.at(i), nodes);
			repeats.insert(node->children.at(i)->puzzle.key);
		}
	}
	
	if (nodes.size() > largestQueueSize) {
		largestQueueSize = nodes.size();
	}
}

void trace_back_node (Node* node) {
	if (node == 0) {
		return;
	}
	trace_back_node(node->parent);
	node->puzzle.print_board();
	cout << endl;
}

bool puzzle_search(Eightpuzzle puzzle, Heuristic huer) {
	largestQueueSize = 1;
	nodesExpanded = 0;
	list<Node*> nodes;
	unordered_set<int> repeatedStates;
	Node* initialState = new Node;
	initialState->puzzle = puzzle;
	repeatedStates.insert(puzzle.key);
	nodes.push_back(initialState);
	while (1) {
		if (nodes.empty()) {
			return false; 
		}
		Node* n = nodes.front();
		nodes.pop_front();
		
		if (n->puzzle.isSolved()) {
			trace_back_node(n);
			cout << "Expanded " << nodesExpanded << " nodes." << endl;
			cout << "Largest size of queue was " << largestQueueSize << endl;
			cout << "Solution depth: " << n->depth << endl;
			return true;
		}
		
		Queueing_Function(n, nodes, repeatedStates, huer);
	}
}