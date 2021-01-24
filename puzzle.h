#ifndef PUZZLE_H
#define PUZZLE_H

class Puzzle {
	private:
	
	public:
		virtual void move_up() = 0;
		virtual void move_down() = 0;
		virtual void move_left() = 0;
		virtual void move_right() = 0;
		virtual bool isSolved() = 0;
};

#endif