#ifndef BOARD
#define BOARD

#include <array>

using namespace std;

class Board{
	private:
		array<array<int, 3>, 3> board = {{{{0, 0, 0}}, {{0, 0, 0}}, {{0, 0, 0}}}};
	
		bool is_win(int player);
		
		bool is_draw();
	
	public:
		
		//-1 - none 0 - draw 1- O won 2- X won
		int check_board();
		
		void clear_board();
		
		array<array<int,3>,3> get_board();
		
		void print_board();
		
		bool put_sign(int y, int x, int player);
};

#endif
