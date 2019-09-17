#include "Game.hpp"

#include <iostream>



void Game::train_menu()
{
	int games_amount;
	int winner;
	
	print_train_menu();
	cin>>games_amount;
	
	playerAI1.set_tile(1);
	playerAI2.set_tile(2);
	
	for(int i=0;i<games_amount;i++)
	{
		play(playerAI1,playerAI2, play_board);
		
		if(i%(games_amount/100) == 1)
		{
		print_train_menu();
		cout << "\n" << i/(games_amount/100) << "%\n";
		}
	}
	cout << "\nDone!\nType 0 to continue.";
	
	//press anything
	cin >> games_amount;
}

void Game::play_menu()
{
	bool exit = false;
	int tile=0;
	int option;

	string tile_str;
	print_play_menu();
	
	while(tile!=1 && tile !=2)
	{
		cin >> tile;
		if(tile!=1 && tile !=2){
			cout << "Invalid choice!";
		}
	}
	cout << tile;
	player_human.set_tile(tile);
	
	if(tile == 1)
	{
		tile_str = "O";
		playerAI1.set_tile(2);
	}
	else if (tile == 2)
	{
		tile_str = "X";
		playerAI1.set_tile(1);
	}
	
	while(!exit)
	{
		//system("clear");
		play(playerAI1, player_human, play_board);
		cout << "One more?\n1 - Yes\n2 - No";
		cin >> option;
		if(option == 2){
			exit=true;
		}
	}
}
	
void Game::play(Player &player1, Player &player2, Board &board)
{
	bool end_game = false;
	int winner;
	int turn = 1;
	
	while(!end_game)
	{
		
		if(player1.get_tile()==turn)
		{
			player1.make_move(board);
		}
		else{
			player2.make_move(board);
		}
		
		winner = board.check_board();
		if(winner>-1)
		{
			end_game = true;
		}
		
		if(turn==1)
		{
			turn++;
		}
		else{
			turn--;
		}
	}
	
	if(player1.get_tile() == winner)
	{
		player1_wins++;
	}
	else if(player2.get_tile() == winner)
	{
		player2_wins++;
	}
	else
	{
		draws++;
	}
	
	
	player1.summarise_round(winner);
	player2.summarise_round(winner);
	player1.switch_tile();
	player2.switch_tile();
	board.clear_board();	
}

void Game::statistics_menu()
{
	int exit;
	cout << "AI players statistics: " <<  endl
	<<"PlayerAI1 won " << player1_wins << " times" << endl
	<<"PlayerAI2 won " << player2_wins << " times" << endl
	<<draws << " Rounds resulted in draw" << endl; 
	
	cout << "playerAI1 00 table:\n";
	vector<int> chance_table = playerAI1.get_vector0();
	for(int i=0; i<chance_table.size(); i++)
	{
		cout << chance_table[i] << "\n";
	}
	cin >> exit;
}

void Game::print_play_menu()
{
	system("clear");
	cout << "Choose your tile:\n1 - O\n2 - X";
}

void Game::print_train_menu()
{
	system("clear");
	cout<<"NOTE: min amount = 100\nHow many training games should AI play?:";
}

void Game::print_main_menu()
{
	system("clear");
		cout<< endl                                                     
		<<"  dBBBBBBP dBP dBBBP      dBBBBBBP dBBBBBb     dBBBP      dBBBBBBP dBBBBP dBBBP " << endl
		<<"                                        BB                        dBP.BP        " << endl
		<<"   dBP   dBP dBP           dBP      dBP BB   dBP           dBP   dBP.BP dBBP    " << endl
		<<"  dBP   dBP dBP           dBP      dBP  BB  dBP           dBP   dBP.BP dBP      " << endl
		<<" dBP   dBP dBBBBP        dBP      dBBBBBBB dBBBBP        dBP   dBBBBP dBBBBP    " << endl << endl
		<<"                                  MENU"<< endl << endl
		<<"                               1. Train AI" << endl
		<<"                               2. Play vs AI" << endl
		<<"                               3. Statistics" << endl
		<<"                               0. Exit" << endl;
}



void Game::main_menu()
{
	bool exit = false;
	int option;
	
	while(!exit)
	{
		print_main_menu();
		cin>>option;
		
		switch(option)
		{
			case 0 :exit = true;
					break;
			case 1 :train_menu();
					break;
			case 2 :play_menu();
					break;
			case 3 :statistics_menu();
					break;
			
		}
	}
}
