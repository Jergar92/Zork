#include "World.h"
#define NUM_EXITS 24

World::World()
{

	rooms = new Room[13];
	exits = new Exit[24];
	player = new Player;
	player->location = rooms + 0;
}
/************************************************************/
//room + 0 = Home
//room + 1 = Rock Path
/************************************************************/
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
	//to Rock path
	strcpy_s((exits + 0)->name, "Rocky path");
	strcpy_s((exits + 0)->description, "walk with pain in your feet");
	(exits + 0)->origin = (rooms + 0);
	(exits + 0)->destination = (rooms + 1);
	(exits + 0)->direction = north;
	//to Home Base
	strcpy_s((exits + 1)->name, "Rocky path");
	strcpy_s((exits + 1)->description, "walk with pain in your feet");
	(exits + 1)->origin = (rooms + 1);
	(exits + 1)->destination = (rooms + 0);
	(exits + 1)->direction = south;
	//to Altar
	strcpy_s((exits + 2)->name, "Little path");
	strcpy_s((exits + 2)->description, "walk with pain in your feet");
	(exits + 2)->origin = (rooms + 0);
	(exits + 2)->destination = (rooms + 5);
	(exits + 2)->direction = east;
	//to Home Base
	strcpy_s((exits + 3)->name, "Little path");
	strcpy_s((exits + 3)->description, "walk with pain in your feet");
	(exits + 3)->origin = (rooms + 5);
	(exits + 3)->destination = (rooms + 0);
	(exits + 3)->direction = west;
	//to Waterfall
	strcpy_s((exits + 4)->name, "waterfall path");
	strcpy_s((exits + 4)->description, "walk with pain in your feet");
	(exits + 4)->origin = (rooms + 1);
	(exits + 4)->destination = (rooms + 2);
	(exits + 4)->direction = east;
	//to Rock path
	strcpy_s((exits + 5)->name, "waterfall path");
	strcpy_s((exits + 5)->description, "walk with pain in your feet");
	(exits + 5)->origin = (rooms + 2);
	(exits + 5)->destination = (rooms + 1);
	(exits + 5)->direction = west;
	//to Abandoned cave
	strcpy_s((exits + 6)->name, "Little path");
	strcpy_s((exits + 6)->description, "walk with pain in your feet");
	(exits + 6)->origin = (rooms + 1);
	(exits + 6)->destination = (rooms + 3);
	(exits + 6)->direction = west;
	//to Rock path
	strcpy_s((exits + 7)->name, "Little path");
	strcpy_s((exits + 7)->description, "walk with pain in your feet");
	(exits + 7)->origin = (rooms + 3);
	(exits + 7)->destination = (rooms + 1);
	(exits + 7)->direction = east;
	//to monster Cave
	strcpy_s((exits + 8)->name, "Little path");
	strcpy_s((exits + 8)->description, "walk with pain in your feet");
	(exits + 8)->origin = (rooms + 1);
	(exits + 8)->destination = (rooms + 4);
	(exits + 8)->direction = north;
	//to Rock path
	strcpy_s((exits + 9)->name, "Little path");
	strcpy_s((exits + 9)->description, "walk with pain in your feet");
	(exits + 9)->origin = (rooms + 4);
	(exits + 9)->destination = (rooms + 1);
	(exits + 9)->direction = south;
	//to Big nest
	strcpy_s((exits + 10)->name, "Little path");
	strcpy_s((exits + 10)->description, "walk with pain in your feet");
	(exits + 10)->origin = (rooms + 5);
	(exits + 10)->destination = (rooms + 6);
	(exits + 10)->direction = east;
	//to altar
	strcpy_s((exits + 11)->name, "Little path");
	strcpy_s((exits + 11)->description, "walk with pain in your feet");
	(exits + 11)->origin = (rooms + 6);
	(exits + 11)->destination = (rooms + 5);
	(exits + 11)->direction = west;
	//to rubble
	strcpy_s((exits + 12)->name, "Little path");
	strcpy_s((exits + 12)->description, "walk with pain in your feet");
	(exits + 12)->origin = (rooms + 6);
	(exits + 12)->destination = (rooms + 7);
	(exits + 12)->direction = north;
	//to waterfall
	strcpy_s((exits + 13)->name, "Little path");
	strcpy_s((exits + 13)->description, "walk with pain in your feet");
	(exits + 13)->origin = (rooms + 7);
	(exits + 13)->destination = (rooms + 2);
	(exits + 13)->direction = west;
	//to Thorny path
	strcpy_s((exits + 14)->name, "Little path");
	strcpy_s((exits + 14)->description, "walk with pain in your feet");
	(exits + 14)->origin = (rooms + 0);
	(exits + 14)->destination = (rooms + 8);
	(exits + 14)->direction = south;
	//to home base
	strcpy_s((exits + 15)->name, "Little path");
	strcpy_s((exits + 15)->description, "walk with pain in your feet");
	(exits + 15)->origin = (rooms + 8);
	(exits + 15)->destination = (rooms + 0);
	(exits + 15)->direction = north;
	//to gun path
	strcpy_s((exits + 16)->name, "Little path");
	strcpy_s((exits + 16)->description, "walk with pain in your feet");
	(exits + 16)->origin = (rooms + 8);
	(exits + 16)->destination = (rooms + 9);
	(exits + 16)->direction = west;
	//to Thorny path
	strcpy_s((exits + 17)->name, "Little path");
	strcpy_s((exits + 17)->description, "walk with pain in your feet");
	(exits + 17)->origin = (rooms + 9);
	(exits + 17)->destination = (rooms + 8);
	(exits + 17)->direction = east;
	//to fuel path
	strcpy_s((exits + 18)->name, "Little path");
	strcpy_s((exits + 18)->description, "walk with pain in your feet");
	(exits + 18)->origin = (rooms + 8);
	(exits + 18)->destination = (rooms + 10);
	(exits + 18)->direction = east;
	//to Thorny path
	strcpy_s((exits + 19)->name, "Little path");
	strcpy_s((exits + 19)->description, "walk with pain in your feet");
	(exits + 19)->origin = (rooms + 10);
	(exits + 19)->destination = (rooms + 8);
	(exits + 19)->direction = west;
	//to underwater cave
	strcpy_s((exits + 20)->name, "Little path");
	strcpy_s((exits + 20)->description, "walk with pain in your feet");
	(exits + 20)->origin = (rooms + 8);
	(exits + 20)->destination = (rooms + 11);
	(exits + 20)->direction = south;
	//to Thorny path
	strcpy_s((exits + 21)->name, "Little path");
	strcpy_s((exits + 21)->description, "walk with pain in your feet");
	(exits +21)->origin = (rooms + 11);
	(exits + 21)->destination = (rooms + 8);
	(exits + 21)->direction = north;
	//to jungle
	strcpy_s((exits + 22)->name, "Little path");
	strcpy_s((exits + 22)->description, "walk with pain in your feet");
	(exits + 22)->origin = (rooms + 0);
	(exits + 22)->destination = (rooms + 12);
	(exits + 22)->direction = west;
	//to home base
	strcpy_s((exits + 23)->name, "Little path");
	strcpy_s((exits + 23)->description, "walk with pain in your feet");
	(exits + 23)->origin = (rooms + 12);
	(exits + 23)->destination = (rooms + 0);
	(exits + 23)->direction = east;

}
int World::getDirection(char ope[]){
	if ((0 == strcmp(ope, "north")) || (0 == strcmp(ope, "n"))){
		return 0;
	}
	if ((0 == strcmp(ope, "south")) || (0 == strcmp(ope, "s"))){
		return 1;
	}
	if ((0 == strcmp(ope, "east")) || (0 == strcmp(ope, "e"))){
		return 2;
	}
	if ((0 == strcmp(ope, "west")) || (0 == strcmp(ope, "w"))){
		return 3;
	}
	return -1;
}

