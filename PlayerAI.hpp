#ifndef PLAYER_AI
#define PLAYER_AI

#include "Player.hpp"
#include <map>
#include <vector>

class PlayerAI: public Player{
	private:
		map<array<array<int,3>,3>,vector<int>> played_boards;
		map<array<array<int,3>,3>,int> current_boards;
		
		double base_chance = 100;
		double max_chance = 100;
		double min_chance = 0;
		double learning_rate = 10;
	
	public:
		bool is_human = false;
		
		vector<int> get_vector0();
		
		void summarise_round(int win);
		
		int get_empty_field_no(vector<int> chance_table);
		
		vector<int> generate_chance_table(array<array<int,3>,3> table);
		
		array<int,2>  get_x_y(int empty_field_no, array<array<int,3>,3> table);
		
		void make_move(Board &board);
};

#endif
