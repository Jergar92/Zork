#include "World.h"

Entity::Entity()
{
}
Entity::Entity(const char* n, const char* d)
{
	name = n;
	description = d;
}


Entity::~Entity()
{

}

void Entity::Look()const
{
	printf("You are in %s, %s \n", name.C_Str(), description.C_Str());
}