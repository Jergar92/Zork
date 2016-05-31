#include "World.h"
#include "time.h"
#include <Windows.h>
#include "MonkeyMonster.h"
#define time 3000

Monkey::Monkey()
{

}
Monkey::Monkey(const char* name, const char* description, int life, int atack, int armor,Room* location) :Creature(name, description, life, atack, armor,location)
{
	Item*  meat = new Item("Meat", "a good piece of meat that give me energy",0,20,true, MEAT);
	App->container.push_back(meat);
	list.Push_back(meat);
	isType = MONSTER;
	CreatureType = NO_HOSTILE;
	currentState = MOVE;
}

Monkey::~Monkey()
{
}
void Monkey::Update(){
	if (isDead == true){
		return;
	}
	int i = 0;
	currentTime = GetTickCount();
	if (currentTime >= (lastTime + time)){
		if (life > 0){
			lastTime = currentTime;
			if (this->CreatureType == NO_HOSTILE){
				if (!CheckTake()){
						currentState = MOVE;
						/*
						if (location == App->hero->location && !App->hero->list.empty()){
							currentState = STEAL;
						}
						*/
					}
					else{
						currentState = TAKE;
					}
				}
			
			else if (this->CreatureType == HOSTILE_PLAYER){

				if (this->location != App->hero->location&&App->hero->isDead != true){
					if (!CheckTake()){
						currentState = MOVE;
					}
					else{
						currentState = TAKE;
					}
				}
				else{
					currentState = ATTACK_HERO;
				}
			}
			else if (this->CreatureType == HOSTILE_ALL){
				if (this->location != App->hero->location&&App->hero->isDead != true){
			
					if (!CheckTake()){
						currentState = MOVE;
					}
					else if (CheckTake()){
						currentState = TAKE;
					}
					for (i = 0; i < App->container.size(); i++){

						if (App->container[i]->isType == MONSTER && !(App->container[i]->name == this->name) && ((Creature*)App->container[i])->isDead == false){
							if (((Creature*)App->container[i])->location == location){
								currentState = ATTACK_NPC;
								break;
							}
							else{
								currentState = MOVE;
							}

						}
					}
				}
					else{
					for (i = 0; i < App->container.size(); i++){

						if (App->container[i]->isType == MONSTER && !(App->container[i]->name == this->name) && ((Creature*)App->container[i])->isDead == false){
							if (((Creature*)App->container[i])->location == location){
								currentState = ATTACK_NPC;
								break;
							}
							else{
								currentState = MOVE;
						
							}

						}
						else if (App->container[i]->isType == PLAYER)
						{
							if (App->hero->location == location){
								currentState = ATTACK_HERO;
								break;
							}
							else{
								currentState = MOVE;
							}
						}

					}
				}
				
			}
		}
		else{
			currentState = DIE;
		}
		switch (currentState)
		{
		case MOVE:
			Go();
			break;
		case TAKE:
			Take();
			break;
		/*
		case STEAL:
			Steal();
			break;
			*/
		case ATTACK_HERO:
			Attack(App->hero);
			break;
		case ATTACK_NPC:
			Attack(((Creature*)App->container[i]));
			break;
		case DIE:
			Die();
			break;
		default:
			break;
		}
	}
}


void Monkey::Attack(Player* hero){
	if (hero->armor < attack){
		hero->life -= (attack - hero->armor);
		printf("%s hit to %s and do %i damage\n", name.C_Str(), hero->name.C_Str(), (attack - hero->armor));

	}
	else{
		hero->life -= 1;
		printf("%s hit to %s and do %i damage\n", name.C_Str(), hero->name.C_Str(), 1);
	}
}
void Monkey::Attack(Creature* monster){
	if (monster->armor < attack){
		monster->life -= (attack - monster->armor);
		if (location == App->hero->location){//If you're there the game tells you
			printf("%s hit to %s and do %i damage\n", name.C_Str(), monster->name.C_Str(), monster->armor);
		}

	}
	else{
		monster->life -= 1;
		if (location == App->hero->location){//If you're there the game tells you

			printf("%s hit to %s and do %i damage\n", name.C_Str(), monster->name.C_Str(), 1);
		}
	}
}



