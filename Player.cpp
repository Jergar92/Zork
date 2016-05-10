#include "World.h"



Player::Player()
{

}
Player::Player(const char* name, const char* description, int life, int atack, int armor) :Entity(name, description)
, life(life), atack(atack), armor(armor)
{
	isType = PLAYER;
}

Player::~Player()
{
}
void Player::Stats()const{
	printf("You have %i hp, %i atack and %i defense\n", life, atack, armor);
}
