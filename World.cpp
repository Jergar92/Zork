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
	(rooms + 0)->name->string= "Home Base";
	(rooms + 0)->description->string = "this is your settlement.";

	(rooms + 1)->name->string = "Mountain";
	(rooms + 1)->description->string = "you're on the top of a mountain with a large rock at the edge of a precipice";

	(rooms + 2)->name->string = "Waterfall";
	(rooms + 2)->description->string = "you are on the front of the waterfall, in the background can clearly see your robot AAR-88";

	(rooms + 3)->name->string = "Abandoned Cave";
	(rooms + 3)->description->string = "there seems to be nothing , you only see a few rags and a pile of bones";

	(rooms + 4)->name->string =  "Monster Cave";
	(rooms + 4)->description->string =  "you can see a piece of your broken ship and you hear noises coming from the cave";

	(rooms + 5)->name->string =  "Altar";
	(rooms + 5)->description->string = "you are in a large open area and around you see a pile of bones";

	(rooms + 6)->name->string = "Big Nest";
	(rooms + 6)->description->string = "you find yourself on top of a large tree along you see the biggest nest you've seen in your whole life, from there you see a vine down the north";

	(rooms + 7)->name->string = "Rubble";
	(rooms + 7)->description->string =  "Rubble";

	(rooms + 8)->name->string = "Thorn Forest";
	(rooms + 8)->description->string = "You can not see anything, you can move forward in any direction";

	(rooms + 9)->name->string = "Thorn Forest East";
	(rooms + 9)->description->string =  "You can not see anything, you do not see any exit";

	(rooms + 10)->name->string = "Thorn Forest West";
	(rooms + 10)->description->string = "You can not see anything, you do not see any exit";

	(rooms + 11)->name->string =  "Underwater Cave";
	(rooms + 11)->description->string = "the ceiling of the cave have been destroyed by the impact of your ship probably";

	(rooms + 12)->name->string =  "Jungle";
	(rooms + 12)->description->string =  "you can hear many noises of beasts that you never heard";

	//////////////////////EXITS/////////////////////////////

	//Mountain to Home Base
	(exits + 1)->name->string = "Rocky path";
	(exits + 1)->description->string = "your home base";
	(exits + 1)->origin = (rooms + 1);
	(exits + 1)->destination = (rooms + 0);
	(exits + 1)->direction = south;
	//Altar to Home Base
	(exits + 3)->name->string =  "Little path";
	(exits + 3)->description->string = "your home base";
	(exits + 3)->origin = (rooms + 5);
	(exits + 3)->destination = (rooms + 0);
	(exits + 3)->direction = west;
	//Jungle to Home base
	(exits + 23)->name->string = "Jungle path";
	(exits + 23)->description->string =  "your home base";
	(exits + 23)->origin = (rooms + 12);
	(exits + 23)->destination = (rooms + 0);
	(exits + 23)->direction = east;
	//Thorny forest to home base
	(exits + 15)->name->string =  "Thorny path";
	(exits + 15)->description->string =  "many thorns, but nothing more";
	(exits + 15)->origin = (rooms + 8);
	(exits + 15)->destination = (rooms + 0);
	(exits + 15)->direction = north;
	//Home Base to Mountain
	(exits + 0)->name->string = "Rocky path";
	(exits + 0)->description->string = "a large mountain, on the top see a big rock";
	(exits + 0)->origin = (rooms + 0);
	(exits + 0)->destination = (rooms + 1);
	(exits + 0)->direction = north;
	(exits + 0)->door = true;
	(exits + 0)->closed = true;
	//Waterfall to Mountain
	(exits + 5)->name->string = "Rocky path";
	(exits + 5)->description->string = "a large mountain, on the top see a big rock";
	(exits + 5)->origin = (rooms + 2);
	(exits + 5)->destination = (rooms + 1);
	(exits + 5)->direction = west;
	//Abandoned Cave to Mountain
	(exits + 7)->name->string =  "Rocky path";
	(exits + 7)->description->string =  "a large mountain, on the top see a big rock";
	(exits + 7)->origin = (rooms + 3);
	(exits + 7)->destination = (rooms + 1);
	(exits + 7)->direction = east;
	//Monster Cave to Mountain
	(exits + 9)->name->string =  "Rocky path";
	(exits + 9)->description, "a large mountain, on the top see a big rock";
	(exits + 9)->origin = (rooms + 4);
	(exits + 9)->destination = (rooms + 1);
	(exits + 9)->direction = south;
	//Mountain to Waterfall
	(exits + 4)->name->string =  "Rocky path";
	(exits + 4)->description->string =  "a beautiful waterfall, something seems to shine in it";
	(exits + 4)->origin = (rooms + 1);
	(exits + 4)->destination = (rooms + 2);
	(exits + 4)->direction = east;
	//Rubble to waterfall
	(exits + 13)->name->string = "vine path";
	(exits + 13)->description->string =  "a waterfall down there, but you know you can not come back here";
	(exits + 13)->origin = (rooms + 7);
	(exits + 13)->destination = (rooms + 2);
	(exits + 13)->direction = west;
	//Mountain to Abandoned cave
	(exits + 6)->name->string =  "Rocky path";
	(exits + 6)->description->string =  "a cave apparently abandoned";
	(exits + 6)->origin = (rooms + 1);
	(exits + 6)->destination = (rooms + 3);
	(exits + 6)->direction = west;
	//Mountain to monster Cave
	(exits + 8)->name->string = "Rocky path";
	(exits + 8)->description->string = "a cave, and many noises come from it";
	(exits + 8)->origin = (rooms + 1);
	(exits + 8)->destination = (rooms + 4);
	(exits + 8)->direction = north;
	//Home Base to Altar
	(exits + 2)->name->string =  "Little path";
	(exits + 2)->description->string =  "a large open area, not appear to be dangerous zone";
	(exits + 2)->origin = (rooms + 0);
	(exits + 2)->destination = (rooms + 5);
	(exits + 2)->direction = east;
	(exits + 2)->door = true;
	(exits + 2)->closed = true;
	//Big nest to altar
	(exits + 11)->name->string =  "Little path";
	(exits + 11)->description->string =  "a large open area, not appear to be dangerous zone";
	(exits + 11)->origin = (rooms + 6);
	(exits + 11)->destination = (rooms + 5);
	(exits + 11)->direction = west;
	//Altar to Big nest
	(exits + 10)->name->string =  "Little path";
	(exits + 10)->description->string =  "a big tree, and on top a big nest";
	(exits + 10)->origin = (rooms + 5);
	(exits + 10)->destination = (rooms + 6);
	(exits + 10)->direction = east;
	//Big nest to rubble
	(exits + 12)->name->string = "vine path";
	(exits + 12)->description->string = "a rubble down there, but you know you can not come back here";
	(exits + 12)->origin = (rooms + 6);
	(exits + 12)->destination = (rooms + 7);
	(exits + 12)->direction = north;
	//Home base to Thorny path
	(exits + 14)->name->string = "Thorny path";
	(exits + 14)->description->string = "many thorns, but nothing more";
	(exits + 14)->origin = (rooms + 0);
	(exits + 14)->destination = (rooms + 8);
	(exits + 14)->direction = south;
	(exits + 14)->door = true;
	(exits + 14)->closed = true;
	//Gun zone to Thorny path
	(exits + 17)->name->string = "Thorny path";
	(exits + 17)->description->string = "many thorns, but nothing more";
	(exits + 17)->origin = (rooms + 9);
	(exits + 17)->destination = (rooms + 8);
	(exits + 17)->direction = east;
	//Fuel zone to Thorny path
	(exits + 19)->name->string =  "Thorny path";
	(exits + 19)->description->string =  "many thorns, but nothing more";
	(exits + 19)->origin = (rooms + 10);
	(exits + 19)->destination = (rooms + 8);
	(exits + 19)->direction = west;
	//Underwater Cave to Thorny path
	(exits + 21)->name->string =  "Thorny path";
	(exits + 21)->description->string =  "walk with pain in your feet";
	(exits + 21)->origin = (rooms + 11);
	(exits + 21)->destination = (rooms + 8);
	(exits + 21)->direction = north;
	//Thorny path to gun zone
	(exits + 16)->name->string = "Thorny path";
	(exits + 16)->description->string = "many thorns, but nothing more";
	(exits + 16)->origin = (rooms + 8);
	(exits + 16)->destination = (rooms + 9);
	(exits + 16)->direction = west;
	//Thorny path to fuel zone
	(exits + 18)->name->string = "Thorny path";
	(exits + 18)->description->string = "many thorns, but nothing more";
	(exits + 18)->origin = (rooms + 8);
	(exits + 18)->destination = (rooms + 10);
	(exits + 18)->direction = east;
	//Thorny path to underwater cave
	(exits + 20)->name->string = "Thorny path";
	(exits + 20)->description->string = "many thorns, but nothing more";
	(exits + 20)->origin = (rooms + 8);
	(exits + 20)->destination = (rooms + 11);
	(exits + 20)->direction = south;
	//Home Base to jungle
	(exits + 22)->name->string = "Jungle path";
	(exits + 22)->description->string = "a huge jungle, probably full of beasts";
	(exits + 22)->origin = (rooms + 0);
	(exits + 22)->destination = (rooms + 12);
	(exits + 22)->direction = west;
	(exits + 22)->door = true;
	(exits + 22)->closed = true;

	///////////////////ITEMS///////////////////////
	(items + 0)->name->string = "Laser Gun";
	(items + 0)->description->string = "a powerfull large distance weapon";
	(items + 0)->location = (rooms + 0);

	(items + 0)->name->string =  "Gigant Rock";
	(items + 0)->description->string =  "It is very big but is on the brink of precipice sure You can push it";
	(items + 1)->location = (rooms + 1);
	(items + 1)->canTake = false;
	(items + 1)->canPush = true;
}


