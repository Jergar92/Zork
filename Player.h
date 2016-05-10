#ifndef _PLAYER
#define _PLAYER
#include "World.h"

class Room;

class Player : public Entity
{
public:
	Player();
	Player(const char* name, const char* description, int life, int atack, int armor);
	~Player();
	void Stats()const;

public:
	Room* location;
	int life = 100;
	unsigned int atack = 1;
	unsigned int armor = 1;
};


#endif _PLAYER