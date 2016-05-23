#include "World.h"



Player::Player()
{

}
Player::Player(const char* name, const char* description, int life, int atack, int armor) :Creature(name, description,life,atack,armor)
{
	isType = PLAYER;
}

Player::~Player()
{
}
void Player::Stats()const{
	printf("You have %i hp, %i atack and %i defense\n", life, atack, armor);
}




void Player::Go(Vector<MyString> &strings){//this move the player if the move is possible
	int direction = -1;
	direction = App->getDirection(strings);//dat get the right direction
	if (direction == -1){
		printf("wrong operation\n");
		return;
	}
	else{
		for (int i = 0; i < App->container.size(); i++){
			if (App->container[i]->isType == EXIT){
				if (((Exit*)App->container[i])->direction==direction && ((Exit*)App->container[i])->origin->name.C_Str() == location->name.C_Str()){
					if (((Exit*)App->container[i])->closed == true){//check if the exit is closed
						if (((Exit*)App->container[i])->door == true){//check if the exit is closed
							printf("the door is closed\n");
							return;
						}
						else{
							printf("You can not pass, is bloqued\n");
							return;
						}
					}
					else{
						location = ((Exit*)App->container[i])->destination;//change your location
						for (int i = 0; i < inventory.size(); i++){
							inventory[i]->location = location;
						}
						Look();
						return;

					}
				}

			}
		}
		printf("You can not pass\n");
	}
}
void Player::Look()const{//LOOK CURRENT ROOM AND HIS ITEMS
	printf("You are in a %s, %s \n", location->name.C_Str(),location->description.C_Str());
	for (int i = 0; i < App->container.size(); i++){
		if (App->container[i]->isType == PLAYER){
			if (!((Player*)App->container[i])->location->list.empty()){
					for (int j = 0;j< ((Player*)App->container[i])->location->list.size(); j++){
						//printf("You see a %s\n", ((Player*)App->container[i])->location->list.);
					}
				}

			}
		}
	}


