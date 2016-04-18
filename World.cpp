#include "World.h"

World::World()
{}
World::~World()
{
	for (int i = 0; i < player.size(); i++){
		delete player[i];
	}
	for (int i = 0; i < rooms.size(); i++){
		delete rooms[i];
	}
	for (int i = 0; i < items.size(); i++){
		for (int j = 0; i < items[i]->trunk.size(); j++){
			delete items[i]->trunk[j];
		}
	}
	for (int i = 0; i < items.size(); i++){
			delete items[i];
	}

	for (int i = 0; i < inventory.size(); i++){
		delete inventory[i];
	}
	for (int i = 0; i < exits.size(); i++){
		delete exits[i];
	}
}
void World::createWorld(){
	

	Room* home = new Room("Home Base", "this is your settlement.");
	Room* mountain = new Room("Mountain", "you're on the top of a mountain with a large rock at the edge of a precipice");
	Room* waterfall = new Room("Waterfall", "you are on the front of the waterfall");
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
	Exit* home_To_Mountain = new Exit("Rocky path", "a large mountain", true, true, home, mountain, NORTH);
	Exit* waterfall_To_Mountain = new Exit("Rocky path", "a large mountain", false, false, waterfall, mountain, WEST);
	Exit* abandonedCave_To_Mountain = new Exit("Rocky path", "a large mountain", false, false, abandonedCave, mountain, EAST);
	Exit* monsterCave_To_Mountain = new Exit("Rocky path", "a large mountain", false, false, monsterCave, mountain, SOUTH);
	Exit* mountain_To_Waterfall = new Exit("Rocky path", "a beautiful waterfall", false, false, mountain, waterfall, EAST);
	Exit* rubble_To_Waterfall = new Exit("vine path", "a waterfall down there, but you know you can not come back here", false, false, rubble, waterfall, WEST);
	Exit* mountain_To_AbandonedCave = new Exit("vine path", "a cave apparently abandoned", false, false, mountain, abandonedCave, WEST);
	Exit* mountain_To_MonsterCave = new Exit("Rocky path", "a cave, and many noises come from it", false, false, mountain, monsterCave, NORTH);
	Exit* home_To_Altar = new Exit("Little path", "a large open area, not appear to be dangerous zone", true, true, home, altar, EAST);
	Exit* bigNest_To_Altar = new Exit("Little path", "a large open area, not appear to be dangerous zone", false, false, bigNest, altar, WEST);
	Exit* altar_To_BigNest = new Exit("Little path", "a big tree, and on top a big nest", false, false, altar, bigNest, EAST);
	Exit* bigNest_To_Rubble = new Exit("vine path", "a rubble down there, but you know you can not come back here", false, false, bigNest, rubble, NORTH);
	Exit* home_To_Thorny = new Exit("Thorny path", "many thorns, but nothing more", true, true, home, thornForest, SOUTH);
	Exit* thornyWest_To_Thorny = new Exit("Thorny path", "many thorns, but nothing more", false, false, thornForestWest, thornForest, EAST);
	Exit* thornyEast_To_Thorny = new Exit("Thorny path", "many thorns, but nothing more", false, false, thornForestEast, thornForest, WEST);
	Exit* thorny_To_UnderwaterCave = new Exit("Thorny path", "many thorns, but nothing more", false, false, thornForest, underwaterCave, SOUTH);
	Exit* underwaterCave_To_Thorny = new Exit("Thorny path", "many thorns, but nothing more", false, false, underwaterCave, thornForest, NORTH);
	Exit* thorny_To_ThornyEast = new Exit("Thorny path", "many thorns, but nothing more", false, false, thornForest, thornForestEast, EAST);
	Exit* thorny_To_ThornyWest = new Exit("Thorny path", "many thorns, but nothing more", false, false, thornForest, thornForestWest, WEST);
	Exit* home_To_Jungle = new Exit("Jungle path", "a huge jungle, probably full of beasts", false, false, home, jungle, WEST);


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
	Item* laserGun = new Item("Gun", "a powerfull large distance weapon", 5, 0, false, true,  false, thornForestWest, WEAPON);
	Item* bigRock = new Item("Rock", "It is very big but is on the brink of precipice sure You can push it", NULL, NULL, false, false,  true, mountain, ENVIROMENT);
	Item* powerArmor = new Item("Armor", "a powerful power armor, you will be more safe with this", 0, 5, false, true,  false, abandonedCave, ARMOR);
	Item* jumpBoots = new Item("Boots", "a stunning jump boots, with it you can move faster", 1, 1, false, true,  false, rubble, BOOTS);
	Item* fuel = new Item("Fuel", "a container fuel, could be useful", NULL, NULL, false, true,  false, thornForestEast, PICK);
	Item* antenna = new Item("Antenna", "with this the beacon signal reached everywhere", NULL, NULL, false, true,  false, underwaterCave, PICK);
	Item* core = new Item("Core", "a energy core, this will give power to the beacon", NULL, NULL, false, true,  false, bigNest, PICK);
	Item* transmitter = new Item("Transmitter", "with this transmitter you can send a help message", NULL, NULL, false, true,  false, monsterCave, PICK);
	Item* robot = new Item("Robot", "at the bottom of the waterfall you can see your assistant robot, it would be helpful but due to the strong current of water is impossible to remove you if something stop the waterfall...", NULL, NULL, false, false, false, waterfall, PICK);
	Item* trunk = new Item("Trunk", "it is spacious and seems to fit everything", NULL, NULL, false, false, false, home, TRUNK);

	items.push_back(laserGun);
	items.push_back(bigRock);
	items.push_back(powerArmor);
	items.push_back(jumpBoots);
	items.push_back(fuel);
	items.push_back(antenna);
	items.push_back(core);
	items.push_back(transmitter);
	items.push_back(robot);
	items.push_back(trunk);


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
	else if ((strings[0] == "drop") || (strings[0] == "d")){
		Drop(strings);
		return;
	}
	else if ((strings[0] == "equip")){
		Equip(strings);
		return;
	}
	else if ((strings[0] == "unequip")){
		UnEquip(strings);
		return;
	}
	else if ((strings[0] == "push") || (strings[0] == "p")){
		Push(strings);
		return;
	}
	else if ((strings[0] == "put") && (strings[2] == "into")){
			PutInto(strings);
	
		return;
	}

	else if ((strings[0] == "get") && (strings[2] == "from")){
		GetFrom(strings);

		return;
	}
	else if ((strings[0] == "help") || (strings[0] == "h")){
		Help();
		return;
	}
	else if (strings[0] == "quit"){
		return;
	}
	
	else{
		printf("wrong operation\n");
	}
}
int World::getDirection(Vector<MyString> &strings){//this defines the direction, if not found returns -1 and the program will exit
	int i = 0;
	do{
		if (((strings[i] == "north")) || ((strings[i] == "n"))){
			return 0;
		}
		else if (((strings[i] == "south")) || ((strings[i] == "s"))){
			return 1;
		}
		else if (((strings[i] == "east")) || ((strings[i] == "e"))){
			return 2;
		}
		else if (((strings[i] == "west")) || ((strings[i] == "w"))){
			return 3;
		}
		else{
			i++;
		}
	} while (i < strings.size());
	return -1;
}

