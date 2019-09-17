#ifndef GAME
#define GAME

#include "PlayerAI.hpp"
#include "GreedyAI.hpp"
#include "PlayerHuman.hpp"

class Game{
	private:
		//play values
		PlayerAI playerAI1;
		PlayerAI playerAI2;
		PlayerAI randomAI;
		PlayerHuman player_human;
		Board play_board;
		//Statistics
		int draws=0;
		int player1_wins = 0;
		int player2_wins = 0;
		int player3_wins = 0;
		
		
		
		void train_menu();
		
		void play_menu();
			
		void play(Player &player1, Player &player2, Board &board);
		
		void statistics_menu();
		
		void print_play_menu();
		
		void print_train_menu();
		
		void print_main_menu();
		
	
	public:
		void main_menu();
};
#endif
