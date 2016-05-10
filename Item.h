#ifndef _ITEM
#define _ITEM
#include "World.h"

enum itemType{ WEAPON, ARMOR, BOOTS, PICK, ENVIROMENT, TRUNK };

class Room;

class Item : public Entity
{
public:
	Item();
	Item(const char*name, const char* description, unsigned int atack, unsigned int defense, bool equiped, bool canTake, bool canPush, Room* location, itemType isItem);

	~Item();
	void Look() const;
	void Stats()const;
public:
	Vector<Item*>trunk;

	unsigned int atack = 0;
	unsigned int defense = 0;
	bool equiped = false;
	bool canTake = true;
	bool canPush = false;
	Room* location;
	itemType isItem;

private:

};



#endif _ITEM
