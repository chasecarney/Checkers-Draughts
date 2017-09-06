// Project: Checkers, C++
// Date: 2016 (University of Kentucky, Freshman)
// Author: Chase Carney
// Goal/Description: Implement classic board game Checkers in C++
// 									 minimum: player vs player functionality, single jumps
//									 extra: implement AI, multiple strategies

#include <iostream>
#include "checker_board.h"

using namespace std;

void player_vs_player();

CheckerBoard* checkerboard = new CheckerBoard();

bool turn = true, win = false;
// when turn = true, player 1 turn
//		   = false, player 2 turn
char row; // selected row
int col; // selected col

int main()
{
	player_vs_player();

	return 0;
}

void player_vs_player()
{
	while(!win)
	// iterate until a player wins
	{
		if(turn)
		{
			checkerboard->display();

			cout << "Player 1's turn\nBegin by choosing a piece (ex. A1)\n";
			cin >> row >> col;

			CheckerBoard::Square start = checkerboard->find_square(row,col);

			if(checkerboard->check_piece(start,turn))
			{
				cout << "Choose your move or type 'u' to undo piece selection\n";
				cin >> row;
				if(row == 'u')
					continue;

				cin >> col;

				CheckerBoard::Square end = checkerboard->find_square(row,col);

				if(checkerboard->move_piece(start, end))
					turn = false;

				else
				{
					cout << "Invalid move selection, please try again\n\n";
					continue;
				}
			}

			else
			{
				cout << "Invalid piece selection, please try again\n\n";
				continue;
			}

			if(checkerboard->get_x_count() == 0)
			{
				cout << "\nCongratulations! Player 1 wins.\n";
				win = true;
			}
		}
		else
		{
			checkerboard->display();

			cout << "Player 2's turn\nBegin by choosing a piece (ex. A1)\n";
			cin >> row >> col;

			CheckerBoard::Square start = checkerboard->find_square(row,col);

			if(checkerboard->check_piece(start,turn))
			{
				cout << "Choose your move or type 'u' to undo piece selection\n";
				cin >> row;
				if(row == 'u')
					continue;

				cin >> col;

				CheckerBoard::Square end = checkerboard->find_square(row,col);

				if(checkerboard->move_piece(start, end))
					turn = true;

				else
				{
					cout << "Invalid move selection, please try again\n\n";
					continue;
				}
			}

			else
			{
				cout << "Invalid piece selection, please try again\n\n";
				continue;
			}

			if(checkerboard->get_o_count() == 0)
			{
				cout << "\nCongratulations! Player 2 wins.\n";
				win = true;
			}
		}
	}
}