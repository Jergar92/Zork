#ifndef _PLAYER
#define _PLAYER
#include "World.h"

class Room;

class Player : public Entity
{
public:
	Player();
	Player(const char* n, const char* d, int life, int dmg, int def);

	~Player();
public:
	Room* location;
	int hp = 100;
	unsigned int atack = 1;
	unsigned int defense = 1;
};


#endif _PLAYER