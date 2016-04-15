#include "World.h"
#define NUM_EXITS 24
#define NUM_ITEMS 2
World::World()
{


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
void World::createWorld(){
	Room* home = new Room("Home Base", "this is your settlement.");
	Room* mountain = new Room("Mountain", "you're on the top of a mountain with a large rock at the edge of a precipice");
	Room* waterfall = new Room("Waterfall", "you are on the front of the waterfall, in the background can clearly see your robot AAR-88");
	Room* abandonedCave = new Room("Abandoned Cave", "there seems to be nothing , you only see a few rags and a pile of bones");
	Room* monsterCave = new Room("Monster Cave", "you can see a piece of your broken ship and you hear noises coming from the cave");
	Room* altar = new Room("Altar", "you are in a large open area and around you see a pile of bones");
	Room* bigNest = new Room("Big Nest", "you find yourself on top of a large tree along you see the biggest nest you've seen in your whole life, from there you see a vine down the north");
	Room* rubble = new Room("Rubble", "Rubble");
	Room* thornForest = new Room("Thorn Forest", "You can not see anything, you can move forward in any direction");
	Room* thornForestWest = new Room("Thorn Forest West", "You can not see anything, you do not see any exit");
	Room* thornForestEast = new Room("Thorn Forest East", "You can not see anything, you do not see any exit");
	Room* underwaterCave = new Room("Underwater Cave", "the ceiling of the cave have been destroyed by the impact of your ship probably");
	Room* jungle = new Room("Jungle", "you can hear many noises of beasts that you never heard");


	rooms.push_back(home);
	rooms.push_back(mountain);
	rooms.push_back(waterfall);
	rooms.push_back(abandonedCave);
	rooms.push_back(monsterCave);
	rooms.push_back(altar);
	rooms.push_back(bigNest);
	rooms.push_back(rubble);
	rooms.push_back(thornForest);
	rooms.push_back(thornForestWest);
	rooms.push_back(thornForestEast);
	rooms.push_back(underwaterCave);
	rooms.push_back(jungle);
	//////////////////////EXITS/////////////////////////////

	Exit* mountain_To_Home = new Exit("Rocky path", "your home base", false, false, mountain, home, SOUTH);
	Exit* altar_To_Home = new Exit("Little path", "your home base", false, false, altar, home, WEST);
	Exit* jungle_To_Home = new Exit("Little path", "your home base", false, false, jungle, home, EAST);
	Exit* thorny_To_Home = new Exit("Little path", "your home base", false, false, thornForest, home, NORTH);
	Exit* home_To_Mountain = new Exit("Rocky path", "a large mountain", false, false, home, mountain, NORTH);
	Exit* waterfall_To_Mountain = new Exit("Rocky path", "a large mountain", false, false, waterfall, mountain, WEST);
	Exit* abandonedCave_To_Mountain = new Exit("Rocky path", "a large mountain", false, false, abandonedCave, mountain, EAST);
	Exit* monsterCave_To_Mountain = new Exit("Rocky path", "a large mountain", false, false, monsterCave, mountain, SOUTH);
	Exit* mountain_To_Waterfall = new Exit("Rocky path", "a beautiful waterfall", false, false, mountain, waterfall, EAST);
	Exit* rubble_To_Waterfall = new Exit("vine path", "a waterfall down there, but you know you can not come back here", false, false, rubble, waterfall, WEST);
	Exit* mountain_To_AbandonedCave = new Exit("vine path", "a cave apparently abandoned", false, false, mountain, abandonedCave, WEST);
	Exit* mountain_To_MonsterCave = new Exit("Rocky path", "a cave, and many noises come from it", false, false, mountain, monsterCave, NORTH);
	Exit* home_To_Altar = new Exit("Little path", "a large open area, not appear to be dangerous zone", false, false, home, altar, EAST);
	Exit* bigNest_To_Altar = new Exit("Little path", "a large open area, not appear to be dangerous zone", false, false, bigNest, altar, WEST);
	Exit* altar_To_BigNest = new Exit("Little path", "a big tree, and on top a big nest", false, false, altar, bigNest, EAST);
	Exit* bigNest_To_Rubble = new Exit("vine path", "a rubble down there, but you know you can not come back here", false, false, bigNest, rubble, NORTH);
	Exit* home_To_Thorny = new Exit("Thorny path", "many thorns, but nothing more", false, false, home, thornForest, SOUTH);
	Exit* thornyWest_To_Thorny = new Exit("Thorny path", "many thorns, but nothing more", false, false, thornForestWest, thornForest, EAST);
	Exit* thornyEast_To_Thorny = new Exit("Thorny path", "many thorns, but nothing more", false, false, thornForestEast, thornForest, WEST);
	Exit* thorny_To_UnderwaterCave = new Exit("Thorny path", "many thorns, but nothing more", false, false, thornForest, underwaterCave, SOUTH);
	Exit* underwaterCave_To_Thorny = new Exit("Thorny path", "many thorns, but nothing more", false, false, underwaterCave, thornForest, NORTH);
	Exit* thorny_To_ThornyEast = new Exit("Thorny path", "many thorns, but nothing more", false, false, thornForest, thornForestEast, EAST);
	Exit* thorny_To_ThornyWest = new Exit("Thorny path", "many thorns, but nothing more", false, false, thornForest, thornForestWest, WEST);
	Exit* home_To_Jungle = new Exit("Jungle path", "a huge jungle, probably full of beasts", false, false, underwaterCave, thornForest, WEST);


	exits.push_back(mountain_To_Home);
	exits.push_back(altar_To_Home);
	exits.push_back(jungle_To_Home);
	exits.push_back(thorny_To_Home);
	exits.push_back(home_To_Mountain);
	exits.push_back(waterfall_To_Mountain);
	exits.push_back(abandonedCave_To_Mountain);
	exits.push_back(monsterCave_To_Mountain);
	exits.push_back(mountain_To_Waterfall);
	exits.push_back(rubble_To_Waterfall);
	exits.push_back(mountain_To_AbandonedCave);
	exits.push_back(mountain_To_MonsterCave);
	exits.push_back(home_To_Altar);
	exits.push_back(bigNest_To_Altar);
	exits.push_back(altar_To_BigNest);
	exits.push_back(bigNest_To_Rubble);
	exits.push_back(home_To_Thorny);
	exits.push_back(thornyWest_To_Thorny);
	exits.push_back(thornyEast_To_Thorny);
	exits.push_back(underwaterCave_To_Thorny);
	exits.push_back(thorny_To_UnderwaterCave);
	exits.push_back(thorny_To_ThornyEast);
	exits.push_back(thorny_To_ThornyWest);
	exits.push_back(home_To_Jungle);


	////////////////////////ITEMS///////////////////////
	Item* laserGun = new Item("Gun", "a powerfull large distance weapon", 5, 0, false, true, false, false, home, PICK);
	Item* bigRock = new Item("Rock", "It is very big but is on the brink of precipice sure You can push it", 0, 2, false, false, false, true, home, ENVIROMENT);
	items.push_back(laserGun);
	items.push_back(bigRock);

	////////////////////////PLAYER//////////////////////

	Player* hero = new Player("Hero", "ieeje", 100, 5, 5);
	player.push_back(hero);

	hero->location = home;

}


void World::getOperation(Vector<MyString> &strings){//list of possible operations
if ((strings[0] == "north") || (strings[0] == "n")){
		strings[1] = "north";
		Go(strings);
		return;
	}
	else if ((strings[0] == "south") || (strings[0] == "s")){
		strings[1] = "south";
		Go(strings);

		return;
	}
	else if ((strings[0] == "east") || (strings[0] == "e")){
		strings[1] = "east";
		Go(strings);

		return;
	}
	else if ((strings[0] == "west") || (strings[0] == "w")){
		strings[1] = "west";

		Go(strings);
		return;
	}
	else if ((strings[0] == "go") || (strings[0] == "g")){
		Go(strings);
		return;
	}
	else if ((strings[0] == "open") || (strings[0] == "o")){
		Open(strings);
		return;
	}
	else if ((strings[0] == "close") || (strings[0] == "c")){
		Close(strings);
		return;
	}
	else if ((strings[0] == "look") || (strings[0] == "l")){
		Look(strings);
		return;
	}
	else if ((strings[0] == "take") || (strings[0] == "t")){
		Take(strings);
		return;
	}
	else if ((strings[0] == "quit") || (strings[0] == "q")){
		return;
	}
	else{
		printf("wrong operation\n");
	}
}
int World::getDirection(Vector<MyString> &strings){//this defines the direction, if not found returns -1 and the program will exit
	if (((strings[1] == "north")) || ((strings[1] == "n"))){
		return 0;
	}
	if (((strings[1] == "south")) || ((strings[1] == "s"))){
		return 1;
	}
	if (((strings[1] == "east")) || ((strings[1] == "e"))){
		return 2;
	}
	if (((strings[1] == "west")) || ((strings[1] == "w"))){
		return 3;
	}
	return -1;
}

void World::Go(Vector<MyString> &strings){//this move the player if the move is possible
	int direction = -1;
	direction = getDirection(strings);//dat get the right direction
	if (direction == -1){

	}
	else{
		for (int i = 0; i < NUM_EXITS; i++){
			if (exits[i]->direction == direction)
			{
				if (exits[i]->origin->name == player[0]->location->name)
				{
					//check if they have the same direction
					if (exits[i]->closed == true){//check if the exit is closed
						printf("The door is closed\n");
						return;
					}
					else{
						player[0]->location = exits[i]->destination;//change your location
						Look();
						return;
					}
				}
			}
		}
		printf("You can not pass\n");
	}
}
void World::Look(Vector<MyString> &strings){//this move the player if the move is possible
	int direction = -1;
	direction = getDirection(strings);//dat get the right direction
	if (direction == -1){

		if (strings[1] == "here" || strings[1] == ""){
			player[0]->location->Look();
			return;
		}
		else if (strings[1] == "me")
		{
			player[0]->Look();
			return;

		}
		else if (strings[1] == "inventory"){
			for (int i = 0; i < inventory.size(); i++){
				inventory[i]->Look();
			}
		}
		else
		{
			for (int i = 0; i < NUM_ITEMS; i++)
			{
				if (items[i]->location->name == player[0]->location->name){
					if (strings[1] == items[i]->name){
						items[i]->Look();
						return;
					}
				}
			}
		}
	}
	else{
		for (int i = 0; i < NUM_EXITS; i++){
			if (exits[i]->direction == direction)
			{
				if (exits[i]->origin->name == player[0]->location->name)
				{
					exits[i]->Look();
					return;
				}
			}
		}
	}
	printf("You don't see nothing here\n");
}

void World::Look()const{
	player[0]->location->Look();
	for (int i = 0; i < NUM_ITEMS; i++)
	{
		if (items[i]->location->name == player[0]->location->name){
			if (items[i]->onInventory == false && items[i]->equiped == false){
				printf("You see a %s\n", items[i]->name);
			}
		}

	}
}
void World::Open(Vector<MyString> &strings){//this move the player if the move is possible
	int direction = -1;
	direction = getDirection(strings);//dat get the right direction
	if (direction == -1){
		printf("wrong operation\n");
		return;
	}
	else{
		for (int i = 0; i < NUM_EXITS; i++){
			if (exits[i]->direction == direction)
			{
				if (exits[i]->origin->name == player[0]->location->name)
				{
					//check if they have the same direction
					if (exits[i]->door == true){//check if the exit is closed
						if (exits[i]->closed == true){//check if the exit is closed
							exits[i]->closed = false;
							printf("the door is open\n");
							return;
						}
					}
					else{
						printf("is alredy opened");
						return;
					}
				}
			}
		}
		printf("you can not pass\n");
	}
}
void World::Close(Vector<MyString> &strings){//this move the player if the move is possible
	int direction = -1;
	direction = getDirection(strings);//dat get the right direction
	if (direction == -1){
		printf("wrong operation\n");
		return;
	}
	else{
		for (int i = 0; i < NUM_EXITS; i++){
			if (exits[i]->direction == direction)
			{
				if (exits[i]->origin->name == player[0]->location->name)
				{
					//check if they have the same direction
					if (exits[i]->door == true){//check if the exit is closed
						if (exits[i]->closed == false){//check if the exit is closed
							exits[i]->closed = true;
							printf("the door is closed\n");
							return;
						}
					}
					else{
						printf("is alredy closed");
						return;
					}
				}
			}
		}
		printf("you can not pass\n");
	}
}
void World::Take(Vector<MyString> &strings){//this move the player if the move is possible
	for (int j = 0; j < strings.size(); j++){
		for (int i = 0; i < NUM_ITEMS; i++)
		{
			if (items[i]->location->name == player[0]->location->name){
				if (strings[j] == items[i]->name){
					if (items[i]->isItem != ENVIROMENT && items[i]->onInventory == false){
						items[i]->onInventory = true;
						inventory.push_back(items[i]);
						printf("You take %s\n", items[i]->name);
					}
					else{
						printf("You can take %s\n", items[i]->name);
					}
				}
			}
		}
	}
}

void World::Drop(Vector<MyString> &strings){//this move the player if the move is possible
	for (int j = 0; j < strings.size(); j++){
		for (int i = 0; i < inventory.size(); i++)
		{
			if (strings[j] == inventory[i]->name){
				if (inventory[i]->equiped == false){

					inventory[i]->onInventory = false;
					inventory[i]->location = player[0]->location;
					printf("You drop %s\n", inventory[i]->name);
					inventory.clean_selected(i);
				}
				else{
					printf("You can not throw a equipped object");
				}
			}
		}
	}
}
void World::Equip(Vector<MyString> &strings){//this move the player if the move is possible
	for (int j = 0; j < strings.size(); j++){
		for (int i = 0; i < inventory.size(); i++)
		{
			if (strings[j] == inventory[i]->name){
				if (items[i]->isItem == BOOTS || items[i]->isItem == ARMOR || items[i]->isItem == WEAPON){
					if (items[i]->equiped == false){
						inventory[i]->equiped = true;
						player[0]->atack += inventory[i]->atack;
						player[0]->defense += inventory[i]->defense;
						printf("You equiped %s\n", inventory[i]->name);
						return;
					}
					else{
						printf("Already was equipped");
						return;
					}
				}
			}
		}
	}
}
void World::UnEquip(Vector<MyString> &strings){//this move the player if the move is possible
	for (int j = 0; j < strings.size(); j++){
		for (int i = 0; i < inventory.size(); i++)
		{
			if (strings[j] == inventory[i]->name){
				if (items[i]->isItem == BOOTS || items[i]->isItem == ARMOR || items[i]->isItem == WEAPON){
					if (items[i]->equiped == true){
						inventory[i]->equiped = false;
						player[0]->atack -= inventory[i]->atack;
						player[0]->defense -= inventory[i]->defense;
						printf("You have taken away %s\n", inventory[i]->name);
						return;
					}
					else{
						printf("You do not have this object equipped");
						return;
					}
				}
			}
		}
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

}

