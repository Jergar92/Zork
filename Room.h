#ifndef _ROOM
#define _ROOM
#include "World.h"


class Room
{
public:
	char name[25];
	char description[250];
	Room* direction;
	char north[25];
	char south[25];
	char east[25];
	char west[25];
	
public:

	Room();
	~Room();


};



#endif _ROOM