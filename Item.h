#ifndef _ITEM
#define _ITEM
#include "World.h"


class Room;

class Item : public Entity
{
public:
	Item();
	~Item();
	bool equiped = false;
	bool canTake = true;
	bool canPush = false;
	Room* location;
	 
private:

};



#endif _ITEM
