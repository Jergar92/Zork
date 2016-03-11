#include "World.h"

World::World()
{
	rooms = new Room[13];
	const char *names[] = { "Home Base", "Rock Path", "Waterfall", "Abandoned Cave", "Monster Cave", "Altar", "Big Nest", "Rubble", "Thorny Path", "Gun Path", "Fuel Path", "Underwater cave", "jungle" };
	for (int i = 0; i < 13; i++){
		strcpy_s(rooms[i].name, names[i]);
	}
	const char *descriptions[] = {
		"You are in a Home Base",//Home Base
		"You are on a road with a large rock at the edge of a precipice",//Rock Path
		"you are on the front of the waterfall and something seems to shine in it",//Waterfall
		"there seems to be nothing , you only see a few rags and a pile of bones",//Abandoned Cave
		"you can see a piece of your broken ship and you hear noises coming from the cave",//Monster Cave
		"You are in a large open area and around you see a pile of bones,",//Altar
		"text",//Big Nest
		"text",//Rubble
		"you can feel as your skin it is torn while you cross, you cannot see anything except ways that are divided in all the directions",//Thorny Path
		"text",//Gun Path
		"text",//Fuel Path
		"the ceiling of the cave have been destroyed by the impact of your ship probably",//Underwater cave
		"you can hear many noises of beasts that you never heard"//Jungle

	};
	for (int i = 0; i < 13; i++){
		strcpy_s(rooms[i].description, descriptions[i]);
	}

	
}

World::~World()
{
	delete[]rooms;
}