void World::Go(Vector<MyString> &strings){//this move the player if the move is possible
	int direction = -1;
	direction = getDirection(strings);//dat get the right direction
	if (direction == -1){
		printf("wrong operation\n");
		return;
	}
	else{
		for (int i = 0; i < exits.size(); i++){
			if (exits[i]->direction == direction && exits[i]->origin->name.C_Str() == player[0]->location->name.C_Str()){
					if (exits[i]->closed == true){//check if the exit is closed
						if (exits[i]->door == true){//check if the exit is closed
							printf("the door is closed\n");
							return;
						}
						else{
							printf("You can not pass, is bloqued\n");
							return;
						}
					}
					else{
						player[0]->location = exits[i]->destination;//change your location
						for (int i = 0; i < inventory.size(); i++){
							inventory[i]->location = player[0]->location;
						}
						Look();
						return;
					
				}
			}
		}
		printf("You can not pass\n");
	}
}
void World::Look(Vector<MyString> &strings){
	int direction = -1;
	direction = getDirection(strings);//dat get the right direction
	if (direction == -1){
		if (strings[1] == "here" || strings[1] == ""){//LOCK ROOM
			player[0]->location->Look();
			return;
		}
		else if (strings[1] == "hero"){//LOOK HERO STATS
			if (strings[2] == "stats"){
				player[0]->Stats();
			}
			else{
				player[0]->Look();//LOOK HERO 
			}
			return;
		}
		else if (strings[1] == "inventory"){//LOOK ALL INVENTORY
			for (int i = 0; i < inventory.size(); i++){
				inventory[i]->Look();
				printf("\n");
			}
		}
		else if (strings[1] == "inside"){//LOOK INSIDE TRUNK ITEMS
			for (int i = 0; i < items.size(); i++){
				if (items[i]->location->name == player[0]->location->name && strings[2] == items[i]->name && items[i]->isItem == TRUNK){
					if (items[i]->trunk.size()>0){
						printf("Inside %s you see:\n", items[i]->name.C_Str());
						for (int j = 0; j < items[i]->trunk.size(); j++){
							printf("%s\n", items[i]->trunk[j]->name.C_Str());
						}
					}
					else{
						printf("is empty\n");
					}
				}
			}
			return;
			}
		
		else{
			for (int i = 0; i < items.size(); i++){//LOOK SPECIFIC OBJECTS(no inventory items)
				if (items[i]->location->name == player[0]->location->name){
					if (strings[1] == items[i]->name){
						if (strings[2] == "stats"){
							if (items[i]->isType == ARMOR || items[i]->isType == WEAPON || items[i]->isType == BOOTS) {
								items[i]->Stats();
							}						
							else{
								printf("this item don't have stats");
							}
						}
						else{
							items[i]->Look();
						}
						return;
					}
				}
			}
			for (int i = 0; i < inventory.size(); i++){//LOOK SPECIFIC OBJECTS(iventory items)
				if (inventory[i]->location->name == player[0]->location->name){
					if (strings[1] == inventory[i]->name){
						if (strings[2] == "stats"){
							if (inventory[i]->isType == ARMOR || inventory[i]->isType == WEAPON || inventory[i]->isType == BOOTS) {
								inventory[i]->Stats();
							}
							else{
								printf("this item don't have stats");
							}
						}
						else{
							inventory[i]->Look();
						}
						return;
					}
				}
			}
		}
	}
	else{//LOOK EXITS
		for (int i = 0; i < exits.size(); i++){
			if (exits[i]->direction == direction){
				if (exits[i]->origin->name == player[0]->location->name){
					exits[i]->Look();
					return;
				}
			}
		}
	}
	printf("You don't see nothing here\n");
}

