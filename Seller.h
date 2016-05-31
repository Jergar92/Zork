#ifndef _SELLER
#define _SELLER
#include "World.h"
#include "Creature.h"
class Room;


class Seller : public Creature
{
public:
	Seller();
	Seller(const char* name, const char* description, int life, int atack, int armor, Room* location);
	~Seller();
	void Update();
	void Inventory();
	void Speak();
public:
	unsigned int currentTime, lastTime = 0;

};
#endif// _SELLER