void World::getOperation(MyString ope[]){//list of possible operations
	if ((ope[0] == "north") || (ope[0] == "n")){
		ope[1] = "north";
		Go(ope);
		return;
	}
	else if ((ope[0] == "south") || (ope[0] == "s")){
		ope[1] = "south";
		Go(ope);
		return;
	}
	else if ((ope[0] == "east") || (ope[0] == "e")){
		ope[1] = "east";
		Go(ope);
		return;
	}
	else if ((ope[0] == "west") || (ope[0] == "w")){
		ope[1] = "west";
		Go(ope);
		return;
	}
	else if ((ope[0] == "go") || (ope[0] == "g")){
		Go(ope);
		return;
	}
	else if ((ope[0] == "look") || (ope[0] == "l")){
		Look(ope);
		return;
	}
	else if ((ope[0] == "open") || (ope[0] == "o")){
		Open(ope);
		return;
	}
	else if ((ope[0] == "help") || (ope[0] == "h")){
		Help();
		return;
	}

	else if ((ope[0] == "quit") || (ope[0] == "q")){
		return;
	}
	else{
		printf("wrong operation\n");
	}
}
int World::getDirection(MyString ope[]){//this defines the direction, if not found returns -1 and the program will exit
	if (((ope[1] == "north")) || ((ope[1] == "n"))){
		return 0;
	}
	if (((ope[1] == "south")) || ((ope[1] == "s"))){
		return 1;
	}
	if (((ope[1] == "east")) || ((ope[1] == "e"))){
		return 2;
	}
	if (((ope[1] == "west")) || ((ope[1] == "w"))){
		return 3;
	}
	return -1;
}