void Player::Look(Vector<MyString> &strings){
	int direction = -1;
	direction =App->getDirection(strings);//dat get the right direction
	if (direction == -1){
		if (strings[1] == "here" || strings[1] == ""){//LOCK ROOM
			location->Look();
			return;
		}
		else if (strings[1] == "hero"){//LOOK HERO STATS
			if (strings[2] == "stats"){
				Stats();
			}
			else{
				Look();//LOOK HERO 
			}
			return;
		}
		else if (strings[1] == "inventory"){//LOOK ALL INVENTORY
			for (int i = 0; i < inventory.size(); i++){
				printf("Inside inventory you see:\n");
				inventory[i]->Look();
				printf("\n");
			}
			return;
		}
		else if (strings[1] == "inside"){//LOOK INSIDE TRUNK ITEMS
			for (int i = 0; i < App->container.size(); i++){
				if (App->container[i]->isType == ITEM){
					if (((Item*)App->container[i])->location->name == location->name && strings[2] == ((Item*)App->container[i])->name && ((Item*)App->container[i])->isItem == TRUNK){
						if (((Item*)App->container[i])->trunk.size()>0){
							printf("Inside %s you see:\n", ((Item*)App->container[i])->name.C_Str());
							for (int j = 0; j < ((Item*)App->container[i])->trunk.size(); j++){
								printf("%s\n", ((Item*)App->container[i])->trunk[j]->name.C_Str());
							}
						}
						else{
							printf("is empty\n");
						}
					}
				}
			}
			return;
		}

		else{
			for (int i = 0; i < App->container.size(); i++){//LOOK SPECIFIC OBJECTS(no inventory items)
				if (App->container[i]->isType == ITEM){

					if (((Item*)App->container[i])->location->name == location->name){
						if (strings[1] == ((Item*)App->container[i])->name){
							if (strings[2] == "stats"){
								if (((Item*)App->container[i])->isType == ARMOR || ((Item*)App->container[i])->isType == WEAPON || ((Item*)App->container[i])->isType == BOOTS) {
									((Item*)App->container[i])->Stats();
								}
								else{
									printf("this item don't have stats");
								}
							}
							else{
								((Item*)App->container[i])->Look();
							}
							return;
						}
					}
				}
			}
			for (int i = 0; i < inventory.size(); i++){//LOOK SPECIFIC OBJECTS(iventory items)
				if (inventory[i]->location->name == location->name){
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
		for (int i = 0; i < App->container.size(); i++){
			if (App->container[i]->isType == EXIT){

				if (((Exit*)App->container[i])->direction == direction){
					if (((Exit*)App->container[i])->origin->name == location->name){
						((Exit*)App->container[i])->Look();
						return;
					}
				}
			}
		}
	}
	printf("You don't see nothing here\n");
}

void Player::Open(Vector<MyString> &strings){
	int direction = -1;
	direction = App->getDirection(strings);//dat get the right direction
	if (direction == -1){
		printf("wrong operation\n");
		return;
	}
	else{
		for (int i = 0; i < App->container.size(); i++){
			if (App->container[i]->isType == EXIT){

				if (((Exit*)App->container[i])->direction == direction && ((Exit*)App->container[i])->origin->name == location->name){//check if they have the same direction
					if (((Exit*)App->container[i])->door == true){//check if the exit is closed
						if (((Exit*)App->container[i])->closed == true){//check if the exit is closed
							((Exit*)App->container[i])->closed = false;
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
		}
		printf("you can not pass\n");
	}
}
void Player::Close(Vector<MyString> &strings){
	int direction = -1;
	direction = App->getDirection(strings);//dat get the right direction
	if (direction == -1){
		printf("wrong operation\n");
		return;
	}
	else{
		for (int i = 0; i < App->container.size(); i++){
			if (App->container[i]->isType == EXIT){

				if (((Exit*)App->container[i])->direction == direction && ((Exit*)App->container[i])->origin->name == location->name){//check if they have the same direction			
					if (((Exit*)App->container[i])->door == true){//check if the exit is closed
						if (((Exit*)App->container[i])->closed == false){//check if the exit is closed
							((Exit*)App->container[i])->closed = true;
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
		}
		printf("you can not pass\n");
	}
}
void Player::Take(Vector<MyString> &strings){//TAKE OBJECTS
	for (int i = 0; i < App->container.size(); i++){
		if (App->container[i]->isType == ITEM){

			if (((Item*)App->container[i])->location->name == location->name && strings[1] == ((Item*)App->container[i])->name){
				if (((Item*)App->container[i])->isItem != ENVIROMENT && ((Item*)App->container[i])->canTake == true){//Check if is enviroment item and if you can take
					inventory.push_back(((Item*)App->container[i]));
					printf("You take %s\n", ((Item*)App->container[i])->name);
				//	contai.clean_selected(i); end erase
				}
				else{
					printf("You can't take %s\n", ((Item*)App->container[i])->name);
				}
			}
		}
	}
}


void Player::Drop(Vector<MyString> &strings){
	for (int i = 0; i < App->container.size(); i++){
		if (strings[1] == inventory[i]->name){//Look if you have this item on you inventory
			if (inventory[i]->equiped == false){
				//items.push_back(inventory[i]);//drop item on current room
				inventory[i]->location = location;
				printf("You drop %s\n", inventory[i]->name);
				inventory.clean_selected(i);//delete item on inventory
			}
			else{
				printf("You can not throw a equipped object\n");
			}
		}
	}
}

void Player::Equip(Vector<MyString> &strings){
	for (int i = 0; i < inventory.size(); i++)
	{
		if (strings[1] == inventory[i]->name && inventory[i]->isItem == BOOTS || inventory[i]->isItem == ARMOR || inventory[i]->isItem == WEAPON){
			if (inventory[i]->equiped == false){//equip and items give you stats
				inventory[i]->equiped = true;
				atack += inventory[i]->atack;
				armor += inventory[i]->defense;
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

void Player::UnEquip(Vector<MyString> &strings){
	for (int i = 0; i < inventory.size(); i++)
	{
		if (strings[1] == inventory[i]->name && inventory[i]->isItem == BOOTS || inventory[i]->isItem == ARMOR || inventory[i]->isItem == WEAPON){
			if (inventory[i]->equiped == true){//unequip and lost stats
				inventory[i]->equiped = false;
				atack -= inventory[i]->atack;
				armor -= inventory[i]->defense;
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

void Player::Push(Vector<MyString> &strings){
	for (int i = 0; i < App->container.size(); i++){
		if (App->container[i]->isType == ITEM){

			if (((Item*)App->container[i])->location->name == location->name){
				if (strings[1] == ((Item*)App->container[i])->name && ((Item*)App->container[i])->isItem == ENVIROMENT && ((Item*)App->container[i])->canPush == true){//check if is enviroment item (only rock is enviroment)
					int direction = -1;
					direction = App->getDirection(strings);//dat get the direction you push
					if (direction == -1){
						printf("wrong direction.\n");
						return;
					}
					for (int j = 0; j < App->container.size(); j++){
						if (App->container[i]->isType == EXIT){
							if (((Exit*)App->container[j])->direction == direction && ((Exit*)App->container[j])->origin->name == location->name){//check if they have the same direction
								((Item*)App->container[i])->location = ((Exit*)App->container[j])->destination;//change your location
								if (((Item*)App->container[i])->location->name == "Abandoned Cave"){
									printf("You have blocked the entrance to the Abandoned cave\n");
									for (int j = 0; j < App->container.size(); j++){//BLOCK EXIT
										if (App->container[i]->isType == EXIT){
											if (((Item*)App->container[i])->location == ((Exit*)App->container[j])->origin){
												((Exit*)App->container[j])->closed = true;//block the exit
												((Item*)App->container[i])->canPush = false;
											}
										}
									}
								}
							}
							else if (((Item*)App->container[i])->location->name == "Monster Cave"){
								printf("the big rock block the cave\n");
								((Item*)App->container[i])->description = "The big rock now block the cave";//change description of the item
								((Item*)App->container[i])->canPush = false;
								//this blocks the fight against the monster (monsters not implemented)
							}
							else if (((Item*)App->container[i])->location->name == "Waterfall"){
								printf("the big rock block the water\n");
								((Item*)App->container[i])->description = "The big rock now block the water";//change description of the item
								for (int j = 0; j <	App->container.size(); j++){//ITEM robot now we can take
									if (App->container[j]->isType == ITEM){

										if (((Item*)App->container[i])->location == ((Item*)App->container[j])->location && ((Item*)App->container[j])->name == "Robot"){
											((Item*)App->container[j])->canTake = true;
											((Item*)App->container[j])->description = "this robot is in perfect condition";//block the exit
										}
									}
								}
								((Item*)App->container[i])->canPush = false;
							}
							else{
								printf("You have blocked the entrance to your base, congratulations you have committed suicide\n");
								for (int j = 0; j < App->container.size(); j++){//BLOCK EXIT
									if (App->container[i]->isType == EXIT){

										if (((Item*)App->container[i])->location == ((Exit*)App->container[j])->destination){
											((Exit*)App->container[j])->closed = true;//block the exit
										}
									}
								}
								((Item*)App->container[i])->canPush = false;
							}
						}
					}

				}
				else{
					printf("You can't push %s\n\n", ((Item*)App->container[i])->name);
				}
			}
		}
	}
}


void Player::PutInto(Vector<MyString> &strings){
	for (int j = 0; j < inventory.size(); j++){
		if (strings[1] == inventory[j]->name){
			if (inventory[j]->equiped == false){
				for (int i = 0; i < App->container.size(); i++){
					if (App->container[i]->isType == ITEM){

						if (((Item*)App->container[i])->isItem == TRUNK && ((Item*)App->container[i])->location == location){
							((Item*)App->container[i])->trunk.push_back(inventory[j]);//put item on trunk
							printf("You put %s into %s\n", inventory[j]->name.C_Str(), ((Item*)App->container[i])->name.C_Str());
							inventory.clean_selected(j);//delete item from inventory
							return;
						}
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
void Player::GetFrom(Vector<MyString> &strings){//Get items froms trunk
	for (int i = 0; i < App->container.size(); i++){
		if (App->container[i]->isType == ITEM){
			if (((Item*)App->container[i])->isItem == TRUNK && ((Item*)App->container[i])->location == location){//check if is trunk item
				for (int j = 0; j < ((Item*)App->container[i])->trunk.size(); j++){
					if (strings[1] == ((Item*)App->container[i])->trunk[j]->name){
						inventory.push_back(((Item*)App->container[i])->trunk[j]);//put item on inventory
						printf("You get %s from %s\n", ((Item*)App->container[i])->trunk[j]->name.C_Str(), ((Item*)App->container[i])->name.C_Str());
						((Item*)App->container[i])->trunk.clean_selected(j);//delete item from trunk
						return;
					}
				}
			}
		}
	}
	printf("There is no trunk in the floor to perform this action.\n");
}