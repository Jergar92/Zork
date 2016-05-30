#ifndef _BEAR_MONSTER
#define _BEAR_MONSTER
#include "World.h"
#include "Creature.h"
class Room;
class Bear : public Creature
{
public:
	Bear();
	Bear(const char* name, const char* description, int life, int atack, int armor, Room* location);
	~Bear();
	void Die();
	void Update();
	void Atack(Creature* container);
	void Atack(Player* hero);
public:
	unsigned int currentTime, lastTime = 0;

};
#endif// _BEAR_MONSTER