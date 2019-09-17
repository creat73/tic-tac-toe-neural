#include "PlayerAI.hpp"

#include<numeric> //accumulate

vector<int> PlayerAI::get_vector0()
{
	return played_boards[{{{{0,0,0}},{{0,0,0}},{{0,0,0}}}}];
}

void PlayerAI::summarise_round(int win)
{
	
	for(auto const& entry : current_boards)
	{			
		if(win==tile && played_boards[entry.first][entry.second] < max_chance)
		{
			played_boards[entry.first][entry.second] += played_boards[entry.first][entry.second]/10;
		}
		
		else if (win!=0 && accumulate(played_boards[entry.first].begin(),played_boards[entry.first].end(),0)>10)
		{
			played_boards[entry.first][entry.second] -= played_boards[entry.first][entry.second]/10;
		}
	}
	
	current_boards.clear();
}


vector<int> PlayerAI::generate_chance_table(array<array<int,3>,3> table)
{
	int empty_fields = 0;
	vector<int> chance_table(9);
	
	for(int y=0;y<3;y++)
	{
		for(int x=0;x<3;x++)
		{
			if(table[y][x] == 0)
			{
				empty_fields++;
			}
		}
	}
	
	for(int i=0;i<empty_fields;i++)
	{
		chance_table[i] = base_chance;
	}
	
	return chance_table;	
}

int PlayerAI::get_empty_field_no(vector<int> chance_table)
{
	vector<int> highest_values;

	int highest_value = 0;
	int index = 0;
	int random_choice;
	
	for (int i=0;i<chance_table.size();i++)
	{
		if(chance_table[i]>highest_value)
		{
			highest_value = chance_table[i];
		}
	}
	
	for(int i=0;i<chance_table.size();i++)
	{
		if(chance_table[i]==highest_value)
		{
			highest_values.push_back(highest_value);
		}
	}
	
	random_choice = rand() % highest_values.size();
	
	
	return random_choice;
//			int total_parts;
//			int random_part_choice;
//			
//			for(int i=0; i<chance_table.size(); i++){
//				total_parts += chance_table[i];
//			}
//			random_part_choice = rand() % total_parts;
//			
//			int i = -1;
//			while(random_part_choice>=0){
//				i++;
//				random_part_choice -= chance_table[i];
//
//			}
//			return i;
}

array<int,2>  PlayerAI::get_x_y(int empty_field_no, array<array<int,3>,3> table)
{
	int current_no = -1;
	
	for(int y=0; y<3; y++)
	{
		for(int x=0; x<3; x++)
		{
			if(table[y][x] == 0)
			{
				current_no++;
			}
			if(current_no == empty_field_no)
			{
			return {x,y};
			}
		}
	}
}

void PlayerAI::make_move(Board &board)
{
	array<array<int,3>,3> table = board.get_board();
	vector<int> chance_table;
	array<int,2>  x_y;
	int y, x, empty_field_no;
	
	if(played_boards.count(table) > 0)
	{
		chance_table = played_boards[table];
	}
	else
	{
		chance_table = generate_chance_table(table);
		played_boards[table] = chance_table;
	}
	
	empty_field_no = get_empty_field_no(chance_table);
	current_boards[table] = empty_field_no;
	x_y = get_x_y(empty_field_no, table);
	board.put_sign(x_y[1],x_y[0],get_tile());
}