void World::Look()const{//LOOK CURRENT ROOM AND HIS ITEMS
	player[0]->location->Look();
	for (int i = 0; i < items.size(); i++){
		if (items[i]->location->name == player[0]->location->name){
				printf("You see a %s\n", items[i]->name);
			
		}
	}
}
void World::Open(Vector<MyString> &strings){
	int direction = -1;
	direction = getDirection(strings);//dat get the right direction
	if (direction == -1){
		printf("wrong operation\n");
		return;
	}
	else{
		for (int i = 0; i < exits.size(); i++){
			if (exits[i]->direction == direction && exits[i]->origin->name == player[0]->location->name){//check if they have the same direction
				if (exits[i]->door == true){//check if the exit is closed
					if (exits[i]->closed == true){//check if the exit is closed
						exits[i]->closed = false;
						printf("the door is open\n");
						return;
					}
				}
				else{
					printf("is alredy opened\n");
					return;
				}
				
			}
		}
		printf("you can not pass\n");
	}
}
void World::Close(Vector<MyString> &strings){
	int direction = -1;
	direction = getDirection(strings);//dat get the right direction
	if (direction == -1){
		printf("wrong operation\n");
		return;
	}
	else{
		for (int i = 0; i < exits.size(); i++){
			if (exits[i]->direction == direction && exits[i]->origin->name == player[0]->location->name){//check if they have the same direction			
				if (exits[i]->door == true){//check if the exit is closed
					if (exits[i]->closed == false){//check if the exit is closed
						exits[i]->closed = true;
						printf("the door is closed\n");
						return;
					}
				}
				else{
					printf("is alredy closed\n");
					return;
				}
				
			}
		}
		printf("you can not pass\n");
	}
}
void World::Take(Vector<MyString> &strings){//TAKE OBJECTS
		for (int i = 0; i < items.size(); i++){
			if (items[i]->location->name == player[0]->location->name && strings[1] == items[i]->name){			
				if (items[i]->isItem != ENVIROMENT &&items[i]->canTake==true){//Check if is enviroment item and if you can take
					inventory.push_back(items[i]);
					printf("You take %s\n", items[i]->name);
					items.clean_selected(i);
				}
				else{
					printf("You can't take %s\n", items[i]->name);
				}				
			}
		}
	}


