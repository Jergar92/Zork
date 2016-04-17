#ifndef _EXIT
#define _EXIT
#include "World.h"

class Room;

enum directions{ NORTH, SOUTH, EAST, WEST };

class Exit: public Entity
{
public:
	Exit();
	Exit(const char* n, const char* d, bool closed, bool door, Room* origin, Room*destination, directions dir);
	~Exit();
public:
	bool closed = false;
	bool door = false;
	Room* origin;
	Room* destination;
	directions direction;
};





#endif _EXIT