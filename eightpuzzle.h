#ifndef EIGHTPUZZLE_H
#define EIGHTPUZZLE_H
#include "puzzle.h"
#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

class Eightpuzzle : public Puzzle {
	public:
		vector<int> board; //board is stored in vector, first 3 entries is first row, and next 3 is 2nd row, and last 3 are 3rd row
		int blank; //position of blank space in vector
		int key; //another representation of the board for easily detecting repeated states
		/*
		if the board looks like
		1 2 3 
		4 5 6 
		7 8 0
		The key would be the single integer 123456780
		*/
	public:
		//update the key of the puzzle, to be done every time the board changes
		void update_key() {
			int newKey = 0;
			for (int i = 0; i < 9; ++i) {
				newKey += (board.at(i)*(pow(10, 8-i)));
			}
			key = newKey;
		}
		
		//default constructor creates a solved puzzle state
		Eightpuzzle() {
			for (int i = 1; i < 9; ++i) {
				board.push_back(i);
			}
			board.push_back(0);
			blank = 8;
			key = 123456780;
		};
		
		//all four operators return true if a valid move was made and false if it is an illegal move
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
		
		//checks if puzzle is currently in solved state
		bool isSolved() {
			for (int i = 0; i < 8; ++i) {
				if (board.at(i) != (i + 1)) {
					return false;
				}
			}
			return (board.at(8) == 0);
		};
		
		//prints out the board
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