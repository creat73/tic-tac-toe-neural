#ifndef PLAYER
#define PLAYER

#include "Board.hpp"

class Player{
	public:
		
		virtual void make_move(Board &board) = 0;
		virtual void summarise_round(int win) = 0;
		
		bool is_human;
		
		void switch_tile();
		
		int get_tile();
		
		void set_tile(int tile);
		
		
	protected:
		
		int tile=0;
	
};

#endif
