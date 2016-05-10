#include "World.h"
Exit::Exit(){

}
Exit::Exit(const char* name, const char* description, bool closed, bool door, Room* origin, Room*destination, directions direction) :Entity(name, description) 
, closed(closed), door(door), origin(origin), destination(destination), direction(direction)
{
	isType = EXIT;
}


Exit::~Exit(){

}