#ifndef _WORLD
#define _WORLD

#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include <windows.h>
#include "Player.h"
#include "Room.h"
#include "Exit.h"
using namespace std;

class World
{
public:
	Room* rooms = nullptr;
	Exit* exits = nullptr;
	Player* players = nullptr;
public:
	World();
	~World();

	void createWorld() const;
	void createExits() const;

private:

};

#endif _WORLD