void World::Torken(char ope[]){
	char operation1[10] = "";
	char operation2[10] = "";
	int i = 0, spaces = 0;
	char *context;

	while (ope[i] != '\0') {//checks for spaces
		if (ope[i] == ' ') spaces++;
		i++;
	}
	if (spaces == 0){
		strcpy_s(operation1, ope);
		strcpy_s(operation2, "\0");
	}
	else{
		strcpy_s(operation1, strtok_s(ope, " ", &context));
		strcpy_s(operation2, strtok_s(NULL, " ", &context));
	}
	getOperation(operation1, operation2);
}

void World::getOperation(char ope[], char ope2[]){
	if (0 == strcmp(ope, "north") || 0 == strcmp(ope, "n")){
		Go(ope);
	}
	if (0 == strcmp(ope, "south") || 0 == strcmp(ope, "s")){
		Go(ope);
	}
	if (0 == strcmp(ope, "east") || 0 == strcmp(ope, "e")){
		Go(ope);
	}
	if (0 == strcmp(ope, "west") || 0 == strcmp(ope, "w")){
		Go(ope);
	}
	else if (0 == strcmp(ope, "open")){
		Open(ope2);
	}
	else if (0 == strcmp(ope, "go")){
		Go(ope2);
	}
	else if (0 == strcmp(ope, "look")){
		Look(ope2);
	}

}
void World::Go(char operation[]){
	int direction = -1, i = 0;
	direction = getDirection(operation);
	for (i = 0; i < NUM_EXITS; i++){

		if (0 == strcmp(exits[i].origin->name, player->location->name))
		{
			if (exits[i].direction == direction){
				player->location = exits[i].destination;
				break;
			}
		}
	}
}
void World::Look(char operation[]){
	int direction = -1, i = 0;
	direction = getDirection(operation);
	for (i = 0; i < NUM_EXITS; i++){

		if (0 == strcmp(exits[i].origin->name, player->location->name))
		{
			if (exits[i].direction == direction){
				printf("%s", exits[i].description);
				break;
			}
		}
	}
}
void World::Open(char operation[]){
	int direction = -1, i = 0;
	direction = getDirection(operation);
	for (i = 0; i < NUM_EXITS; i++){

		if (0 == strcmp(exits[i].origin->name, player->location->name))
		{
			if (exits[i].direction == direction){
				if (exits[i].door == true){
					if (exits[i].closed == true)
						exits[i].closed = false;
				}
				break;
			}
		}
	}
}



World::~World()
{
	delete[]rooms;
	delete[]exits;
	delete[]player;

}

