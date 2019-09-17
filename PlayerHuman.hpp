#ifndef PLAYER_HUMAN
#define PLAYER_HUMAN

#include "Player.hpp"
#include "Board.hpp"

class PlayerHuman: public Player{	
	public:
		bool is_human = true;
		
		void summarise_round(int win);
		
		void make_move(Board &board);
};

#endif
