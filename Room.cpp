#include "World.h"
Room::Room(){
}
Room::~Room(){

}
Room::Room(const char* n, const char* d) :Entity(n, d)
{
	isType = ROOM;
}
