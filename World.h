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

	void createWorld() const;//this is called on main
	void createExits() const;//this is called on main
	void Torken(char operation[]);//this is called on main
	void Help(char operation[]);//this is called on main
private:
	int getDirection(char operation[]);
	void getOperation(char ope[], char ope2[]);
	void Go(char operation[]);
	void Look(char operation[]);
	void Open(char operation[]);
	void Close(char operation[]);
private:

};

#endif _WORLD
