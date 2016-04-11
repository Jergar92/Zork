#ifndef _WORLD
#define _WORLD

#include "Entity.h"
#include "Player.h"
#include "Room.h"
#include "Exit.h"
#include "Item.h"
#include "My_String.h"
#include <stdio.h>
#include <cmath>
#include <stdlib.h>
#include <string>
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
	void getOperation(MyString str2[]);

private:
	int getDirection(MyString str2[]);
	void Go(MyString str2[]);
	void Look(MyString str2[]);
	void Open(MyString str2[]);
	void Close(MyString str2[]);
private:

};

#endif _WORLD
