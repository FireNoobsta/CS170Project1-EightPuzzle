#include<iostream>
#include<cstdlib>
#include<ctime>
#include "eightpuzzle.h"
#include "searches.h"

using namespace std;

int main() {
	Eightpuzzle puzzle;
	srand(time(0));
	for (int i = 0; i < 50; ++i) {
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
	cout << "Initial puzzle state." << endl;
	puzzle.print_board();
	cout << "Attempting to solve puzzle with uniform cost algorithm" << endl;
	if (puzzle_search(puzzle, 0)) {
		cout << "Found solution!" << endl;
	}
	else {
		cout << "Something went horribly wrong" << endl;
	}
	
	return 0;
}