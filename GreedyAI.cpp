#include "GreedyAI.hpp"

/*
 * Greedy algorithm
 * Checks every possible move for given board, then chooses the place with most wins.
 * NOTE: It takes a long time for this algorithm to make a starting move. Therefore it shouldn't be playing on an empty
 * board (starting a round) and its not advised to use it for training neural AI as it is very time consuming.
 */

void GreedyAI::summarise_round(int win)
{
	return;
}
		
int GreedyAI::get_next_tile(int tile)
{
	if(tile==1)
	{
		return 2;
	}
	else
	{
		return 1;
	}
}

array<int,2> GreedyAI::greedy(Board board)
{
	array<array<int,3>,3> bias_table;
	array<int,2> move_yx= {-1,-1};
	int next_tile = get_next_tile(tile);
	int max_bias;
	int sum = 0;
	
	for(int y = 0;y<3;y++)
	{
		for(int x =0;x<3;x++)
		{
			if(board.get_board()[y][x]==0)
			{
				Board board_copy = board;
				board_copy.put_sign(y,x,tile);
				bias_table[y][x] = minmax_r(board_copy, next_tile);
				sum+=bias_table[y][x];
			}
		}
	}
	
	for(int y = 0;y<3;y++)
	{
		for(int x =0;x<3;x++)
		{
			if(board.get_board()[y][x] == 0 && move_yx[0] == -1)
			{
				max_bias = bias_table[y][x];
				move_yx[0] = y;
				move_yx[1] = x;
			}
			else if(bias_table[y][x] > max_bias && board.get_board()[y][x] == 0)
			{
				max_bias = bias_table[y][x];
				move_yx[0] = y;
				move_yx[1] = x;
			}
			}
	}
	return move_yx;	
}

int GreedyAI::greedy_r(Board board, int tile)
{
	int next_tile = get_next_tile(tile);
	Board board_copy;
	int sum = 0;
	int win = board.check_board();
	
	if ( win == this->tile)
	{
		return 1;
	}
	else if(win == get_next_tile(this->tile))
	{
		return -1;	
	}
	else if(win == 0)
	{
		return 0;
	}
	
	for(int y=0; y<3;y++)
	{
		for(int x=0;x<3;x++)
		{
			if(board.get_board()[y][x] == 0)
			{
				board_copy = board;
				board_copy.put_sign(y,x,tile);
				sum += minmax_r(board_copy,next_tile);
			}
		}
	}
	return sum;
}
	
void GreedyAI::make_move(Board &board)
{
	array<int,2> yx= minmax(board);
	board.put_sign(yx[0],yx[1],tile);
}
