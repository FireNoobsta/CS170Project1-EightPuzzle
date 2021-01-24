#include<iostream>
#include "eightpuzzle.h"

using namespace std;

int main() {
	Eightpuzzle puzzle;
	puzzle.move_up();
	int input = 0;
	while (input != 5) {
		puzzle.print_board();
		if (puzzle.isSolved()) {
			cout << "Congratulations! The puzzle is solved!" << endl;
			return 0;
		}
		cout << "Choose a move. (0 represents a blank space)" << endl;
		cout << "1. Move blank up" << endl;
		cout << "2. Move blank right" << endl;
		cout << "3. Move blank down" << endl;
		cout << "4. Move blank left" << endl;
		cout << "5. Quit" << endl;
		cin >> input;
		switch (input) {
			case 1:
			puzzle.move_up();
			break;
			
			case 2:
			puzzle.move_right();
			break;
			
			case 3:
			puzzle.move_down();
			break;
			
			case 4:
			puzzle.move_left();
			break;
			
			default:
			break;
		}
	}
	return 0;
}