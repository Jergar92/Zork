#include "World.h"

Entity::Entity()
{
}
Entity::Entity(const char* name, const char* description) :name(name), description(description)
{}


Entity::~Entity()
{

}

void Entity::Look()const
{
	printf("You are in %s, %s \n", name.C_Str(), description.C_Str());
}