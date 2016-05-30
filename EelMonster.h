#ifndef _EEL_MONSTER
#define _EEL_MONSTER
#include "World.h"
#include "Creature.h"
class Room;
class Eel : public Creature
{
public:
	Eel();
	Eel(const char* name, const char* description, int life, int atack, int armor, Room* location);
	~Eel();
	void Die();
	void Update();
	void Atack(Creature* container);
	void Atack(Player* hero);
public:
	unsigned int currentTime, lastTime = 0;

};
#endif// _EEL_MONSTER