#ifndef _WORLD
#define _WORLD

#include "Room.h"
#include "Player.h"
#include "Exit.h"
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

class World
{
public:
	
	World();
	~World();
private:
	Room rooms[13];
	
};

#endif _WORLD
