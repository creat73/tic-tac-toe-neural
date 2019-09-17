#include <iostream>
#include <time.h>  //time
#include "Game.hpp"

int main()
{
	srand(time(NULL)); // for PlayerAI
	Game game;
	game.main_menu();
}
