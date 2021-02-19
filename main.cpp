#include<iostream>
#include<cstdlib>
#include<ctime>
#include "eightpuzzle.h"
#include "searches.h"

using namespace std;

int main() {
	Eightpuzzle puzzle;
	int input = 0;
	srand(time(0));
	for (int i = 0; i < 500; ++i) {
		switch (rand() % 4) {
			case 0:
				puzzle.move_up();
				break;
			case 1:
				puzzle.move_down();
				break;
			case 2:
				puzzle.move_left();
				break;
			case 3:
				puzzle.move_right();
				break;
		}
	}
	while (input != 4) {
		cout << "Initial puzzle state." << endl;
		puzzle.print_board();
		cout << "1. Solve with Uniform Cost Search" << endl;
		cout << "2. Solve with A* using misplaced tile heuristic" << endl;
		cout << "3. Solve with A* using manhattan distance heuristic" << endl;
		cout << "4. Quit" << endl;
		cin >> input;
		switch (input) {
			case 1:
			cout << "Attempting to solve puzzle with Uniform Cost Search" << endl;
			if (puzzle_search(puzzle, UNIFORM_COST)) {
				cout << "Found Solution!" << endl;
			}
			else {
				cout << "No Solution" << endl;
			}
			break;
			
			case 2:
			cout << "Attempting to solve puzzle with A* algorithm using misplaced tile heuristic" << endl;
			if (puzzle_search(puzzle, MISPLACED_TILE)) {
				cout << "Found Solution!" << endl;
			}
			else {
				cout << "No Solution" << endl;
			}
			break;
			
			case 3:
			cout << "Attempting to solve puzzle with A* algorithm using manhattan distance heuristic" << endl;
			if (puzzle_search(puzzle, MANHATTAN_DISTANCE)) {
				cout << "Found Solution!" << endl;
			}
			else {
				cout << "No Solution" << endl;
			}
			break;
			
			default:
			break;
		}
	}
	
	return 0;
}