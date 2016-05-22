#ifndef _MONKEY_MONSTER
#define _MONKEY_MONSTER
#include "World.h"
#include "Item.h"
#include "Creature.h"
class Room;

class Monkey : public Creature
{
public:
	Monkey();
	Monkey(const char* name, const char* description, int life, int atack, int armor);
	~Monkey();
	/*void Stats()const;
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
	void Look()const;
	*/
public:
	Room* location;
	Vector <Item*> inventory;

	int life = 100;
	unsigned int atack = 1;
	unsigned int armor = 1;
};
#endif _MONKEY_MONSTER