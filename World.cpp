#include "World.h"

World::World()
{}
World::~World()
{

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


	container.push_back(home);
	container.push_back(mountain);
	container.push_back(waterfall);
	container.push_back(abandonedCave);
	container.push_back(monsterCave);
	container.push_back(altar);
	container.push_back(bigNest);
	container.push_back(rubble);
	container.push_back(thornForest);
	container.push_back(thornForestWest);
	container.push_back(thornForestEast);
	container.push_back(underwaterCave);
	container.push_back(jungle);
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


	container.push_back(mountain_To_Home);
	container.push_back(altar_To_Home);
	container.push_back(jungle_To_Home);
	container.push_back(thorny_To_Home);
	container.push_back(home_To_Mountain);
	container.push_back(waterfall_To_Mountain);
	container.push_back(abandonedCave_To_Mountain);
	container.push_back(monsterCave_To_Mountain);
	container.push_back(mountain_To_Waterfall);
	container.push_back(rubble_To_Waterfall);
	container.push_back(mountain_To_AbandonedCave);
	container.push_back(mountain_To_MonsterCave);
	container.push_back(home_To_Altar);
	container.push_back(bigNest_To_Altar);
	container.push_back(altar_To_BigNest);
	container.push_back(bigNest_To_Rubble);
	container.push_back(home_To_Thorny);
	container.push_back(thornyWest_To_Thorny);
	container.push_back(thornyEast_To_Thorny);
	container.push_back(underwaterCave_To_Thorny);
	container.push_back(thorny_To_UnderwaterCave);
	container.push_back(thorny_To_ThornyEast);
	container.push_back(thorny_To_ThornyWest);
	container.push_back(home_To_Jungle);


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
	Item* trunk = new Item("Trunk", "it is spacious and seems to fit everything", NULL, NULL, false, false, false, home, TRUNK);//I decided that it can not move , but if you change "canTake" to true you can move and work fine

	container.push_back(laserGun);
	container.push_back(bigRock);
	container.push_back(powerArmor);
	container.push_back(jumpBoots);
	container.push_back(fuel);
	container.push_back(antenna);
	container.push_back(core);
	container.push_back(transmitter);
	container.push_back(robot);
	container.push_back(trunk);


	////////////////////////PLAYER//////////////////////

	Player* hero = new Player("Hero", "ieeje", 100, 5, 5);
	container.push_back(hero);
	for (int i = 0; i < container.size(); i++){
		if (container[i]->isType == PLAYER){
			((Player*)container[i])->location = home;

		}
	}
}


void World::getOperation(Vector<MyString> &strings){//list of possible operations
if ((strings[0] == "north") || (strings[0] == "n")){
		strings[1] = "north";
		hero->Go(strings);
		return;
	}
	else if ((strings[0] == "south") || (strings[0] == "s")){
		strings[1] = "south";
		hero->Go(strings);

		return;
	}
	else if ((strings[0] == "east") || (strings[0] == "e")){
		strings[1] = "east";
		hero->Go(strings);

		return;
	}
	else if ((strings[0] == "west") || (strings[0] == "w")){
		strings[1] = "west";

		hero->Go(strings);
		return;
	}
	else if ((strings[0] == "go") || (strings[0] == "g")){
		hero->Go(strings);
		return;
	}
	else if ((strings[0] == "open") || (strings[0] == "o")){
		hero->Open(strings);
		return;
	}
	else if ((strings[0] == "close") || (strings[0] == "c")){
		hero->Close(strings);
		return;
	}
	else if ((strings[0] == "look") || (strings[0] == "l")){
		hero->Look(strings);
		return;
	}
	else if ((strings[0] == "take") || (strings[0] == "t")){
		hero->Take(strings);
		return;
	}
	else if ((strings[0] == "drop") || (strings[0] == "d")){
		hero->Drop(strings);
		return;
	}
	else if ((strings[0] == "equip")){
		hero->Equip(strings);
		return;
	}
	else if ((strings[0] == "unequip")){
		hero->UnEquip(strings);
		return;
	}
	else if ((strings[0] == "push") || (strings[0] == "p")){
		hero->Push(strings);
		return;
	}
	else if ((strings[0] == "put") && (strings[2] == "into")){
		hero->PutInto(strings);
	
		return;
	}

	else if ((strings[0] == "get") && (strings[2] == "from")){
		hero->GetFrom(strings);

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

