#ifndef _PLAYER
#define _PLAYER
#include "World.h"
#include "Entity.h"

class Room;

class Player : public Entity
{
public:
	Room* location;
};


#endif _PLAYER