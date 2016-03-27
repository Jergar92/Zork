#include "World.h"
#define NUM_EXITS 24

World::World()
{

	rooms = new Room[13];
	exits = new Exit[24];
	player = new Player;
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
	strcpy_s((rooms + 0)->name, "Home Base");
	strcpy_s((rooms + 0)->description, "this is your settlement.");

	strcpy_s((rooms + 1)->name, "Mountain");
	strcpy_s((rooms + 1)->description, "you're on the top of a mountain with a large rock at the edge of a precipice");

	strcpy_s((rooms + 2)->name, "Waterfall");
	strcpy_s((rooms + 2)->description, "you are on the front of the waterfall, in the background can clearly see your robot AAR-88");

	strcpy_s((rooms + 3)->name, "Abandoned Cave");
	strcpy_s((rooms + 3)->description, "there seems to be nothing , you only see a few rags and a pile of bones");

	strcpy_s((rooms + 4)->name, "Monster Cave");
	strcpy_s((rooms + 4)->description, "you can see a piece of your broken ship and you hear noises coming from the cave");

	strcpy_s((rooms + 5)->name, "Altar");
	strcpy_s((rooms + 5)->description, "you are in a large open area and around you see a pile of bones");

	strcpy_s((rooms + 6)->name, "Big Nest");
	strcpy_s((rooms + 6)->description, "you find yourself on top of a large tree along you see the biggest nest you've seen in your whole life, from there you see a vine down the north");

	strcpy_s((rooms + 7)->name, "Rubble");
	strcpy_s((rooms + 7)->description, "Rubble");

	strcpy_s((rooms + 8)->name, "Thorn Forest");
	strcpy_s((rooms + 8)->description, "You can not see anything, you can move forward in any direction");

	strcpy_s((rooms + 9)->name, "Thorn Forest East");
	strcpy_s((rooms + 9)->description, "You can not see anything, you do not see any exit");

	strcpy_s((rooms + 10)->name, "Thorn Forest West");
	strcpy_s((rooms + 10)->description, "You can not see anything, you do not see any exit");

	strcpy_s((rooms + 11)->name, "Underwater Cave");
	strcpy_s((rooms + 11)->description, "the ceiling of the cave have been destroyed by the impact of your ship probably");

	strcpy_s((rooms + 12)->name, "Jungle");
	strcpy_s((rooms + 12)->description, "you can hear many noises of beasts that you never heard");
	//Exits
	//Mountain to Home Base
	strcpy_s((exits + 1)->name, "Rocky path");
	strcpy_s((exits + 1)->description, "your home base");
	(exits + 1)->origin = (rooms + 1);
	(exits + 1)->destination = (rooms + 0);
	(exits + 1)->direction = south;
	//Altar to Home Base
	strcpy_s((exits + 3)->name, "Little path");
	strcpy_s((exits + 3)->description, "your home base");
	(exits + 3)->origin = (rooms + 5);
	(exits + 3)->destination = (rooms + 0);
	(exits + 3)->direction = west;
	//Jungle to Home base
	strcpy_s((exits + 23)->name, "Jungle path");
	strcpy_s((exits + 23)->description, "your home base");
	(exits + 23)->origin = (rooms + 12);
	(exits + 23)->destination = (rooms + 0);
	(exits + 23)->direction = east;
	//Thorny forest to home base
	strcpy_s((exits + 15)->name, "Thorny path");
	strcpy_s((exits + 15)->description, "many thorns, but nothing more");
	(exits + 15)->origin = (rooms + 8);
	(exits + 15)->destination = (rooms + 0);
	(exits + 15)->direction = north;
	//Home Base to Mountain
	strcpy_s((exits + 0)->name, "Rocky path");
	strcpy_s((exits + 0)->description, "a large mountain, on the top see a big rock");
	(exits + 0)->origin = (rooms + 0);
	(exits + 0)->destination = (rooms + 1);
	(exits + 0)->direction = north;
	(exits + 0)->door = true;
	(exits + 0)->closed = true;
	//Waterfall to Mountain
	strcpy_s((exits + 5)->name, "Rocky path");
	strcpy_s((exits + 5)->description, "a large mountain, on the top see a big rock");
	(exits + 5)->origin = (rooms + 2);
	(exits + 5)->destination = (rooms + 1);
	(exits + 5)->direction = west;
	//Abandoned Cave to Mountain
	strcpy_s((exits + 7)->name, "Rocky path");
	strcpy_s((exits + 7)->description, "a large mountain, on the top see a big rock");
	(exits + 7)->origin = (rooms + 3);
	(exits + 7)->destination = (rooms + 1);
	(exits + 7)->direction = east;
	//Monster Cave to Mountain
	strcpy_s((exits + 9)->name, "Rocky path");
	strcpy_s((exits + 9)->description, "a large mountain, on the top see a big rock");
	(exits + 9)->origin = (rooms + 4);
	(exits + 9)->destination = (rooms + 1);
	(exits + 9)->direction = south;
	//Mountain to Waterfall
	strcpy_s((exits + 4)->name, "Rocky path");
	strcpy_s((exits + 4)->description, "a beautiful waterfall, something seems to shine in it");
	(exits + 4)->origin = (rooms + 1);
	(exits + 4)->destination = (rooms + 2);
	(exits + 4)->direction = east;
	//Rubble to waterfall
	strcpy_s((exits + 13)->name, "vine path");
	strcpy_s((exits + 13)->description, "a waterfall down there, but you know you can not come back here");
	(exits + 13)->origin = (rooms + 7);
	(exits + 13)->destination = (rooms + 2);
	(exits + 13)->direction = west;
	//Mountain to Abandoned cave
	strcpy_s((exits + 6)->name, "Rocky path");
	strcpy_s((exits + 6)->description, "a cave apparently abandoned");
	(exits + 6)->origin = (rooms + 1);
	(exits + 6)->destination = (rooms + 3);
	(exits + 6)->direction = west;
	//Mountain to monster Cave
	strcpy_s((exits + 8)->name, "Rocky path");
	strcpy_s((exits + 8)->description, "a cave, and many noises come from it");
	(exits + 8)->origin = (rooms + 1);
	(exits + 8)->destination = (rooms + 4);
	(exits + 8)->direction = north;
	//Home Base to Altar
	strcpy_s((exits + 2)->name, "Little path");
	strcpy_s((exits + 2)->description, "a large open area, not appear to be dangerous zone");
	(exits + 2)->origin = (rooms + 0);
	(exits + 2)->destination = (rooms + 5);
	(exits + 2)->direction = east;
	(exits + 2)->door = true;
	(exits + 2)->closed = true;
	//Big nest to altar
	strcpy_s((exits + 11)->name, "Little path");
	strcpy_s((exits + 11)->description, "a large open area, not appear to be dangerous zone");
	(exits + 11)->origin = (rooms + 6);
	(exits + 11)->destination = (rooms + 5);
	(exits + 11)->direction = west;
	//Altar to Big nest
	strcpy_s((exits + 10)->name, "Little path");
	strcpy_s((exits + 10)->description, "a big tree, and on top a big nest");
	(exits + 10)->origin = (rooms + 5);
	(exits + 10)->destination = (rooms + 6);
	(exits + 10)->direction = east;
	//Big nest to rubble
	strcpy_s((exits + 12)->name, "vine path");
	strcpy_s((exits + 12)->description, "a rubble down there, but you know you can not come back here");
	(exits + 12)->origin = (rooms + 6);
	(exits + 12)->destination = (rooms + 7);
	(exits + 12)->direction = north;
	//Home base to Thorny path
	strcpy_s((exits + 14)->name, "Thorny path");
	strcpy_s((exits + 14)->description, "many thorns, but nothing more");
	(exits + 14)->origin = (rooms + 0);
	(exits + 14)->destination = (rooms + 8);
	(exits + 14)->direction = south;
	(exits + 14)->door = true;
	(exits + 14)->closed = true;
	//Gun zone to Thorny path
	strcpy_s((exits + 17)->name, "Thorny path");
	strcpy_s((exits + 17)->description, "many thorns, but nothing more");
	(exits + 17)->origin = (rooms + 9);
	(exits + 17)->destination = (rooms + 8);
	(exits + 17)->direction = east;
	//Fuel zone to Thorny path
	strcpy_s((exits + 19)->name, "Thorny path");
	strcpy_s((exits + 19)->description, "many thorns, but nothing more");
	(exits + 19)->origin = (rooms + 10);
	(exits + 19)->destination = (rooms + 8);
	(exits + 19)->direction = west;
	//Underwater Cave to Thorny path
	strcpy_s((exits + 21)->name, "Thorny path");
	strcpy_s((exits + 21)->description, "walk with pain in your feet");
	(exits + 21)->origin = (rooms + 11);
	(exits + 21)->destination = (rooms + 8);
	(exits + 21)->direction = north;
	//Thorny path to gun zone
	strcpy_s((exits + 16)->name, "Thorny path");
	strcpy_s((exits + 16)->description, "many thorns, but nothing more");
	(exits + 16)->origin = (rooms + 8);
	(exits + 16)->destination = (rooms + 9);
	(exits + 16)->direction = west;
	//Thorny path to fuel zone
	strcpy_s((exits + 18)->name, "Thorny path");
	strcpy_s((exits + 18)->description, "many thorns, but nothing more");
	(exits + 18)->origin = (rooms + 8);
	(exits + 18)->destination = (rooms + 10);
	(exits + 18)->direction = east;
	//Thorny path to underwater cave
	strcpy_s((exits + 20)->name, "Thorny path");
	strcpy_s((exits + 20)->description, "many thorns, but nothing more");
	(exits + 20)->origin = (rooms + 8);
	(exits + 20)->destination = (rooms + 11);
	(exits + 20)->direction = south;
	//Home Base to jungle
	strcpy_s((exits + 22)->name, "Jungle path");
	strcpy_s((exits + 22)->description, "a huge jungle, probably full of beasts");
	(exits + 22)->origin = (rooms + 0);
	(exits + 22)->destination = (rooms + 12);
	(exits + 22)->direction = west;
	(exits + 22)->door = true;
	(exits + 22)->closed = true;
}
int World::getDirection(char ope[]){//this defines the direction, if not found returns -1 and the program will exit
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

void World::Torken(char *ope){//this separates the sentence into two if possible
	char operation1[10] = "";
	char operation2[10] = "";
	char *ope1, *ope2;
	ope1 = operation1;
	ope2 = operation2;
	int i = 0, spaces = 0;
	char *context;
	while (ope[i] != '\0') {//checks for spaces and remove uppercase
		ope[i] = (tolower(ope[i]));
		if (ope[i] == ' ') {
			if (ope[i + 1] == '\0'){
				spaces--;
			}
			spaces++;
		}
		i++;
	}
	if (spaces == 0){//this protect the code from wrong commands
		strcpy_s(operation1, ope);
		strcpy_s(operation2, "\0");
	}
	else if (spaces == 1)//This will create two operations
	{
		strcpy_s(operation1, strtok_s(ope, " ", &context));//take the word untill ""
		strcpy_s(operation2, strtok_s(NULL, " ", &context));//take the rest
	}
	else {//if you make more than one space, return \0 
		strcpy_s(operation1, "\0");
		strcpy_s(operation2, "\0");
	}
	getOperation(ope1, ope2);
}

void World::getOperation(char *ope, char *ope2){//list of possible operations
	if (0 == strcmp(ope, "north") || 0 == strcmp(ope, "n")){
		Go(ope);
		return;
	}
	if (0 == strcmp(ope, "south") || 0 == strcmp(ope, "s")){
		Go(ope);
		return;
	}
	if (0 == strcmp(ope, "east") || 0 == strcmp(ope, "e")){
		Go(ope);
		return;
	}
	if (0 == strcmp(ope, "west") || 0 == strcmp(ope, "w")){
		Go(ope);
		return;
	}
	else if (0 == strcmp(ope, "go") || 0 == strcmp(ope, "g")){
		Go(ope2);
		return;
	}
	else if (0 == strcmp(ope, "look") || 0 == strcmp(ope, "l")){
		Look(ope2);
		return;
	}
	else if (0 == strcmp(ope, "open") || 0 == strcmp(ope, "o")){
		Open(ope2);
		return;
	}
	else if (0 == strcmp(ope, "close") || 0 == strcmp(ope, "c")){
		Close(ope2);
		return;
	}
	else if (0 == strcmp(ope, "help") || 0 == strcmp(ope, "h")){
		Help(ope);
		return;
	}
	else if (0 == strcmp(ope, "quit") || 0 == strcmp(ope, "q")){
		return;
	}
	else{
		printf("wrong operation\n");
	}
}

void World::Go(char *operation){//this move the player if the move is possible
	int direction = -1, i = 0;
	direction = getDirection(operation);//dat get the right direction
	if (direction ==-1){
		printf("wrong operation\n");
		return;
	}
	else{
		for (i = 0; i < NUM_EXITS; i++){

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
void World::Look(char *operation){//this looks the exit if there is any
	int direction = -1, i = 0;

	direction = getDirection(operation);//dat get the right direction
	if (direction == -1){
		printf("wrong operation\n");
		return;
	}
	else{
		for (i = 0; i < NUM_EXITS; i++){

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
void World::Open(char *operation){//this open the door if possible
	int direction = -1, i = 0;
	direction = getDirection(operation);
	if (direction == -1){
		printf("wrong operation\n");
		return;
	}
	else{
		for (i = 0; i < NUM_EXITS; i++){
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
void World::Close(char *operation){//	this close the door if possible
	int direction = -1, i = 0;
	direction = getDirection(operation);//dat get the right direction
	if (direction == -1){
		printf("wrong operation\n");
		return;
	}
	else{
		for (i = 0; i < NUM_EXITS; i++){

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

void World::Help(char *operation){
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
	delete player;
	delete[]exits;
	delete[]rooms;

}

