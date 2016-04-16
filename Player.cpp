#include "World.h"



Player::Player()
{

}
Player::Player(const char* n, const char* d, int life, int dmg, int def) :Entity(n, d)
{
	isType = PLAYER;
}

Player::~Player()
{
}
void Player::Stats()const{
	printf("You have %i hp, %i atack and %i defense\n", hp, atack, defense);
}
