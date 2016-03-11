#include "World.h"

World::World()
{
	rooms = new Room[13];
	const char *names[] = { "Home Base", "Rock Path", "Waterfall", "Abandoned Cave", "Monster Cave", "Altar", "Big Nest", "Rubble", "Thorny Path", "Gun Path", "Fuel Path", "Underwater cave", "jungle" };
	for (int i = 0; i < 13; i++){
		strcpy_s(rooms[i].name, names[i]);
	}
	const char *descriptions[] = {
		"",//Home Base
		"",//Rock Path
		"",//Waterfall
		"",//Abandoned Cave
		"",//Monster Cave
		"",//Altar
		"",//Big Nest
		"",//Rubble
		"",//Thorny Path
		"",//Fuel Path
		"",//Underwater cave
		"",//Jungle

	}



	
}

World::~World()
{
	delete[]rooms;
}

void makeWorld(){
	
}
