#ifndef GREEDY_AI
#define GREEDY_AI

#include "Player.hpp"

class GreedyAI: public Player{
	private:
		bool is_human = false;
		
		void summarise_round(int win);
		
		int get_next_tile(int tile);

		array<int,2> minmax(Board board);
		
		int minmax_r(Board board,int tile);
		
	public:
		void make_move(Board &board);
		
};

#endif
