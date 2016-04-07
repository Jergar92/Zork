#ifndef _WORLD
#define _WORLD

#include <stdio.h>
#include <cmath>
#include <stdlib.h>
#include <string>
#include "Player.h"
#include "Room.h"
#include "Exit.h"
#include "Entity.h"
#include "Item.h"
#include "My_String.h"
class MyString; 

class World
{
public:
	Room* rooms = nullptr;
	Exit* exits = nullptr;
	Player* player = nullptr;
	Item* items = nullptr;
	MyString* str=nullptr;
public:
	World();
	~World();

	void createWorld() const;//this is called on main
	void Help()const;//this is called on main
	void getOperation(char* words[]);

private:
	int getDirection(char operation[]);
	void Go(char *words[]);
	void Look(char *words[]);
	void Open(char *words[]);
	void Close(char *words[]);
private:

};

#endif _WORLD
