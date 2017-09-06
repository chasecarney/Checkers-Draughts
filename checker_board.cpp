// file: checker_board.h
// purpose: header for checker board, utilizies square.h and performs many game operations

// Project: Checkers, C++
// Date: 2016 (University of Kentucky, Freshman)
// Author: Chase Carney
// Goal/Description: Implement classic board game Checkers in C++
// 					minimum: player vs player functionality, single jumps
//					extra: implement AI, multiple strategies

#include <iostream>
#include <map>
#include "checker_board.h"

using namespace std;

	CheckerBoard::CheckerBoard()
	// default constructor
	// initializes checker board to standard starting status
	{
		for(int i = 0; i < 8; i++)
		// iterate rows
		{
			for(int j = 0; j < 8; j++)
			// iterate cols
			{
				//create Square with corresponding default value
				Square temp;
				temp.y = i;
				temp.x = j;

				if( (i == 0 || i == 2) && j%2 == 0)	// o
					temp.value = 1;
				else if( i == 1 && j%2 == 1)
					temp.value = 1;

				else if( (i == 7 || i == 5) && j%2 == 1)	// x
					temp.value = -1;
				else if( i == 6 && j%2 == 0)
					temp.value = -1;

				else								// blank
					temp.value = 0;

				board[i][j] = temp;
			}
		}

		for(int i = 0; i < 8; i++)
		{
			y_map[y_axis[i]] = i;
		}

		piece_map[-2] = 'X';
		piece_map[-1] = 'x';
		piece_map[0] = '_';
		piece_map[1] = 'o';
		piece_map[2] = 'O';
	}

	CheckerBoard::Square CheckerBoard::find_square(char row, int col)
	// finds square given row and col as presented in visualizations
	{
		int x = col-1;
		int y = y_map[row];

		return board[y][x];
	}

	bool CheckerBoard::check_piece(Square piece, bool turn)
	// check square's value for correct piece
	{
		if(turn)
			return (piece.value == 1 || piece.value == 2);
		else
			return (piece.value == -1 || piece.value == -2);
	}

	bool CheckerBoard::move_piece(Square start, Square end)
	// given starting square and ending square
	// determines status of each square and what move is attempting to be made
	// performs checks to ensure move is valid and completes the move
	{
		if(end.value != 0)
		// end square is not blank
			return false;

		if((start.x + start.y) % 2 != (end.x + end.y) % 2)
		// start and end are not in the same diagonal set of squares
	         return false;

		if( !(end.x >= 0 && end.x < 8 && end.y >= 0 && end.y < 8 && start.x >= 0 && start.x < 8 && start.y >= 0 && start.y < 8) )
		// start and end squares are not in bounds
			return false;

	     switch(start.value)
	     {
	          case 1:
	          // o piece
	          	if(end.y > start.y)
				// end square is below start square
	               {
	                    board[start.y][start.x].value = 0; // start becomes blank

					if(abs(end.y - start.y) == 2 && abs(end.x - start.x) == 2)
					// desired move is a jump
						board[(start.y + end.y) / 2][(start.x + end.x) / 2].value = 0; // jumped piece becomes blank

	                    board[end.y][end.x].value = 1; // end becomes piece

	                    if(end.y == 7)
					// piece is promoted
	                    	board[end.y][end.x].value = 2;

	                    return true;
	               }

	               else // end square is not below start square
	                    return false;

	          case 2:
	          // O piece
	               board[start.y][start.x].value = 0; // start becomes blank

				if(abs(end.y - start.y) == 2 && abs(end.x - start.x) == 2)
				// desired move is a jump
					board[(start.y + end.y) / 2][(start.x + end.x) / 2].value = 0; // jumped piece becomes blank

                    board[end.y][end.x].value = 2; // end becomes piece

                    return true;

             	case -1:
               // x piece
				if(end.y < start.y)
				// end square is above start square
				{
					board[start.y][start.x].value = 0; // start becomes blank

					if(abs(end.y - start.y) == 2 && abs(end.x - start.x) == 2)
					// desired move is a jump
						board[(start.y + end.y) / 2][(start.x + end.x) / 2].value = 0; // jumped piece becomes blank

					board[end.y][end.x].value = -1; // end becomes piece

					if(end.y == 0)
					// piece is promoted
						board[end.y][end.x].value = -2;

					return true;
				}

				else // end square is not above start square
					return false;

             	case -2:
               // X piece
				board[start.y][start.x].value = 0; // start becomes blank

				if(abs(end.y - start.y) == 2 && abs(end.x - start.x) == 2)
				// desired move is a jump
					board[(start.y + end.y) / 2][(start.x + end.x) / 2].value = 0; // jumped piece becomes blank

				board[end.y][end.x].value = -2; // end becomes piece

				return true;
		}

	    return false;
	}

	void CheckerBoard::display()
	// prints current status of board to standard output
	{
		for(int i = 0; i < 8; i++)
	     {
	          cout << y_axis[i] << " |";
	          for(int j = 0; j < 8; j++)
	          {
	          	//cout << piece_map[find_square(i,j).value] << '|';
				cout << piece_map[board[i][j].value] << '|';
	     	}
	          cout << '\n';
	     }

	     cout << "   ";

	     for(int i = 0; i < 8; i++)
		{
	     	cout << x_axis[i] << ' ';
		}

		cout << '\n';
	}

	int CheckerBoard::get_o_count() const
	// returns value of o_count
	{
		return o_count;
	}

	int CheckerBoard::get_x_count() const
	// returns value of x_count
	{
		return x_count;
	}