#include "World.h"
Creature::Creature()
{

}
Creature::Creature(const char* name, const char* description, int life, int atack, int armor) :Creature(name, description, life, atack, armor)
{
}

Creature::~Creature()
{
}