#ifndef SEARCHES_H
#define SEARCHES_H
#include "eightpuzzle.h"
#include "node.h"
#include<queue>
#include<unordered_set>

void Queueing_Function (Node* node, queue<Node*> &nodes, unordered_set<int> &repeats, int queueFunc);
bool puzzle_search(Eightpuzzle puzzle, int queueFunc);
#endif
