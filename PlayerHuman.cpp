#include "PlayerHuman.hpp"
#include <iostream>

void PlayerHuman::summarise_round(int win)
{
	string player_string;
	
	if(this->tile == 1)
	{
		player_string = "O";
	}
	else
	{
		player_string = "X";
	}

	if(win==this->tile)
	{
		cout<< player_string << " won the game!";
	}
	else if(win == 0)
	{
		cout<< " Its a draw!";	
	}
	else
	{
		cout << "You lost :(";
	}
	
}

void PlayerHuman::make_move(Board &board)
{
		bool correct_move = false;
		
		board.print_board();
		int y,x;
		
		while(!correct_move)
		{
			cout<< "\nPlayer "<< get_tile() << " choose x";
			cin>> x;
			cout <<"\nPlayer "<< get_tile() << " choose y";
			cin>> y;
			
			correct_move = board.put_sign(y,x,get_tile());
			
			if(!correct_move)
			{
				cout<<"\nInvalid move! Choose again.";
			}	
		}
		board.print_board();
}
