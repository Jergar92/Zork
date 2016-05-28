#ifndef _PLAYER
#define _PLAYER
#include "World.h"
#include "Item.h"
#include "Creature.h"
class Room;

class Player : public Creature
{
public:
	Player();
	Player(const char* name, const char* description, int life, int atack, int armor, unsigned int energy, Room* location);
	~Player();
	void Stats()const;
	void Go(Vector<MyString> &strings);
	void Look(Vector<MyString> &strings);
	void Open(Vector<MyString> &strings);
	void Close(Vector<MyString> &strings);
	void Take(Vector<MyString> &strings);
	void Drop(Vector<MyString> &strings);
	void Equip(Vector<MyString> &strings);
	void UnEquip(Vector<MyString> &strings);
	void Push(Vector<MyString> &strings);
	void PutInto(Vector<MyString> &strings);
	void GetFrom(Vector<MyString> &strings);
	void Atack(Vector<MyString> &strings);
	void AtackTarget(Creature* creature);

	void Look()const;
	void Update();

public:
	unsigned int energy = 0;
	unsigned int currentTime, lastTime = 0;
	unsigned int currentAtackTime, lastAtackTime = 0;

	Creature* Target=nullptr;
};


#endif //_PLAYER