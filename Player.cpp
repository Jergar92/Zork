#include "World.h"
#include <Windows.h>
#define lostLifeEnergy 5
#define SPECIAL 2
#define AtackTime 5000
#define EnergyTime 20000
#define SpecialAtackTime 20000
Player::Player()
{

}
Player::Player(const char* name, const char* description, int life, int atack, int armor,unsigned int energy, Room* location) :Creature(name, description, life, atack, armor, location)
,energy(energy)
{
	isType = PLAYER;
	CreatureType = HERO;
}

Player::~Player()
{
	
}
void Player::Stats()const{
	printf("You have %i hp, %i atack and %i defense and %i of energy\n", life, attack, armor,energy);
}
void Player::Update(){

	if (life >= 0){
		currentTime = GetTickCount();
		currentAttackTime = GetTickCount();
		currentSpecialAttackTime = GetTickCount();

		if (currentTime >= (lastTime + EnergyTime)){//this decrease your energy if you don't have energy your life
			lastTime = currentTime;
			if (energy <= 0){
				printf("You lost %i of life\n", lostLifeEnergy);
				life -= lostLifeEnergy;
			}
			else {
				printf("You lost %i of energy\n", lostLifeEnergy);
				energy -= lostLifeEnergy;
			}
			if (life < 20){
				printf("Take care, You only have %i of life\n", life);
			}
			if (energy < 20){
				printf("Take care, You only have %i of energy\n", energy);
			}
		}
		if (currentAttackTime >= (lastAttackTime + AtackTime)){//this is the autoatack
			lastAttackTime = currentTime;
			if (Target != nullptr){
				if (Target->isDead == true){
					Target = nullptr;
					return;
				}
				AttackTarget(Target);
			}	
		}

		if (currentSpecialAttackTime >= (lastSpecialAttackTime + SpecialAtackTime)&&specialAttack==false){//informs you once if you can use the special attack
			printf("you've regained your strength, you can do special atack again\n");
			specialAttack = true;
		}
	}
	else{
		printf("You are dead\n\n");//this end the game
		printf("This is the end of the game press enter for exit\n");
		getchar();
		isDead = true;
	}
}

