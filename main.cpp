#include<iostream>
#include<cstdlib>
#include<ctime>
#include "eightpuzzle.h"
#include "searches.h"

using namespace std;

void get_puzzle_input(Eightpuzzle &puzzle) {
	vector<int> board;
	int input;
	cout << "Input your own puzzle one number at a time." << endl;
	cout << "(Puzzle will be shown as you input each number. Type \"0\" for a blank)" << endl;
	for (unsigned int i = 0; i < 9; ++i) {
		cout << "Type number for position " << i+1 << endl;
		cin >> input;
		board.push_back(input);
		for (unsigned int j = 0; j < board.size(); ++j) {
			cout << board.at(j) << " ";
			if ((j % 3) == 2) {
				cout << endl;
			}
			if (input == 0) {
				puzzle.blank = j;
			}
		}
		cout << endl;
	}
	puzzle.board = board;
	puzzle.update_key();
	cout << "Puzzle accepted! (Puzzle not guaranteed to have a solution)" << endl;
}

int main() {
	Eightpuzzle puzzle;
	int input = 0;
	srand(time(0));
	cout << "Welcome to my 8-puzzle solver!" << endl;
	cout << "Type \"1\" for a random puzzle. Type \"2\" to input your own puzzle." << endl;
	cin >> input;
	if (input == 1) {
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
	}
	else if (input == 2) {
		get_puzzle_input(puzzle);
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