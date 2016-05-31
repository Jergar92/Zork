#ifndef _MONKEY_MONSTER
#define _MONKEY_MONSTER
#include "World.h"
#include "Creature.h"
class Room;
class Monkey : public Creature
{
public:
	Monkey();
	Monkey(const char* name, const char* description, int life, int atack, int armor,Room* location);
	~Monkey();
	void Go();
	void Take();
	//void Steal();
	void Die();
	void Equip();
	void Update();
	void Attack(Creature* container);
	void Attack(Player* hero);
	bool CheckTake();
public:
	unsigned int currentTime, lastTime = 0;

};
#endif// _MONKEY_MONSTER