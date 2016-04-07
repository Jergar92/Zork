#include "World.h"
#define NUM_EXITS 24

World::World()
{

	rooms = new Room[13];
	exits = new Exit[24];
	player = new Player;
	items = new Item[2];
	str = new MyString;
	player->location = rooms + 0;//player location
}
/**********************LOCATIONS*****************************/
//room + 0 = Home Base
//room + 1 = Mountain
//room + 2 = Waterfall
//room + 3 = Abandoned Cave
//room + 4 = Monster Cave
//room + 5 = Altar 
//room + 6 = Big Nest
//room + 7 = Rubble
//room + 8 = Thorn Forest
//room + 9 = Thorn Forest East
//room + 10 = Thorn Forest West
//room + 11 = Underwater Cave
//room + 12 = Jungle
/************************************************************/
void World::createWorld() const{
	//Rooms
	str->Set((rooms + 0)->name, "Home Base");
	str->Set((rooms + 0)->description, "this is your settlement.");

	str->Set((rooms + 1)->name, "Mountain");
	str->Set((rooms + 1)->description, "you're on the top of a mountain with a large rock at the edge of a precipice");

	str->Set((rooms + 2)->name, "Waterfall");
	str->Set((rooms + 2)->description, "you are on the front of the waterfall, in the background can clearly see your robot AAR-88");

	str->Set((rooms + 3)->name, "Abandoned Cave");
	str->Set((rooms + 3)->description, "there seems to be nothing , you only see a few rags and a pile of bones");

	str->Set((rooms + 4)->name, "Monster Cave");
	str->Set((rooms + 4)->description, "you can see a piece of your broken ship and you hear noises coming from the cave");

	str->Set((rooms + 5)->name, "Altar");
	str->Set((rooms + 5)->description, "you are in a large open area and around you see a pile of bones");

	str->Set((rooms + 6)->name, "Big Nest");
	str->Set((rooms + 6)->description, "you find yourself on top of a large tree along you see the biggest nest you've seen in your whole life, from there you see a vine down the north");

	str->Set((rooms + 7)->name, "Rubble");
	str->Set((rooms + 7)->description, "Rubble");

	str->Set((rooms + 8)->name, "Thorn Forest");
	str->Set((rooms + 8)->description, "You can not see anything, you can move forward in any direction");

	str->Set((rooms + 9)->name, "Thorn Forest East");
	str->Set((rooms + 9)->description, "You can not see anything, you do not see any exit");

	str->Set((rooms + 10)->name, "Thorn Forest West");
	str->Set((rooms + 10)->description, "You can not see anything, you do not see any exit");

	str->Set((rooms + 11)->name, "Underwater Cave");
	str->Set((rooms + 11)->description, "the ceiling of the cave have been destroyed by the impact of your ship probably");

	str->Set((rooms + 12)->name, "Jungle");
	str->Set((rooms + 12)->description, "you can hear many noises of beasts that you never heard");

	//////////////////////EXITS/////////////////////////////

	//Mountain to Home Base
	str->Set((exits + 1)->name, "Rocky path");
	str->Set((exits + 1)->description, "your home base");
	(exits + 1)->origin = (rooms + 1);
	(exits + 1)->destination = (rooms + 0);
	(exits + 1)->direction = south;
	//Altar to Home Base
	str->Set((exits + 3)->name, "Little path");
	str->Set((exits + 3)->description, "your home base");
	(exits + 3)->origin = (rooms + 5);
	(exits + 3)->destination = (rooms + 0);
	(exits + 3)->direction = west;
	//Jungle to Home base
	str->Set((exits + 23)->name, "Jungle path");
	str->Set((exits + 23)->description, "your home base");
	(exits + 23)->origin = (rooms + 12);
	(exits + 23)->destination = (rooms + 0);
	(exits + 23)->direction = east;
	//Thorny forest to home base
	str->Set((exits + 15)->name, "Thorny path");
	str->Set((exits + 15)->description, "many thorns, but nothing more");
	(exits + 15)->origin = (rooms + 8);
	(exits + 15)->destination = (rooms + 0);
	(exits + 15)->direction = north;
	//Home Base to Mountain
	str->Set((exits + 0)->name, "Rocky path");
	str->Set((exits + 0)->description, "a large mountain, on the top see a big rock");
	(exits + 0)->origin = (rooms + 0);
	(exits + 0)->destination = (rooms + 1);
	(exits + 0)->direction = north;
	(exits + 0)->door = true;
	(exits + 0)->closed = true;
	//Waterfall to Mountain
	str->Set((exits + 5)->name, "Rocky path");
	str->Set((exits + 5)->description, "a large mountain, on the top see a big rock");
	(exits + 5)->origin = (rooms + 2);
	(exits + 5)->destination = (rooms + 1);
	(exits + 5)->direction = west;
	//Abandoned Cave to Mountain
	str->Set((exits + 7)->name, "Rocky path");
	str->Set((exits + 7)->description, "a large mountain, on the top see a big rock");
	(exits + 7)->origin = (rooms + 3);
	(exits + 7)->destination = (rooms + 1);
	(exits + 7)->direction = east;
	//Monster Cave to Mountain
	str->Set((exits + 9)->name, "Rocky path");
	str->Set((exits + 9)->description, "a large mountain, on the top see a big rock");
	(exits + 9)->origin = (rooms + 4);
	(exits + 9)->destination = (rooms + 1);
	(exits + 9)->direction = south;
	//Mountain to Waterfall
	str->Set((exits + 4)->name, "Rocky path");
	str->Set((exits + 4)->description, "a beautiful waterfall, something seems to shine in it");
	(exits + 4)->origin = (rooms + 1);
	(exits + 4)->destination = (rooms + 2);
	(exits + 4)->direction = east;
	//Rubble to waterfall
	str->Set((exits + 13)->name, "vine path");
	str->Set((exits + 13)->description, "a waterfall down there, but you know you can not come back here");
	(exits + 13)->origin = (rooms + 7);
	(exits + 13)->destination = (rooms + 2);
	(exits + 13)->direction = west;
	//Mountain to Abandoned cave
	str->Set((exits + 6)->name, "Rocky path");
	str->Set((exits + 6)->description, "a cave apparently abandoned");
	(exits + 6)->origin = (rooms + 1);
	(exits + 6)->destination = (rooms + 3);
	(exits + 6)->direction = west;
	//Mountain to monster Cave
	str->Set((exits + 8)->name, "Rocky path");
	str->Set((exits + 8)->description, "a cave, and many noises come from it");
	(exits + 8)->origin = (rooms + 1);
	(exits + 8)->destination = (rooms + 4);
	(exits + 8)->direction = north;
	//Home Base to Altar
	str->Set((exits + 2)->name, "Little path");
	str->Set((exits + 2)->description, "a large open area, not appear to be dangerous zone");
	(exits + 2)->origin = (rooms + 0);
	(exits + 2)->destination = (rooms + 5);
	(exits + 2)->direction = east;
	(exits + 2)->door = true;
	(exits + 2)->closed = true;
	//Big nest to altar
	str->Set((exits + 11)->name, "Little path");
	str->Set((exits + 11)->description, "a large open area, not appear to be dangerous zone");
	(exits + 11)->origin = (rooms + 6);
	(exits + 11)->destination = (rooms + 5);
	(exits + 11)->direction = west;
	//Altar to Big nest
	str->Set((exits + 10)->name, "Little path");
	str->Set((exits + 10)->description, "a big tree, and on top a big nest");
	(exits + 10)->origin = (rooms + 5);
	(exits + 10)->destination = (rooms + 6);
	(exits + 10)->direction = east;
	//Big nest to rubble
	str->Set((exits + 12)->name, "vine path");
	str->Set((exits + 12)->description, "a rubble down there, but you know you can not come back here");
	(exits + 12)->origin = (rooms + 6);
	(exits + 12)->destination = (rooms + 7);
	(exits + 12)->direction = north;
	//Home base to Thorny path
	str->Set((exits + 14)->name, "Thorny path");
	str->Set((exits + 14)->description, "many thorns, but nothing more");
	(exits + 14)->origin = (rooms + 0);
	(exits + 14)->destination = (rooms + 8);
	(exits + 14)->direction = south;
	(exits + 14)->door = true;
	(exits + 14)->closed = true;
	//Gun zone to Thorny path
	str->Set((exits + 17)->name, "Thorny path");
	str->Set((exits + 17)->description, "many thorns, but nothing more");
	(exits + 17)->origin = (rooms + 9);
	(exits + 17)->destination = (rooms + 8);
	(exits + 17)->direction = east;
	//Fuel zone to Thorny path
	str->Set((exits + 19)->name, "Thorny path");
	str->Set((exits + 19)->description, "many thorns, but nothing more");
	(exits + 19)->origin = (rooms + 10);
	(exits + 19)->destination = (rooms + 8);
	(exits + 19)->direction = west;
	//Underwater Cave to Thorny path
	str->Set((exits + 21)->name, "Thorny path");
	str->Set((exits + 21)->description, "walk with pain in your feet");
	(exits + 21)->origin = (rooms + 11);
	(exits + 21)->destination = (rooms + 8);
	(exits + 21)->direction = north;
	//Thorny path to gun zone
	str->Set((exits + 16)->name, "Thorny path");
	str->Set((exits + 16)->description, "many thorns, but nothing more");
	(exits + 16)->origin = (rooms + 8);
	(exits + 16)->destination = (rooms + 9);
	(exits + 16)->direction = west;
	//Thorny path to fuel zone
	str->Set((exits + 18)->name, "Thorny path");
	str->Set((exits + 18)->description, "many thorns, but nothing more");
	(exits + 18)->origin = (rooms + 8);
	(exits + 18)->destination = (rooms + 10);
	(exits + 18)->direction = east;
	//Thorny path to underwater cave
	str->Set((exits + 20)->name, "Thorny path");
	str->Set((exits + 20)->description, "many thorns, but nothing more");
	(exits + 20)->origin = (rooms + 8);
	(exits + 20)->destination = (rooms + 11);
	(exits + 20)->direction = south;
	//Home Base to jungle
	str->Set((exits + 22)->name, "Jungle path");
	str->Set((exits + 22)->description, "a huge jungle, probably full of beasts");
	(exits + 22)->origin = (rooms + 0);
	(exits + 22)->destination = (rooms + 12);
	(exits + 22)->direction = west;
	(exits + 22)->door = true;
	(exits + 22)->closed = true;

	///////////////////ITEMS///////////////////////
	str->Set((items + 0)->name, "Laser Gun");
	str->Set((items + 0)->description, "a powerfull large distance weapon");
	(items + 0)->location = (rooms + 0);

	str->Set((items + 0)->name, "Gigant Rock");
	str->Set((items + 0)->description, "It is very big but is on the brink of precipice sure You can push it");
	(items + 1)->location = (rooms + 1);
	(items + 1)->canTake = false;
	(items + 1)->canPush = true;
}



