#ifndef _ENTITY
#define _ENTITY
#include "World.h"
#include "My_String.h"
#include "My_DobleList.h"
enum typeClass{ EXIT, ITEM, PLAYER, ROOM, MONSTER };
class Entity
{
public:
	MyString name;
	MyString description;
	typeClass isType;
	List <Entity*> list;
public:
	Entity();
	Entity(const char* name, const char* description);
	virtual ~Entity();

	virtual void Look() const;
	virtual void Stats() const;
	virtual void Update();
private:

};

#endif _ENTITY

