#include "World.h"
Exit::Exit(){

}
Exit::Exit(const char* n, const char* d, bool _closed, bool _door, Room* _origin, Room*_destination, directions _dir) :Entity(n, d)
{
	closed = _closed;
	door = _door;
	origin = _origin;
	destination = _destination;
	direction = _dir;
	isType = EXIT;
}


Exit::~Exit(){

}