#include "World.h"
Creature::Creature()
{

}
Creature::Creature(const char* name, const char* description, int life, int atack, int armor,Room* location) :Entity(name, description)
, life(life), atack(atack), armor(armor), location(location)
{
}

Creature::~Creature()
{
}