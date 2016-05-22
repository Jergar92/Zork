#ifndef _CREATURE
#define _CREATURE
#include "World.h"
#include "Item.h"
class Room;

class Creature : public Entity
{
public:
	Creature();
	Creature(const char* name, const char* description, int life, int atack, int armor);
	~Creature();
	virtual void Stats()const = 0;;
	virtual void Go(Vector<MyString> &strings) = 0;
	virtual void Look(Vector<MyString> &strings) = 0;
	virtual void Open(Vector<MyString> &strings) = 0;
	virtual void Close(Vector<MyString> &strings) = 0;
	virtual void Take(Vector<MyString> &strings) = 0;
	virtual void Drop(Vector<MyString> &strings) = 0;
	virtual void Equip(Vector<MyString> &strings) = 0;
	virtual void UnEquip(Vector<MyString> &strings) = 0;
	virtual void Push(Vector<MyString> &strings) = 0;
	virtual void PutInto(Vector<MyString> &strings) = 0;
	virtual void GetFrom(Vector<MyString> &strings) = 0;
	virtual void Look()const = 0;;

public:
	Room* location;
	Vector <Item*> inventory;

	int life = 100;
	unsigned int atack = 1;
	unsigned int armor = 1;
};


#endif _CREATURE