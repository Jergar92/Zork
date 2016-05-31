#ifndef _HAWK_MONSTER
#define _HAWK_MONSTER
#include "World.h"
#include "Creature.h"
class Room;
class Hawk : public Creature
{
public:
	Hawk();
	Hawk(const char* name, const char* description, int life, int atack, int armor, Room* location);
	~Hawk();
	void Die();
	void Update();
	void Attack(Creature* container);
	void Attack(Player* hero);
public:
	unsigned int currentTime, lastTime = 0;

};
#endif// _HAWK_MONSTER