#ifndef _WORLD
#define _WORLD

#include "Entity.h"
#include "Player.h"
#include "Room.h"
#include "Exit.h"
#include "Item.h"
#include "My_Vector.h"
#include "My_String.h"
#include <stdio.h>
#include <cmath>
#include <stdlib.h>
#include <string>
class MyString; 

class World
{
public:
	Vector <Player*> player;
	Vector <Room*> rooms;
	Vector <Exit*> exits;
	Vector <Item*> items;
	Vector <Item*> inventory;

public:
	World();
	~World();

	void createWorld();//this is called on main
	void Help()const;//this is called on main
	void getOperation(Vector<MyString> &strings);
	void Look()const;


private:
	int getDirection(Vector<MyString> &strings);

	void Go(Vector<MyString> &strings);
	void Look(Vector<MyString> &strings);
	void Open(Vector<MyString> &strings);
	void Close(Vector<MyString> &strings);
	void Take(Vector<MyString> &strings);
	void Drop(Vector<MyString> &strings);
	void Equip(Vector<MyString> &strings);
	void UnEquip(Vector<MyString> &strings);
	void Push(Vector<MyString> &strings);
private:

};

#endif _WORLD
