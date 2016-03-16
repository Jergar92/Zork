#ifndef _EXIT
#define _EXIT
#include "World.h"

class Room;

enum directions{ north, south, east, west };
class Exit
{
public:
	char name[25];
	char description[250];
	bool closed = false;
	bool door = false;

	Room* origin;
	Room* destination;
	directions direction;
};





#endif _EXIT