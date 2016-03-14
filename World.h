#ifndef _WORLD
#define _WORLD

#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include <windows.h>
#include <string>
#include "Player.h"
#include "Room.h"
#include "Exit.h"
using namespace std;

class World
{
public:
	Room* rooms = nullptr;
	Exit* exits = nullptr;
	Player* player = nullptr;
public:
	World();
	~World();

	void createWorld() const;
	void createExits() const;
	int getDirection(char ope[]);
	void getOperation(char ope[], char ope2[]);
	void Torken(char ope[]);
	void Go(char command[]);
	void Look(char command[]);
	void Open(char command[]);
private:

};

#endif _WORLD
