#ifndef PUZZLE_H
#define PUZZLE_H

class Puzzle {
	private:
	
	public:
		virtual bool move_up() = 0;
		virtual bool move_down() = 0;
		virtual bool move_left() = 0;
		virtual bool move_right() = 0;
		virtual bool isSolved() = 0;
};

#endif