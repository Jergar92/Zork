#ifndef _ITEM
#define _ITEM
#include "World.h"

enum itemType{ WEAPON, ARMOR, BOOTS, PICK, ENVIROMENT, TRUNK, MEAT, POTION,QUEST };

class Room;

class Item : public Entity
{
public:
	Item();
	Item(const char*name, const char* description, unsigned int atack, unsigned int defense, bool equiped, bool canTake, bool canPush, Room* location, itemType isItem);
	Item(const char*name, const char* description, unsigned int life, unsigned int energy, bool canTake, itemType isItem);

	~Item();
	void Look() const;
	void Stats()const;
public:

	unsigned int atack = 0;
	unsigned int defense = 0;
	unsigned int life = 0;
	unsigned int energy = 0;
	bool equiped = false;
	bool canTake = true;
	bool canPush = false;
	bool toDestroy = false;
	Room* location;
	itemType isItem;

private:

};



#endif _ITEM
