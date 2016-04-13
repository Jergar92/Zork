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
	Vector <Entity*> group;

public:
	World();
	~World();

	void createWorld();//this is called on main
	void Help()const;//this is called on main
	void getOperation(Vector<MyString> &strings);

private:
	int getDirection(Vector<MyString> &strings);
	
	void Go(Vector<MyString> &strings);
	/*
	void Look(MyString str2[]);
	void Open(MyString str2[]);
	void Close(MyString str2[]);
	*/
private:

};

#endif _WORLD