void Player::AttackTarget(Creature* target){
	if (target->location == location){

		if (target->armor < attack){
			target->life -= (attack - target->armor);
			printf("%s hit to %s and do %i damage\n", name.C_Str(), target->name.C_Str(), (attack - target->armor));

		}
		else{
			target->life -= 1;
			printf("%s hit to %s and do %i damage\n", name.C_Str(), target->name.C_Str(), 1);
		}
	}
	if (target->life <= 0){
		Target = nullptr;
	}
}
void Player::Attack(Vector<MyString> &strings){

		for (int i = 0; i < App->container.size(); i++){
			if (App->container[i]->isType == MONSTER){

				if (((Creature*)App->container[i])->name == strings[1] && ((Creature*)App->container[i])->location == location){
					Target = ((Creature*)App->container[i]);
					if (((Creature*)App->container[i])->armor < attack){
						if (((Creature*)App->container[i])->CreatureType == NO_HOSTILE){
							((Creature*)App->container[i])->CreatureType = HOSTILE_PLAYER;
						}
						((Creature*)App->container[i])->life -= (attack - ((Creature*)App->container[i])->armor);
						printf("%s hit to %s and do %i damage\n", name.C_Str(), ((Creature*)App->container[i])->name.C_Str(), (attack - ((Creature*)App->container[i])->armor));
						return;//this prevents you hit more than one monkey at a time
					}
					else{
						if (((Creature*)App->container[i])->CreatureType == NO_HOSTILE){
							((Creature*)App->container[i])->CreatureType = HOSTILE_PLAYER;
						}
						((Creature*)App->container[i])->life -= 1;
						printf("%s hit to %s and do %i damage\n", name.C_Str(), ((Creature*)App->container[i])->name.C_Str(), 1);
						return;//this prevents you hit more than one monkey at a time

					}

				}
			}
		}
	
}
void Player::SpecialAttack(Vector<MyString> &strings){
	if (currentSpecialAttackTime >= (lastSpecialAttackTime + SpecialAtackTime)){
		lastSpecialAttackTime = currentSpecialAttackTime;
	for (int i = 0; i < App->container.size(); i++){
		if (App->container[i]->isType == MONSTER){

			if (((Creature*)App->container[i])->name == strings[2] && ((Creature*)App->container[i])->location == location){
				Target = ((Creature*)App->container[i]);
				specialAttack = false;
				if (((Creature*)App->container[i])->armor < attack){
					if (((Creature*)App->container[i])->CreatureType == NO_HOSTILE){//if the creature is no hostile turn to hostile to you
						((Creature*)App->container[i])->CreatureType = HOSTILE_PLAYER;
					}
					((Creature*)App->container[i])->life -= ((SPECIAL*attack) - ((Creature*)App->container[i])->armor);
					printf("You hit with all your strength\n\n");
					printf("%s hit to %s and do %i damage\n", name.C_Str(), ((Creature*)App->container[i])->name.C_Str(), ((SPECIAL*attack) - ((Creature*)App->container[i])->armor));
					return;//this prevents you hit more than one monkey at a time
				}
				else{
					if (((Creature*)App->container[i])->CreatureType == NO_HOSTILE){//if the creature is no hostile turn to hostile to you
						((Creature*)App->container[i])->CreatureType = HOSTILE_PLAYER;
					}
					((Creature*)App->container[i])->life -= 1 * SPECIAL;
					printf("You hit with all your strength\n\n");
					printf("%s hit to %s and do %i damage\n", name.C_Str(), ((Creature*)App->container[i])->name.C_Str(), 1 * SPECIAL);
					return;//this prevents you hit more than one monkey at a time

				}

			}
		}
	}
	}
}
void Player::Speak(Vector<MyString> &strings)const{//this is for get info from the seller

	for (int i = 0; i < App->container.size(); i++){
		if (((Creature*)App->container[i])->CreatureType == SELLER){
			if (((Creature*)App->container[i])->name == strings[1] && ((Creature*)App->container[i])->location == location){
				((Seller*)App->container[i])->Speak();
			}
			else{
				printf("You can not talk to anyone here");
			}
		}
	}
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
				if (((Exit*)App->container[i])->direction == direction && ((Exit*)App->container[i])->origin->name.C_Str() == location->name.C_Str()){
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
	printf("You are in a %s, %s \n", location->name.C_Str(), location->description.C_Str());
	for (int i = 0; i < App->container.size(); i++){
		if (App->container[i]->isType == PLAYER){
			if (!((Player*)App->container[i])->location->list.empty()){
				const List<Entity*>::Node* item = ((Player*)App->container[i])->location->list.first_data;
				for (; item != nullptr; item = item->next)
				{
					printf("You see a %s\n", item->data->name.C_Str());
				}
			}

		}
		else if (App->container[i]->isType == MONSTER){
			if (location == ((Creature*)App->container[i])->location){
				printf("You see a %s", ((Creature*)App->container[i])->name.C_Str());
			}
		}
	}
}


void Player::Look(Vector<MyString> &strings){//because getDirection can be const
	int direction = -1;
	direction = App->getDirection(strings);//dat get the right direction
	if (direction == -1){
		if (strings[1] == "here" || strings[1] == ""){//LOCK ROOM
			Look();
			return;
		}
		else if (strings[1] == "hero"){//LOOK HERO STATS
			if (strings[2] == "stats"){
				Stats();
				return;
			}
		}
		else if (strings[1] == "inventory"){//LOOK ALL INVENTORY
			if (!list.empty()){
				for (int i = 0; i < list.size(); i++){
					if (!list.empty()){
						const List<Entity*>::Node* item = list.first_data;
						for (; item != nullptr; item = item->next)
						{
							printf("You see a %s\n", item->data->name.C_Str());
						}
					}
				}
			}
			else{
				printf("You don't have nothing");
			}
			return;
		}
		else if (strings[1] == "inside"){//LOOK INSIDE TRUNK ITEMS
			if (!location->list.empty()){
				List<Entity*>::Node* item = location->list.first_data;
				for (; item != nullptr; item = item->next){
					if (((Item*)item->data)->isType == ITEM && ((Item*)item->data)->isItem == TRUNK&& strings[2] == ((Item*)item->data)->name){
						if (!((Item*)item->data)->list.empty()){
							List<Entity*>::Node* InsideItem = ((Item*)item->data)->list.first_data;
							printf("Inside %s you see:\n", ((Item*)item->data)->name.C_Str());
							for (; InsideItem != nullptr; InsideItem = InsideItem->next)
							{
								printf("%s\n", InsideItem->data->name.C_Str());
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
			for (int i = 0; i < location->list.size(); i++){//LOOK SPECIFIC OBJECTS(NO iventory items)
				if (!location->list.empty()){
					const List<Entity*>::Node* item = location->list.first_data;
					for (; item != nullptr; item = item->next){
						if (strings[1] == item->data->name){
							if (strings[2] == "stats"){
								if (item->data->isType == ARMOR || item->data->isType == WEAPON || item->data->isType == BOOTS) {
									item->data->Stats();
								}
								else{
									printf("this item don't have stats");
								}
								return;
							}
						}
					}
				}

			}
			for (int i = 0; i < list.size(); i++){//LOOK SPECIFIC OBJECTS(iventory items)
				if (!list.empty()){
					const List<Entity*>::Node* item = list.first_data;
					for (; item != nullptr; item = item->next){
						if (strings[1] == item->data->name){
							if (strings[2] == "stats"){
								if (item->data->isType == ARMOR || item->data->isType == WEAPON || item->data->isType == BOOTS) {
									item->data->Stats();
								}
								else{
									printf("this item don't have stats");
								}
								return;
							}
						}
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
							for (int j = 0; j < App->container.size(); j++){
								if (App->container[j]->isType == EXIT){
									if (((Exit*)App->container[i])->origin == ((Exit*)App->container[j])->destination && ((Exit*)App->container[i])->destination == ((Exit*)App->container[j])->origin){
										((Exit*)App->container[j])->closed = false;
									}
								}
							}
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
							for (int j = 0; j < App->container.size(); j++){
								if (App->container[j]->isType == EXIT){
									if (((Exit*)App->container[i])->origin == ((Exit*)App->container[j])->destination && ((Exit*)App->container[i])->destination == ((Exit*)App->container[j])->origin){
										((Exit*)App->container[j])->closed = true;
									}
								}
							}
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

	if (!location->list.empty()){
		List<Entity*>::Node* item = location->list.first_data;
		for (; item != nullptr; item = item->next)
		{
			if (((Item*)item->data)->name == strings[1]){
				if (((Item*)item->data)->isItem != ENVIROMENT && ((Item*)item->data)->canTake == true){//Check if is enviroment item and if you can take
					this->list.Push_back(((Item*)item->data));
					printf("You take %s\n", ((Item*)item->data)->name.C_Str());
					location->list.Erase(item);
					break;
					//	contai.clean_selected(i); end erase
				}
				else{
					printf("You can't take %s\n", ((Item*)item->data)->name.C_Str());
					break;

				}
			}
		}
	}
	else{
		printf("No items here");

	}
}

void Player::Eat_Drink(Vector<MyString> &strings){//use meat or piton

	if (!list.empty()){
		List<Entity*>::Node* item = list.first_data;
		for (; item != nullptr; item = item->next)
		{
			if (((Item*)item->data)->name == strings[1] && ((Item*)item->data)->isItem == MEAT){
					energy += ((Item*)item->data)->energy;
					printf("You eat %s your energy is %i now\n", ((Item*)item->data)->name.C_Str(),energy);
					((Item*)item->data)->toDestroy = true;//update will delete this item
					location->list.Erase(item);
					break;
				}
			else if (((Item*)item->data)->name == strings[1] && ((Item*)item->data)->isItem == POTION){
				life += ((Item*)item->data)->life;
				printf("You drink %s your life is %i now\n", ((Item*)item->data)->name.C_Str(), life);
				((Item*)item->data)->toDestroy = true;//update will delete this item
				location->list.Erase(item);
				break;
			}
				else{
					printf("You can't eat %s\n", ((Item*)item->data)->name.C_Str());
					break;
				}
			}
		}	
	}
void Player::Mount(Vector<MyString> &strings){//this is the action to end the game
	if (!this->list.empty()){
		int counter = 0;
		bool robot = false;
		List<Entity*>::Node* item = this->list.first_data;
		for (; item != nullptr; item = item->next){
			if (strings[1] == "beacon"){//Look if you have this item on you inventory
				if (((Item*)item->data)->isItem == QUEST){
					counter++;
				}
				if (((Item*)item->data)->name == "Robot"){
					robot = true;
				}
			}
		}
		if (counter == 3 && energy <= 20 &&robot==false){//if you do not have enough energy and you don't have the robot you lose
			printf("You got assembling the beacon but starve before getting help\n\n");
			printf("This is the end of the game press any button for exit\n");
			getchar();
			strings[0] = "quit";
		}
		else if (counter == 3 && energy <= 20 && robot == true){//if you do not have enough energy and but you have the robot you win
			printf("You have successfully managed to save you congratulations!!\n\n");
			printf("This is the end of the game press any button for exit\n");

			getchar();
			strings[0] = "quit";

		}
		else if (counter == 3 && energy > 20){//if you have enough energy you win
			printf("You have successfully managed to save you congratulations!!\n\n");
			printf("This is the end of the game press any button for exit\n");

			getchar();
			strings[0] = "quit";

		}
		else{//if you don't have the three objects needen you still playing
			printf("You do not have the three objects needed");
		}
	}
	else{
		printf("You don't have items");

	}
}
void Player::Buy(Vector<MyString> &strings){//take potion from seller or look seller inventory
	for (int i = 0; i < App->container.size(); i++){
		if (((Creature*)App->container[i])->CreatureType == SELLER){
			if (((Creature*)App->container[i])->name == strings[1] && ((Creature*)App->container[i])->location == location){//this is for look inventory
				((Seller*)App->container[i])->Inventory();
			}
			else if ((((Creature*)App->container[i])->name == strings[3] && ((Creature*)App->container[i])->location == location)){//this is for take potion from him
				if (!((Creature*)App->container[i])->list.empty()){
					List<Entity*>::Node* item = ((Creature*)App->container[i])->list.first_data;
					for (; item != nullptr; item = item->next)
					{
						if (((Item*)item->data)->name == strings[1]){
							if (((Item*)item->data)->isItem == POTION && ((Item*)item->data)->canTake == true){//Check if is potion item and if you can take
								this->list.Push_back(((Item*)item->data));
								printf("You take %s from %s\n", ((Item*)item->data)->name.C_Str(), ((Creature*)App->container[i])->name.C_Str());
								((Creature*)App->container[i])->list.Erase(item);
								break;
								//	contai.clean_selected(i); end erase
							}
						}
					}
				}
				else{
					printf("I have no more potions bring me more meat and wait");

				}
			}
		}
	}
}
void Player::Sell(Vector<MyString> &strings){//give meat to seller
	for (int i = 0; i < App->container.size(); i++){
		if (((Creature*)App->container[i])->CreatureType == SELLER){
			if ((((Creature*)App->container[i])->name == strings[3] && ((Creature*)App->container[i])->location == location)){
				if (!list.empty()){
					List<Entity*>::Node* item = list.first_data;
					for (; item != nullptr; item = item->next)
					{
						if (((Item*)item->data)->name == strings[1]){
							if (((Item*)item->data)->isItem == MEAT && ((Item*)item->data)->canTake == true){//Check if is meat item
								((Creature*)App->container[i])->list.Push_back(((Item*)item->data));
								printf("You give %s to %s\n", ((Item*)item->data)->name.C_Str(), ((Creature*)App->container[i])->name.C_Str());
								list.Erase(item);
								((Seller*)App->container[i])->lastTime = ((Seller*)App->container[i])->currentTime;//reset timer

								break;
								//	contai.clean_selected(i); end erase
							}
						}
					}
				}
				else{
					printf("You don't have nothing human");

				}
			}
		}
	}
}


void Player::Drop(Vector<MyString> &strings){

	if (!this->list.empty()){
		List<Entity*>::Node* item = this->list.first_data;
		for (; item != nullptr; item = item->next){
			if (strings[1] == ((Item*)item->data)->name){//Look if you have this item on you inventory
				if (((Item*)item->data)->equiped == false){
					location->list.Push_back(((Item*)item->data));
					printf("You drop %s\n", ((Item*)item->data)->name.C_Str());
					this->list.Erase(item);
					break;
				}
				else{
					printf("You can not throw a equipped object\n");
					break;
				}
			}
		}
	}
	else{
		printf("You don't have items");

	}
}

void Player::Equip(Vector<MyString> &strings){
	if (!this->list.empty()){
		List<Entity*>::Node* item = this->list.first_data;
		for (; item != nullptr; item = item->next){
			if (strings[1] == ((Item*)item->data)->name && ((Item*)item->data)->isItem == BOOTS || ((Item*)item->data)->isItem == ARMOR || ((Item*)item->data)->isItem == WEAPON){
				if (((Item*)item->data)->equiped == false){//equip and items give you stats
					((Item*)item->data)->equiped = true;
					attack += ((Item*)item->data)->atack;
					armor += ((Item*)item->data)->defense;
					printf("You equiped %s\n", ((Item*)item->data)->name);
					return;
				}
				else{
					printf("Already was equipped\n");
					return;
				}
			}
		}
	}
	else{
		printf("You don't have items");

	}
}

void Player::UnEquip(Vector<MyString> &strings){
	if (!this->list.empty()){
		List<Entity*>::Node* item = this->list.first_data;
		for (; item != nullptr; item = item->next){
			if (strings[1] == ((Item*)item->data)->name && ((Item*)item->data)->isItem == BOOTS || ((Item*)item->data)->isItem == ARMOR || ((Item*)item->data)->isItem == WEAPON){
				if (((Item*)item->data)->equiped == true){//unequip and lost stats
					((Item*)item->data)->equiped = false;
					attack -= ((Item*)item->data)->atack;
					armor -= ((Item*)item->data)->defense;
					printf("You have taken away %s\n", ((Item*)item->data)->name);
					return;
				}
				else{
					printf("You do not have this object equipped\n");
					return;
				}
			}
		}
	}
}

void Player::Push(Vector<MyString> &strings){
	int direction = -1;
	List<Entity*>::Node* item = location->list.first_data;

	if (!location->list.empty()){
		for (; item != nullptr; item = item->next){
			if (strings[1] == ((Item*)item->data)->name && ((Item*)item->data)->isItem == ENVIROMENT && ((Item*)item->data)->canPush == true){//check if is enviroment item (only rock is enviroment)
				direction = App->getDirection(strings);//dat get the direction you push
				break;
				if (direction == -1){
					printf("wrong direction.\n");
					return;
				}
			}
			else{
				printf("you can't push this");
			}
		}
		for (int i = 0; i < App->container.size(); i++){
			if (App->container[i]->isType == EXIT){
				if (((Exit*)App->container[i])->origin == location){
					if (((Exit*)App->container[i])->direction == direction && (((Exit*)App->container[i])->destination->name == "Abandoned Cave")){//check if they have the same direction
						printf("You have blocked the entrance to the Abandoned cave\n");
						((Exit*)App->container[i])->destination->list.Push_back(((Item*)item->data));
						((Item*)item->data)->canPush = false;
						((Exit*)App->container[i])->origin->list.Erase(item);
						((Exit*)App->container[i])->closed = true;//block the exit
					}
					else if (((Exit*)App->container[i])->direction == direction && ((Exit*)App->container[i])->destination->name == "Monster Cave"){
						printf("the big rock block the cave\n");
						((Item*)item->data)->description = "The big rock now block the cave";//change description of the item
						((Item*)item->data)->canPush = false;
						((Exit*)App->container[i])->destination->list.Push_back(((Item*)item->data));
						((Exit*)App->container[i])->origin->list.Erase(item);//this blocks the fight against the monster (monsters not implemented)
						for (int j = 0; j < App->container.size(); j++){//All monsters die on this location die
							if (App->container[j]->isType == MONSTER){
								if (((Exit*)App->container[i])->destination == ((Creature*)App->container[j])->location){
									((Creature*)App->container[j])->life -= 200;
								}
							}
						}
					}
					else if (((Exit*)App->container[i])->direction == direction && ((Exit*)App->container[i])->destination->name == "Waterfall"){
						printf("the big rock block the water\n");
						((Item*)item->data)->description = "The big rock now block the water";//change description of the item
						((Item*)item->data)->canPush = false;
						((Exit*)App->container[i])->destination->list.Push_back(((Item*)item->data));
						((Exit*)App->container[i])->origin->list.Erase(item);
						for (int j = 0; j < App->container.size(); j++){//ITEM robot now we can take
							if (App->container[j]->isType == ITEM && App->container[j]->name == "Robot"){
								((Item*)App->container[j])->canTake = true;
								((Item*)App->container[j])->description = "this robot is in perfect condition";//block the exit
							}
						}
					}
					else if (((Exit*)App->container[i])->direction == direction && ((Exit*)App->container[i])->destination->name == "Home Base"){
						printf("You have blocked the entrance to your base, congratulations you have committed suicide\n");
						((Exit*)App->container[i])->closed = true;//block the exit
						((Item*)item->data)->canPush = false;
						((Exit*)App->container[i])->destination->list.Push_back(((Item*)item->data));
						((Exit*)App->container[i])->origin->list.Erase(item);
					}
				}
			}
		}
	}
}


void Player::PutInto(Vector<MyString> &strings){

	if (!this->list.empty()){
		List<Entity*>::Node* item = this->list.first_data;
		for (; item != nullptr; item = item->next){
			if (strings[1] == ((Item*)item->data)->name){
				if (((Item*)item->data)->equiped == false){
					if (!location->list.empty()){
						List<Entity*>::Node* otherItem = location->list.first_data;
						for (; otherItem != nullptr; otherItem = otherItem->next){
							if (((Item*)otherItem->data)->isType == ITEM){
								if (((Item*)otherItem->data)->isItem == TRUNK){
									(((Item*)otherItem->data)->list.Push_back((Item*)item->data));//put item on trunk
									printf("You put %s into %s\n", ((Item*)item->data)->name.C_Str(), ((Item*)otherItem->data)->name.C_Str());
									return;
								}
							}
						}
					}
					else{
						printf("There is no trunk in the floor to perform this action.\n");
					}
				}
				else{
					printf("You can not put a equipped object\n");
				}
			}
		}
	}

}

void Player::GetFrom(Vector<MyString> &strings){//Get items froms trunk
	if (!location->list.empty()){
		List<Entity*>::Node* item = location->list.first_data;
		for (; item != nullptr; item = item->next){
			if (((Item*)item->data)->isType == ITEM && ((Item*)item->data)->isItem == TRUNK&& strings[3] == ((Item*)item->data)->name){
				if (!((Item*)item->data)->list.empty()){
					List<Entity*>::Node* InsideItem = ((Item*)item->data)->list.first_data;
					for (; InsideItem != nullptr; InsideItem = InsideItem->next){
						if (strings[1] == ((Item*)InsideItem->data)->name){
							printf("You get %s from %s\n", ((Item*)InsideItem->data)->name.C_Str(), ((Item*)item->data)->name.C_Str());
							this->list.Push_back(((Item*)InsideItem->data));

							((Item*)item->data)->list.Erase(InsideItem);

							return;

						}


					}
				}
			}
		}
	}
	printf("There is no trunk in the floor to perform this action.\n");
}
