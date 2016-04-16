#ifndef _ITEM
#define _ITEM
#include "World.h"

enum itemType{ WEAPON, ARMOR, BOOTS, PICK, ENVIROMENT };

class Room;

class Item : public Entity
{
public:
	Item();
	Item(const char* n, const char* d, unsigned int atack, unsigned int defense, bool equiped, bool canTake, bool onInventory, bool canPush, Room* location, itemType isItem);

	~Item();
	void Look() const;
	void Stats()const;
public:

	unsigned int atack = 0;
	unsigned int defense = 0;
	bool equiped = false;
	bool canTake = true;
	bool onInventory = false;
	bool canPush = false;
	Room* location;
	itemType isItem;

private:

};



#endif _ITEM