void World::Drop(Vector<MyString> &strings){
		for (int i = 0; i < inventory.size(); i++){
			if (strings[1] == inventory[i]->name){//Look if you have this item on you inventory
				if (inventory[i]->equiped == false){
					items.push_back(inventory[i]);//drop item on current room
					inventory[i]->location = player[0]->location;
					printf("You drop %s\n", inventory[i]->name);
					inventory.clean_selected(i);//delete item on inventory
				}
				else{
					printf("You can not throw a equipped object\n");
				}
			}
		}
	}

void World::Equip(Vector<MyString> &strings){
		for (int i = 0; i < inventory.size(); i++)
		{
			if (strings[1] == inventory[i]->name && items[i]->isItem == BOOTS || items[i]->isItem == ARMOR || items[i]->isItem == WEAPON){
				if (items[i]->equiped == false){//equip and items give you stats
					inventory[i]->equiped = true;
					player[0]->atack += inventory[i]->atack;
					player[0]->defense += inventory[i]->defense;
					printf("You equiped %s\n", inventory[i]->name);
					return;
				}
				else{
					printf("Already was equipped\n");
					return;
				}				
			}
		}
	}

void World::UnEquip(Vector<MyString> &strings){
		for (int i = 0; i < inventory.size(); i++)
		{
			if (strings[1] == inventory[i]->name && inventory[i]->isItem == BOOTS || items[i]->isItem == ARMOR || items[i]->isItem == WEAPON){
				if (inventory[i]->equiped == true){//unequip and lost stats
					inventory[i]->equiped = false;
					player[0]->atack -= inventory[i]->atack;
					player[0]->defense -= inventory[i]->defense;
					printf("You have taken away %s\n", inventory[i]->name);
					return;
				}
				else{
					printf("You do not have this object equipped\n");
					return;
				}
			}
		}
	}

