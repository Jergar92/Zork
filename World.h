#ifndef _WORLD
#define _WORLD

#include "Entity.h"
#include "Player.h"
#include "Room.h"
#include "Exit.h"
#include "Item.h"
#include "Creature.h"
#include "MonkeyMonster.h"
#include "My_Vector.h"
#include "My_String.h"
#include "My_DobleList.h"
#include <stdio.h>
#include <cmath>
#include <stdlib.h>
#include <string>
class MyString; 

class World
{
public:
	
	Vector <Entity*> container;

	Player* hero;

public:
	World();
	~World();

	void createWorld();//this is called on main
	void Help()const;//this is called on main
	void getOperation(Vector<MyString> &strings);
	int getDirection(Vector<MyString> &strings);


private:
	

	
private:

};

extern World* App;
#endif _WORLD
