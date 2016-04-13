#include "World.h"
#define NUM_EXITS 24

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

	group.push_back(home);
	group.push_back(mountain);
	group.push_back(waterfall);
	group.push_back(abandonedCave);
	group.push_back(monsterCave);
	group.push_back(altar);
	group.push_back(bigNest);
	group.push_back(rubble);
	group.push_back(thornForest);
	group.push_back(thornForestWest);
	group.push_back(thornForestEast);
	group.push_back(underwaterCave);
	group.push_back(jungle);

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

	group.push_back(mountain_To_Home);
	group.push_back(altar_To_Home);
	group.push_back(jungle_To_Home);
	group.push_back(thorny_To_Home);
	group.push_back(home_To_Mountain);
	group.push_back(waterfall_To_Mountain);
	group.push_back(abandonedCave_To_Mountain);
	group.push_back(monsterCave_To_Mountain);
	group.push_back(mountain_To_Waterfall);
	group.push_back(rubble_To_Waterfall);
	group.push_back(mountain_To_AbandonedCave);
	group.push_back(mountain_To_MonsterCave);
	group.push_back(home_To_Altar);
	group.push_back(bigNest_To_Altar);
	group.push_back(altar_To_BigNest);
	group.push_back(bigNest_To_Rubble);
	group.push_back(home_To_Thorny);
	group.push_back(thornyWest_To_Thorny);
	group.push_back(thornyEast_To_Thorny);
	group.push_back(underwaterCave_To_Thorny);
	group.push_back(thorny_To_UnderwaterCave);
	group.push_back(thorny_To_ThornyEast);
	group.push_back(thorny_To_ThornyWest);
	group.push_back(home_To_Jungle);


	////////////////////////ITEMS///////////////////////
	Item* laserGun = new Item("Gun", "a powerfull large distance weapon", 5, 0, false, true, false, false, home);
	Item* bigRock = new Item("Rock", "It is very big but is on the brink of precipice sure You can push it", 0, 2, false, false, false, true, home);
	group.push_back(laserGun);
	group.push_back(bigRock);

	////////////////////////PLAYER//////////////////////

	Player* hero = new Player("Hero", "ieeje", 100, 5, 5);
	group.push_back(hero);

	hero->location = home;

}


void World::getOperation(Vector<MyString> &strings){//list of possible operations
	if ((strings.buffer[0] == "north") || (strings.buffer[0] == "n")){
		strings.buffer[1] = "north";
		//Go(ope);
		return;
	}
	else if ((strings.buffer[0] == "south") || (strings.buffer[0] == "s")){
		strings.buffer[1] = "south";
	//	Go(ope);
		return;
	}
	else if ((strings.buffer[0] == "east") || (strings.buffer[0] == "e")){
		strings.buffer[1] = "east";
		//Go(ope);
		return;
	}
	else if ((strings.buffer[0] == "west") || (strings.buffer[0] == "w")){
		strings.buffer[1] = "west";
		//Go(ope);
		return;
	}
	else if ((strings.buffer[0] == "go") || (strings.buffer[0] == "g")){
	//	Go(ope);
		return;
	}
	else if ((strings.buffer[0] == "look") || (strings.buffer[0] == "l")){
		//Look(ope);
		return;
	}
	else if ((strings.buffer[0] == "open") || (strings.buffer[0] == "o")){
	//	Open(ope);
		return;
	}
	else if ((strings.buffer[0] == "help") || (strings.buffer[0] == "h")){
		Help();
		return;
	}

	else if ((strings.buffer[0] == "quit") || (strings.buffer[0] == "q")){
		return;
	}
	else{
		printf("wrong operation\n");
	}
}
/*
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
*/

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

