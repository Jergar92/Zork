#ifndef _WORLD
#define _WORLD

#include "Entity.h"
#include "Player.h"
#include "Room.h"
#include "Exit.h"
#include "Item.h"
#include "Creature.h"
#include "MonkeyMonster.h"
#include "BearMonster.h"
#include "HawkMonster.h"
#include "EelMonster.h"
#include "Seller.h"
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
	void CleanUp();//this clean container
	void Update();
	unsigned int currentTime, lastTime = 0;
	unsigned int MonkeyNumber = 0;
private:
	

	
private:

};

extern World* App;
#endif _WORLD
