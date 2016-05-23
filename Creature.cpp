#include "World.h"
Creature::Creature()
{

}
Creature::Creature(const char* name, const char* description, int life, int atack, int armor) :Entity(name, description)
,life(life), atack(atack),armor(armor)
{
}

Creature::~Creature()
{
}