void World::getOperation(char* ope[]){//list of possible operations
	if ((ope[0]== "north") || (ope[0]=="n")){
		ope[1] = "north";
		Go(ope);
		return;
	}
	if (str->Equals(ope[0], "south") || str->Equals(ope[0], "s")){
		ope[1] = "south";
		Go(ope);
		return;
	}
	if (str->Equals(ope[0], "east") || str->Equals(ope[0], "e")){
		ope[1] = "east";
		Go(ope);
		return;
	}
	if (str->Equals(ope[0], "west") || str->Equals(ope[0], "w")){
		ope[1] = "west";
		Go(ope);
		return;
	}
	else if (str->Equals(ope[0], "go") || str->Equals(ope[0], "g")){
		Go(ope);
		return;
	}
	else if (str->Equals(ope[0], "look") || str->Equals(ope[0], "l")){
		Look(ope);
		return;
	}
	else if (str->Equals(ope[0], "open") || str->Equals(ope[0], "o")){
		Open(ope);
		return;
	}
	else if (str->Equals(ope[0], "close") || str->Equals(ope[0], "c")){
		Close(ope);
		return;
	}
	else if (str->Equals(ope[0], "help") || str->Equals(ope[0], "h")){
		Help();
		return;
	}
	else if (str->Equals(ope[0], "quit") || str->Equals(ope[0], "q")){
		return;
	}
	else{
		printf("wrong operation\n");
	}
}
int World::getDirection(char ope[]){//this defines the direction, if not found returns -1 and the program will exit
	if ((str->Equals(ope, "north")) || (str->Equals(ope, "n"))){
		return 0;
	}
	if ((str->Equals(ope, "south")) || (str->Equals(ope, "s"))){
		return 1;
	}
	if ((str->Equals(ope, "east")) || (str->Equals(ope, "e"))){
		return 2;
	}
	if ((str->Equals(ope, "west")) || (str->Equals(ope, "w"))){
		return 3;
	}
	return -1;
}

