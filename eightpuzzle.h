#ifndef EIGHTPUZZLE_H
#define EIGHTPUZZLE_H
#include "puzzle.h"
#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

class Eightpuzzle : public Puzzle {
	public:
		vector<int> board;
		int blank; //position of blank space in vector
	
	public:
		int key;
		void update_key() {
			int newKey = 0;
			for (int i = 0; i < 9; ++i) {
				newKey += (board.at(i)*(pow(10, 8-i)));
			}
			key = newKey;
		}
	
	public:
		Eightpuzzle() {
			for (int i = 1; i < 9; ++i) {
				board.push_back(i);
			}
			board.push_back(0);
			blank = 8;
			key = 123456780;
		};
		
		bool move_up() {
			if (blank >= 0 && blank <=2) {
				//cout << "Error: illegal move" << endl;
				return false;	
			}
			board.at(blank) = board.at(blank - 3);
			board.at(blank - 3) = 0;
			blank = blank - 3;
			update_key();
			return true;
		};
		
		bool move_down() {
			if (blank >= 6 && blank <= 8) {
				//cout << "Error: illegal move" << endl;
				return false;
			}
			board.at(blank) = board.at(blank + 3);
			board.at(blank + 3) = 0;
			blank = blank + 3; 
			update_key();
			return true;
		};
		
		bool move_left() {
			if ((blank % 3) == 0) {
				//cout << "Error: illegal move" << endl;
				return false;
			}
			board.at(blank) = board.at(blank - 1);
			board.at(blank - 1) = 0;
			blank = blank - 1;
			update_key();
			return true;
		};
		
		bool move_right() {
			if ((blank % 3) == 2) {
				//cout << "Error: illegal move" << endl;
				return false;
			}
			board.at(blank) = board.at(blank + 1);
			board.at(blank + 1) = 0;
			blank = blank + 1;
			update_key();
			return true;
		};
		
		bool isSolved() {
			for (int i = 0; i < 8; ++i) {
				if (board.at(i) != (i + 1)) {
					return false;
				}
			}
			return (board.at(8) == 0);
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