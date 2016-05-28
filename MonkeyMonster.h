#ifndef _MONKEY_MONSTER
#define _MONKEY_MONSTER
#include "World.h"
#include "Item.h"
#include "Creature.h"
class Room;
enum State{ MOVE, TAKE, STEAL,ATACK_HERO, ATACK_NPC, DIE };
class Monkey : public Creature
{
public:
	Monkey();
	Monkey(const char* name, const char* description, int life, int atack, int armor,Room* location);
	~Monkey();
	void Go();
	void Take();
	void Steal();
	void Die();
	void Equip();
	void UnEquip(Vector<MyString> &strings);
	void Update();
	void Atack(Creature* container);
	void Atack(Player* hero);
	bool CheckTake();
	State currentState;
public:
	unsigned int currentTime, lastTime = 0;

};
#endif// _MONKEY_MONSTER