#include "Player.hpp"

void Player::switch_tile()
{
	if(this->tile == 1)
	{
		this->tile =2;
	}
	else
	{
		this->tile = 1;
	}
}

int Player::get_tile()
{
	return this->tile;
}

void Player::set_tile(int tile)
{
	this->tile = tile;
}

