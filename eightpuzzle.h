#ifndef EIGHTPUZZLE_H
#define EIGHTPUZZLE_H
#include "puzzle.h"
#include<iostream>
#include<vector>

using namespace std;

class Eightpuzzle : public Puzzle {
	private:
		vector<int> board;
		int blank; //position of blank space in vector
	public:
		Eightpuzzle() {
			for (int i = 1; i < 9; ++i) {
				board.push_back(i);
			}
			board.push_back(0);
			blank = 8;
		};
		
		void move_up() {
			if (blank >= 0 && blank <=2) {
				cout << "Error: illegal move" << endl;
				return;	
			}
			board.at(blank) = board.at(blank - 3);
			board.at(blank - 3) = 0;
			blank = blank - 3;
		};
		
		void move_down() {
			if (blank >= 6 && blank <= 8) {
				cout << "Error: illegal move" << endl;
				return;
			}
			board.at(blank) = board.at(blank + 3);
			board.at(blank + 3) = 0;
			blank = blank + 3; 
		};
		
		void move_left() {
			if ((blank % 3) == 0) {
				cout << "Error: illegal move" << endl;
				return;
			}
			board.at(blank) = board.at(blank - 1);
			board.at(blank - 1) = 0;
			blank = blank - 1;
		};
		
		void move_right() {
			if ((blank % 3) == 2) {
				cout << "Error: illegal move" << endl;
				return;
			}
			board.at(blank) = board.at(blank + 1);
			board.at(blank + 1) = 0;
			blank = blank + 1;
		};
		
		bool isSolved() {
			vector<int> goal;
			for (int i = 1; i < 9; ++i) {
				goal.push_back(i);
			}
			goal.push_back(0);
			
			return (board == goal);
		};
		
		void print_board() {
			for (int i = 0; i < 9; ++i) {
				cout << board.at(i) << " ";
				if ((i % 3) == 2) {
					cout << endl;
				}
			}
		};
};
#endif