void World::Go(MyString operation[]){//this move the player if the move is possible
	int direction = -1;
	direction = getDirection(operation);//dat get the right direction
	if (direction == -1){
		printf("wrong operation\n");
		return;
	}
	else{
		for (int i = 0; i < NUM_EXITS; i++){

			if (exits[i].origin->name == player->location->name)
			{
				if (exits[i].direction == direction){//check if they have the same direction
					if (exits[i].closed == true){//check if the exit is closed
						printf("the door is closed\n");
						return;
					}
					else{
						player->location = exits[i].destination;//change your location
						printf("You are in %s, %s \n", player->location->name->string, player->location->description->string);
						return;
					}
				}
			}
		}
		printf("you can not pass\n");
	}
}
void World::Look(MyString operation[]){//this looks the exit if there is any
	int direction = -1;
	direction = getDirection(operation);//dat get the right direction
	if (direction == -1){
		printf("wrong operation\n");
		return;
	}
	for (int i = 0; i < NUM_EXITS; i++)
	{
		if (exits[i].origin->name == player->location->name)
		{
			if (exits[i].direction == direction){//check if they have the same direction
				printf("You see a %s and you see %s ", exits[i].name, exits[i].description);
				return;
			}
		}
	}
	printf("nothing here\n");


}

void World::Open(MyString operation[]){//this open the door if possible
	int direction = -1;
	direction = getDirection(operation);
	if (direction == -1){
		printf("wrong operation\n");
		return;
	}
	else{
		for (int i = 0; i < NUM_EXITS; i++){
			if (exits[i].origin->name == player->location->name)
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
void World::Close(MyString operation[]){//	this close the door if possible
	int direction = -1;
	direction = getDirection(operation);//dat get the right direction
	if (direction == -1){
		printf("wrong operation\n");
		return;
	}
	else{
		for (int i = 0; i < NUM_EXITS; i++){

			if (exits[i].origin->name == player->location->name)
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