void World::Go(char *operation[]){//this move the player if the move is possible
	int direction = -1;
	direction = getDirection(operation[1]);//dat get the right direction
	if (direction ==-1){
		printf("wrong operation\n");
		return;
	}
	else{
		for (int i = 0; i < NUM_EXITS; i++){

			if (0 == strcmp(exits[i].origin->name, player->location->name))
			{
				if (exits[i].direction == direction){//check if they have the same direction
					if (exits[i].closed == true){//check if the exit is closed
						printf("the door is closed\n");
						return;
					}
					else{
						player->location = exits[i].destination;//change your location
						printf("You are in %s, %s \n", player->location->name, player->location->description);//Print your current location
						return;
					}
				}
			}
		}
			printf("you can not pass\n");
	}
}
void World::Look(char *operation[]){//this looks the exit if there is any
	int direction = -1;
	direction = getDirection(operation[1]);//dat get the right direction
	if (direction == -1){
		printf("wrong operation\n");
		return;
	}
	else{
		for (int i = 0; i < NUM_EXITS; i++){

			if (0 == strcmp(exits[i].origin->name, player->location->name))
			{
				if (exits[i].direction == direction){//check if they have the same direction
					printf("You see a %s and you see %s ", exits[i].name,exits[i].description);
					return;
				}
			}
		}
		printf("nothing here\n");
		
	}
}
void World::Open(char *operation[]){//this open the door if possible
	int direction = -1;
	direction = getDirection(operation[1]);
	if (direction == -1){
		printf("wrong operation\n");
		return;
	}
	else{
		for (int i = 0; i < NUM_EXITS; i++){
			if (0 == strcmp(exits[i].origin->name, player->location->name))
			{
				if (exits[i].direction == direction){
					if (exits[i].door == true){//check if we have door
						if (exits[i].closed == true)
							exits[i].closed = false;
							printf("the door is open\n");
							return;
					}
				}
			}
		}
		printf("nothing can't be opened\n");
		
	}
}
void World::Close(char *operation[]){//	this close the door if possible
	int direction = -1;
	direction = getDirection(operation[1]);//dat get the right direction
	if (direction == -1){
		printf("wrong operation\n");
		return;
	}
	else{
		for (int i = 0; i < NUM_EXITS; i++){

			if (0 == strcmp(exits[i].origin->name, player->location->name))
			{
				if (exits[i].direction == direction){
					if (exits[i].door == true){//check if we have door
						if (exits[i].closed == false){
							exits[i].closed = true;
							printf("the door is closed\n");
							return;
						}
					}
				}
			}
		}
			printf("nothing can't be opened\n");
		
	}
}


void World::Help()const{
	printf("This is Zork S.O.S No man's land");
	printf("Your ship has crashed on an unknown planet,\nyou must retrieve the necessary parts of your destroyed ship scattered around the area and build a beacon for help, your resources are limited and will have to find more to survive.\n\n");
	printf("You can move using the comand Go North G North, North or N\n");
	printf("You can look using the command Look North, Look N or L N.\n");
	printf("You can open using the command Open North, Open N or O N.\n");
	printf("You can quit the program using the command Quit.\n");

	printf("(or any other direction using the same structure), don't worry about case sensitive\n\n");
}

World::~World()
{
	delete str;
	delete[] items;
	delete player;
	delete[]exits;
	delete[]rooms;
}

