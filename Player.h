#ifndef _PLAYER
#define _PLAYER
#include "World.h"

class Room;

class Player : public Entity
{
public:
	Room* location;

	Player();
	~Player();
	
};


#endif _PLAYER