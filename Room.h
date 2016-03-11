#ifndef _ROOM
#define _ROOM
#include "World.h"


class Room
{
public:
	char name[25];
	char description[250];
	Room* scr;
	Room* dir;
public:

	Room();
	~Room();


};



#endif _ROOM