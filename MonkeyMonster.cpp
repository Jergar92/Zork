#include "World.h"



Monkey::Monkey()
{

}
Monkey::Monkey(const char* name, const char* description, int life, int atack, int armor) :Creature(name, description, life, atack, armor)
{
	isType = MONSTER;
}

Monkey::~Monkey()
{
}