void World::Push(Vector<MyString> &strings){
		for (int i = 0; i < items.size(); i++){
			if (items[i]->location->name == player[0]->location->name){
			if (strings[1] == items[i]->name && items[i]->isItem == ENVIROMENT && items[i]->canPush == true){//check if is enviroment item (only rock is enviroment)
				int direction = -1;
				direction = getDirection(strings);//dat get the direction you push
				if (direction == -1){
					printf("wrong direction.\n");
					return;
				}
				for (int j = 0; j < exits.size(); j++){
					if (exits[j]->direction == direction&&exits[j]->origin->name == player[0]->location->name){//check if they have the same direction
						items[i]->location = exits[j]->destination;//change your location
							if (items[i]->location->name == "Abandoned Cave"){
								printf("You have blocked the entrance to the Abandoned cave\n");
								for (int j = 0; j < exits.size(); j++){//BLOCK EXIT
									if (items[i]->location == exits[j]->origin){
										exits[j]->closed = true;//block the exit
										items[i]->canPush = false;
									}
								}
							}
							else if (items[i]->location->name == "Monster Cave"){
								printf("the big rock block the cave\n");
								items[i]->description = "The big rock now block the cave";//change description of the item
								items[i]->canPush = false;
								//this blocks the fight against the monster (monsters not implemented)
							}
							else if (items[i]->location->name == "Waterfall"){
								printf("the big rock block the water\n");
								items[i]->description = "The big rock now block the water";//change description of the item
								for (int j = 0; j < items.size(); j++){//ITEM robot now we can take
									if (items[i]->location == items[j]->location && items[j]->name == "Robot"){
										items[j]->canTake = true;
										items[j]->description = "this robot is in perfect condition";//block the exit
									}
								}
								items[i]->canPush = false;
							}
							else{
								printf("You have blocked the entrance to your base, congratulations you have committed suicide\n");
								for (int j = 0; j < exits.size(); j++){//BLOCK EXIT
									if (items[i]->location == exits[j]->destination){
										exits[j]->closed = true;//block the exit
									}
								}
								items[i]->canPush = false;
							}
						}
					}

				}
					else{
						printf("You can't push %s\n\n", items[i]->name);
					}
				}
			}
		}
	

void World::PutInto(Vector<MyString> &strings){
		for (int j = 0; j < inventory.size(); j++){
			if (strings[1] == inventory[j]->name){
				if (inventory[j]->equiped == false){
					for (int i = 0; i < items.size(); i++){
						if (items[i]->isItem == TRUNK && items[i]->location == player[0]->location){
							items[i]->trunk.push_back(inventory[j]);//put item on trunk
							printf("You put %s into %s\n", inventory[j]->name.C_Str(), items[i]->name.C_Str());
							inventory.clean_selected(j);//delete item from inventory
							return;
						}
					}
				}
			
				else{
				printf("You can not put a equipped object\n");
				}
			}
		}
		printf("There is no trunk in the floor to perform this action.\n");
}
void World::GetFrom(Vector<MyString> &strings){//Get items froms trunk
	for (int i = 0; i < items.size(); i++){
		if (items[i]->isItem == TRUNK && items[i]->location == player[0]->location){//check if is trunk item
			for (int j = 0; j < items[i]->trunk.size(); j++){
				if (strings[1] == items[i]->trunk[j]->name){
					inventory.push_back(items[i]->trunk[j]);//put item on inventory
					printf("You get %s from %s\n", items[i]->trunk[j]->name.C_Str(), items[i]->name.C_Str());
					items[i]->trunk.clean_selected(j);//delete item from trunk
					return;
				}
			}
		}
	}
	printf("There is no trunk in the floor to perform this action.\n");
}
void World::Help()const{
	printf("This is Zork S.O.S No man's land");
	printf("Your ship has crashed on an unknown planet,\nyou must retrieve the necessary parts of your destroyed ship scattered around the area and build a beacon for help, your resources are limited and will have to find more to survive.\n\n");
	printf("You can move using the comand Go North G North, North or N\n");
	printf("You can look using the command Look North, Look N or L N (You can look your hero or items).\n");
	printf("You can open/close using the command Open/Close North, Open/Close N or O/C N.\n");
	printf("You can equip/unequip items using the command Equip/Unequip.\n");
	printf("You can take/drop items using the command Take/Drop, T/D.\n");
	printf("You can put/get items into/from trunk using the command Put/Get<ITEM>Into/From.\n");
	printf("You can push items using the command Push <ITEM> to North.\n");
	printf("You can quit the program using the command Quit.\n");
	printf("for more information look README and use Help command for show this text again\n");

	printf("(or any other direction using the same structure), don't worry about case sensitive\n\n");

}

