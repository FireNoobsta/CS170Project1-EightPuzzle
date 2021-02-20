#include "eightpuzzle.h"
#include "searches.h"
#include<cstdlib>
#include<queue>
#include<list>
#include<unordered_set>

using namespace std;

int largestQueueSize;
int nodesExpanded;

//given a node and a list of nodes, it inserts the node sorted by the node's total cost
//must update the node's cost before calling this function
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

//Expands given node and queues its children according to heuristic and set of repeated states
void Queueing_Function (Node* node, list<Node*> &nodes, unordered_set<int> &repeats, Heuristic heur) {
	node->expand();
	nodesExpanded++;
	/*
	Note: The following two lines are commented out because it floods output for hard puzzles.
	If you want to trace every node that is expanded uncomment the next two lines
	*/
	//cout << "Expanding following state. With g(n) = " << node->depth << " and H(n) = " << node->totalCost - node->depth << endl;
	//node->puzzle.print_board();
	for (unsigned int i = 0; i < node->children.size(); ++i) {
		if (repeats.count(node->children.at(i)->puzzle.key) > 0) {
			//Don't add repeated states to queue
		}
		else {
			node->children.at(i)->update_totalCost(heur); //update cost of node
			insert_node_sorted(node->children.at(i), nodes); //queue node
			repeats.insert(node->children.at(i)->puzzle.key); //insert state into set of repeated states
		}
	}
	
	//update largestQueueSize if the queue grew bigger
	if (nodes.size() > largestQueueSize) {
		largestQueueSize = nodes.size();
	}
}

//prints series of moves that lead to the state of node
void trace_back_node (Node* node) {
	if (node == 0) {
		return;
	}
	trace_back_node(node->parent);
	node->puzzle.print_board();
	cout << endl;
}

//Try to solve a given puzzle puzzle using the algorithm specified by heuristic
bool puzzle_search(Eightpuzzle puzzle, Heuristic heur) {
	//initialize global vars
	largestQueueSize = 1;
	nodesExpanded = 0;
	
	//create queue for nodes and set for tracking repeated states
	list<Node*> nodes;
	unordered_set<int> repeatedStates;
	
	//create node based on puzzle input and insert to queue and set
	Node* initialState = new Node;
	initialState->puzzle = puzzle;
	repeatedStates.insert(puzzle.key);
	nodes.push_back(initialState);
	
	//general search algorithm
	while (1) {
		if (nodes.empty()) {
			return false; 
		}
		Node* n = nodes.front();
		nodes.pop_front();
		
		if (n->puzzle.isSolved()) {
			cout << "Solution is ..." << endl;
			trace_back_node(n);
			cout << "Expanded " << nodesExpanded << " nodes." << endl;
			cout << "Largest size of queue was " << largestQueueSize << endl;
			cout << "Solution depth: " << n->depth << endl;
			return true;
		}
		
		Queueing_Function(n, nodes, repeatedStates, heur);
	}
}