void Monkey::Go(){//this move the player if the move is possible

	int direction = rand() % 4;
	
		for (int i = 0; i < App->container.size(); i++){
			if (App->container[i]->isType == EXIT){
				if (((Exit*)App->container[i])->direction == direction && ((Exit*)App->container[i])->origin == location){
					if (((Exit*)App->container[i])->closed == true){//check if the exit is closed
						if (((Exit*)App->container[i])->door == true){//check if the exit is closed
							((Exit*)App->container[i])->closed = false;
							if (((Exit*)App->container[i])->destination == App->hero->location){//If you're there the game tells you
								printf("the %s open the door from %s to %s\n", name.C_Str(), location->name.C_Str(), ((Exit*)App->container[i])->destination->name.C_Str());
							}
							else if (((Exit*)App->container[i])->origin == App->hero->location){//If you're there the game tells you
								printf("the %s open the door from %s to %s\n", name.C_Str(), location->name.C_Str(), ((Exit*)App->container[i])->destination->name.C_Str());
							}
							for (int j = 0; j < App->container.size(); j++){
								if (App->container[j]->isType == EXIT){
									if (((Exit*)App->container[i])->origin == ((Exit*)App->container[j])->destination && ((Exit*)App->container[i])->destination == ((Exit*)App->container[j])->origin){
										((Exit*)App->container[j])->closed = false;
									}
								}
							}
							return;
						}
					}
					else{
						if (((Exit*)App->container[i])->destination == App->hero->location){//If you're there the game tells you
							printf("the %s enter in the %s from %s \n", this->name.C_Str(), App->hero->location->name.C_Str(),((Exit*)App->container[i])->origin->name.C_Str());
						}
						else if (((Exit*)App->container[i])->origin == App->hero->location){//If you're there the game tells you
							printf("the %s left the %s and go to %s\n", this->name.C_Str(), App->hero->location->name.C_Str(), ((Exit*)App->container[i])->destination->name.C_Str());
						}
						location = ((Exit*)App->container[i])->destination;//change your location
						return;
					}
				}

			}
		}
	
}
bool Monkey::CheckTake(){
	if (!location->list.empty()){
		List<Entity*>::Node* item = location->list.first_data;
		for (; item != nullptr; item = item->next)
		{
			if (((Item*)item->data)->isItem != ENVIROMENT && ((Item*)item->data)->canTake == true && ((Item*)item->data)->toDestroy == false){//Check if is enviroment item and if you can take
				return true;
			}


		}
	}
	return false;

}


void Monkey::Take(){//TAKE OBJECTS

	if (!location->list.empty()){
		List<Entity*>::Node* item = location->list.first_data;
		for (; item != nullptr; item = item->next)
		{
			if (((Item*)item->data)->isItem != ENVIROMENT && ((Item*)item->data)->canTake == true && ((Item*)item->data)->toDestroy == false){//Check if is enviroment item and if they can take
					this->list.Push_back(((Item*)item->data));
					if (location == App->hero->location){
						printf("%s take %s\n", name.C_Str(),((Item*)item->data)->name.C_Str());
					}
					if (((Item*)item->data)->isItem == BOOTS || ((Item*)item->data)->isItem == ARMOR || ((Item*)item->data)->isItem == WEAPON){
						Equip();
					}
					location->list.Erase(item);
					break;
					//	contai.clean_selected(i); end erase
				}
				
			
		}
	}
	
}
/*
void Monkey::Steal(){//TAKE OBJECTS from you

	if (!App->hero->list.empty()){
		List<Entity*>::Node* item = App->hero->list.first_data;
		for (; item != nullptr; item = item->next){
			if (((Item*)item->data)->isItem != ENVIROMENT && ((Item*)item->data)->toDestroy == false && ((Item*)item->data)->equiped==false){//if you don't have the object equiped they can steal from you
				list.Push_back(((Item*)item->data));
				if (location == App->hero->location){
					printf("%s steal %s from you\n", name.C_Str(), ((Item*)item->data)->name.C_Str());
				}
				if (((Item*)item->data)->isItem == BOOTS || ((Item*)item->data)->isItem == ARMOR || ((Item*)item->data)->isItem == WEAPON){//if they can equip the object they will equip
					Equip();
				}
				App->hero->list.Erase(item);
				return;
			}
		}
	}
}
*/



void Monkey::Die(){

	if (!this->list.empty()){
		if (location == App->hero->location){//If you're there the game tells you
			printf("%s drop after die:\n", name.C_Str(), list.first_data->data->name.C_Str());
		}
		for (; list.first_data != nullptr; list.first_data = list.first_data->next){
			if (((Item*)list.first_data->data)->equiped == true){
				((Item*)list.first_data->data)->equiped = false;
			}
			location->list.Push_back(list.first_data->data);
			if (location == App->hero->location){//If you're there the game tells you
				printf("%s\n", list.first_data->data->name.C_Str());
			}


		}
	}
	printf("the %s is dead\n", name.C_Str());
	isDead = true;//this will delete the creature on update
	App->MonkeyNumber--;//decrease the number of active monkeys

}

void Monkey::Equip(){
	if (!list.empty()){
		List<Entity*>::Node* item = list.first_data;
		for (; item != nullptr; item = item->next){
			if (((Item*)item->data)->isItem == BOOTS || ((Item*)item->data)->isItem == ARMOR || ((Item*)item->data)->isItem == WEAPON){
				if (((Item*)item->data)->equiped == false){//equip and items give you stats
					((Item*)item->data)->equiped = true;
					attack += ((Item*)item->data)->atack;
					armor += ((Item*)item->data)->defense;
					return;
				}
				
			}
		}
	}
}


