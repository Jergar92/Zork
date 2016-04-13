#ifndef _ENTITY
#define _ENTITY
#include "World.h"
#include "My_String.h"

enum typeClass{EXIT,ITEM,PLAYER,ROOM};
class Entity
{
public:
	MyString name;
	MyString description;
	typeClass isType;
public:
	Entity();
	Entity(const char* name, const char* description);
	~Entity();

	virtual void Look() const;
private:

};

#endif _ENTITY

