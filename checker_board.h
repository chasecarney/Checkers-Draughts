// file: checker_board.h
// purpose: header for checker board, utilizies square.h and performs many game operations

// Project: Checkers, C++
// Date: 2016 (University of Kentucky, Freshman)
// Author: Chase Carney
// Goal/Description: Implement classic board game Checkers in C++
// 					minimum: player vs player functionality, single jumps
//					extra: implement AI, multiple strategies

#ifndef CHECKER_BOARD_H
#define CHECKER_BOARD_H

#include <iostream>
#include <map>

class CheckerBoard
{
	public:
		struct Square {
			int x, y, value;
			// x = col, y = row on board

			// value cases
			// 0 = blank
			// 1 = o (standard), 2 = O (upgraded)
			// -1 = x (standard), -2 = X (upgraded)
		};

		CheckerBoard();
		// default constructor
		// initializes checker board to standard starting status
		// initializes y_map and piece_map for conversion between char and int

		Square find_square(char row, int col);
		// finds square given row and col as presented in visualizations

		bool check_piece(Square piece, bool turn);
		// checks square's value for correct piece

		bool move_piece(Square start, Square end);
		// given starting square and ending square
		// determines status of each square and what move is attempting to be made
		// performs checks to ensure move is valid and completes the move

		void display();
		// prints current status of board to standard output

		int get_o_count() const;
		// returns value of o_count

		int get_x_count() const;
		// returns value of x_count

	private:
		char y_axis[8] = {'A','B','C','D','E','F','G','H'};
		std::map<char, int> y_map; // convert between axis and int for index
		std::map<int, char> piece_map; // convert between piece value and representation
	     int x_axis[8] = {1,2,3,4,5,6,7,8};
	     Square board[8][8];

		int o_count, x_count = 12;
};

#endif /* CHECKER_BOARD_H */