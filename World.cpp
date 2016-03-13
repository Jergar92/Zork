#include "World.h"

World::World()
{

	rooms = new Room[13];
	exits = new Exit[4];
	players = new Player;

}
void World::createWorld() const{
	const char *names[] = { "Home Base", "Rock Path", "Waterfall", "Abandoned Cave", "Monster Cave", "Altar", "Big Nest", "Rubble", "Thorny Path", "Gun Path", "Fuel Path", "Underwater cave", "Jungle"};

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
void World::createExits() const{
	//Home Base
	strcpy_s(rooms[0].side.north, "Rock Path");
	strcpy_s(rooms[0].side.south, "Thorny Path");
	strcpy_s(rooms[0].side.east, "Altar");
	strcpy_s(rooms[0].side.west, "Jungle");
	//Rock Path
	rooms[1].closed = true;
	strcpy_s(rooms[1].side.north, "Monster Cave");
	strcpy_s(rooms[1].side.south, "Home Base");
	strcpy_s(rooms[1].side.east, "Waterfall");
	strcpy_s(rooms[1].side.west, "Abandoned Cave");
	//Waterfall
	strcpy_s(rooms[2].side.north, "");
	strcpy_s(rooms[2].side.south, "");
	strcpy_s(rooms[2].side.east, "");
	strcpy_s(rooms[2].side.west, "Rock Path");
	//Abandoned Cave
	strcpy_s(rooms[3].side.north, "");
	strcpy_s(rooms[3].side.south, "");
	strcpy_s(rooms[3].side.east, "Rock Path");
	strcpy_s(rooms[3].side.west, "");
	//Monster Cave
	strcpy_s(rooms[4].side.north, "");
	strcpy_s(rooms[4].side.south, "Rock Path");
	strcpy_s(rooms[4].side.east, "");
	strcpy_s(rooms[4].side.west, "");
	//Altar
	strcpy_s(rooms[5].side.north, "");
	strcpy_s(rooms[5].side.south, "");
	strcpy_s(rooms[5].side.east, "Big Nest");
	strcpy_s(rooms[5].side.west, "Home Base");
	//Big Nest
	strcpy_s(rooms[6].side.north, "Rubble");
	strcpy_s(rooms[6].side.south, "");
	strcpy_s(rooms[6].side.east, "Altar");
	strcpy_s(rooms[6].side.west, "");
	//Rubble
	strcpy_s(rooms[7].side.north, "");
	strcpy_s(rooms[7].side.south, "");
	strcpy_s(rooms[7].side.east, "");
	strcpy_s(rooms[7].side.west, "Waterfall");
	//Thorny Path
	strcpy_s(rooms[8].side.north, "Home Base");
	strcpy_s(rooms[8].side.south, "Underwater cave");
	strcpy_s(rooms[8].side.east, "Fuel Path");
	strcpy_s(rooms[8].side.west, "Gun Path");
	//Gun Path
	strcpy_s(rooms[9].side.north, "");
	strcpy_s(rooms[9].side.south, "");
	strcpy_s(rooms[9].side.east, "Thorny Path");
	strcpy_s(rooms[9].side.west, "");
	//Fuel Path
	strcpy_s(rooms[10].side.north, "");
	strcpy_s(rooms[10].side.south, "");
	strcpy_s(rooms[10].side.east, "");
	strcpy_s(rooms[10].side.west, "Thorny Path");
	//Underwater cave
	strcpy_s(rooms[11].side.north, "Thorny Path");
	strcpy_s(rooms[11].side.south, "");
	strcpy_s(rooms[11].side.east, "");
	strcpy_s(rooms[11].side.west, "");
	//Jungle
	strcpy_s(rooms[12].side.north, "");
	strcpy_s(rooms[12].side.south, "");
	strcpy_s(rooms[12].side.east, "");
	strcpy_s(rooms[12].side.west, "Home Base");
}
World::~World()
{
	delete[]rooms;
}

