#include "World.h"
Room::Room(){
}
Room::~Room(){

}
Room::Room(const char* name, const char* description) :Entity(name, description)
{
	isType = ROOM;
}
