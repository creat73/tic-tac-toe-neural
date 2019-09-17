#include "Board.hpp"

#include <iostream>

using namespace std;

//Returns true if player with specified id (int player) won, false otherwise
bool Board::is_win(int player)
{
    for(int i=0; i<3;i++)
    {
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player)
        {
            return true;
        }
        if(board[0][i] == player && board[1][i] == player && board[2][i] == player )
        {
            return true;
        }
    }
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player)
    {
        return true;
    }
    if(board[0][2] == player && board[1][1] == player && board [2][0] == player)
    {
        return true;
    }
    return false;
}

//Checks for draw
bool Board::is_draw()
{
	for(int y=0;y<3;y++)
	{
		for(int x=0;x<3;x++)
		{
			if(board[y][x] == 0)
			{
				return false;
			}
		}
	}
	return true;
}

//-1 - none 0 - draw 1- O won 2- X won
int Board::check_board()
{
	if(is_win(1))
	{
		return 1;
	}
	else if (is_win(2))
	{
		return 2;
	}
	else if (is_draw())
	{
		return 0;
	}
	return -1;
}

void Board::clear_board()
{
	for(int y=0;y<3;y++)
	{
		for(int x=0;x<3;x++)
		{
			board[y][x] = 0;
		}
	}
}

array<array<int,3>,3> Board::get_board() 
{
	return this->board;
}

void Board::print_board()
{
	for(int y=0;y<3;y++)
	{
		for(int x=0;x<3;x++)
		{
			if(this->board[y][x] == 0)
			{
				cout<< "[ ]";
			}
			else if(this->board[y][x] == 1)
			{
				cout<< "[O]";
			}
			else if(this->board[y][x] == 2)
			{
				cout<< "[X]";
			}
		}
		cout<<"\n";
	}
}

bool Board::put_sign(int y, int x, int player)
{
	if(board[y][x] == 0)
	{
		board[y][x] = player;
		return true;
	}
	return false;
}
