#ifndef _CREATURE
#define _CREATURE
#include "World.h"
#include "Item.h"
class Room;
enum TypeCreature{HERO,SELLER,NO_HOSTILE,HOSTILE_PLAYER,HOSTILE_ALL};
enum State{IDLE, MOVE, TAKE, STEAL, ATTACK_HERO, ATTACK_NPC, DIE };

class Creature : public Entity
{
public:
	Creature();
	Creature(const char* name, const char* description, int life, int atack, int armor,Room*location);
	~Creature();
	virtual void Stats()const;;
	virtual void Go(Vector<MyString> &strings);
	virtual void Look(Vector<MyString> &strings);
	virtual void Open(Vector<MyString> &strings);
	virtual void Close(Vector<MyString> &strings);
	virtual void Take(Vector<MyString> &strings);
	virtual void Drop(Vector<MyString> &strings);
	virtual void Equip(Vector<MyString> &strings);
	virtual void UnEquip(Vector<MyString> &strings);
	virtual void Push(Vector<MyString> &strings);
	virtual void PutInto(Vector<MyString> &strings);
	virtual void GetFrom(Vector<MyString> &strings);
	virtual void Look()const;

	void Update();
public:
	Room* location;

	int life = 100;
	unsigned int attack = 1;
	unsigned int armor = 1;
	bool isDead = false;
	TypeCreature CreatureType;
	State currentState;

};


#endif //_CREATURE