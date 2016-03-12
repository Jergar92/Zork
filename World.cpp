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
void World::createExits(){
	//Home Base
	strcpy_s(rooms[0].north, "Rock Path");
	strcpy_s(rooms[0].south , "Thorny Path");
	strcpy_s(rooms[0].east , "Altar");
	strcpy_s(rooms[0].west , "Jungle");
	//Rock Path
	strcpy_s(rooms[1].north , "Monster Cave");
	strcpy_s(rooms[1].south , "Home Base");
	strcpy_s(rooms[1].east , "Waterfall");
	strcpy_s(rooms[1].west ,"Abandoned Cave");
	//Waterfall
	strcpy_s(rooms[2].north , "");
	strcpy_s(rooms[2].south , "");
	strcpy_s(rooms[2].east , "");
	strcpy_s(rooms[2].west , "Rock Path");
	//Abandoned Cave
	strcpy_s(rooms[3].north , "");
	strcpy_s(rooms[3].south , "");
	strcpy_s(rooms[3].east , "Rock Path");
	strcpy_s(rooms[3].west , "");
	//Monster Cave
	strcpy_s(rooms[4].north , "");
	strcpy_s(rooms[4].south , "Rock Path");
	strcpy_s(rooms[4].east , "");
	strcpy_s(rooms[4].west , "");
	//Altar
	strcpy_s(rooms[5].north , "");
	strcpy_s(rooms[5].south , "");
	strcpy_s(rooms[5].east , "Big Nest");
	strcpy_s(rooms[5].west , "Home Base");
	//Big Nest
	strcpy_s(rooms[6].north , "Rubble");
	strcpy_s(rooms[6].south , "");
	strcpy_s(rooms[6].east , "Altar");
	strcpy_s(rooms[6].west, "");
	//Rubble
	strcpy_s(rooms[7].north, "");
	strcpy_s(rooms[7].south , "");
	strcpy_s(rooms[7].east , "");
	strcpy_s(rooms[7].west , "Waterfall");
	//Thorny Path
	strcpy_s(rooms[8].north , "Home Base");
	strcpy_s(rooms[8].south , "Underwater cave");
	strcpy_s(rooms[8].east , "Fuel Path");
	strcpy_s(rooms[8].west , "Gun Path");
	//Gun Path
	strcpy_s(rooms[9].north , "");
	strcpy_s(rooms[9].south , "");
	strcpy_s(rooms[9].east , "Thorny Path");
	strcpy_s(rooms[9].west , "");
	//Fuel Path
	strcpy_s(rooms[10].north , "");
	strcpy_s(rooms[10].south, "");
	strcpy_s(rooms[10].east , "");
	strcpy_s(rooms[10].west , "Thorny Path");
	//Underwater cave
	strcpy_s(rooms[11].north , "Thorny Path");
	strcpy_s(rooms[11].south , "");
	strcpy_s(rooms[11].east , "");
	strcpy_s(rooms[11].west , "");
	//Jungle
	strcpy_s(rooms[12].north , "");
	strcpy_s(rooms[12].south , "");
	strcpy_s(rooms[12].east , "");
	strcpy_s(rooms[12].west , "Home Base");
}
World::~World()
{
	delete[]rooms;
}

