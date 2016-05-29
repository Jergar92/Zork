#include "World.h"
#include "time.h"
#include <Windows.h>
#include "MonkeyMonster.h"

Monkey::Monkey()
{

}
Monkey::Monkey(const char* name, const char* description, int life, int atack, int armor,Room* location) :Creature(name, description, life, atack, armor,location)
{
	Item*  meat = new Item("Meat", "a good piece of meat that give me energy",20,true, MEAT);
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
	if (currentTime >= (lastTime + 3000)){
		if (life > 0){
			lastTime = currentTime;
			if (this->CreatureType == NO_HOSTILE){
				if (!CheckTake()){
						currentState = MOVE;
						if (location == App->hero->location && !App->hero->list.empty()){
							currentState = STEAL;
						}
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
					currentState = ATACK_HERO;
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

						if (App->container[i]->isType == MONSTER && App->container[i] != this){
							if (((Creature*)App->container[i])->location == location){
								currentState = ATACK_NPC;
							}

						}
					}
				}
					else{
					for (i = 0; i < App->container.size(); i++){

						if (App->container[i]->isType == MONSTER && App->container[i] != this){
							if (((Creature*)App->container[i])->location == location){
								currentState = ATACK_NPC;
							}

						}
						else if (App->container[i]->isType == PLAYER)
						{
							if (App->hero->location == location){
								currentState = ATACK_HERO;
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
		case STEAL:
			Steal();
			break;
		case ATACK_HERO:
			Atack(App->hero);
			break;
		case ATACK_NPC:
			Atack(((Creature*)App->container[i]));
			break;
		case DIE:
			Die();
			break;
		default:
			break;
		}
	}
}


void Monkey::Atack(Player* hero){
	if (hero->armor < atack){
		hero->life -= (atack - hero->armor);
		printf("%s hit to %s and do %i damage\n", name.C_Str(), hero->name.C_Str(), (atack - hero->armor));

	}
	else{
		hero->life -= 1;
		printf("%s hit to %s and do %i damage\n", name.C_Str(), hero->name.C_Str(), 1);
	}
}
void Monkey::Atack(Creature* monster){
	if (monster->armor < atack){
		monster->life -= (atack - monster->armor);
		printf("%s hit to %s and do %i damage\n", name.C_Str(), monster->name.C_Str(), monster->armor);

	}
	else{
		monster->life -= 1;
		printf("%s hit to %s and do %i damage\n", name.C_Str(), monster->name.C_Str(), 1);
	}
}



void Monkey::Go(){//this move the player if the move is possible

	int direction = rand() % 4;
	
		for (int i = 0; i < App->container.size(); i++){
			if (App->container[i]->isType == EXIT){
				if (((Exit*)App->container[i])->direction == direction && ((Exit*)App->container[i])->origin->name.C_Str() == location->name.C_Str()){
					if (((Exit*)App->container[i])->closed == true){//check if the exit is closed
						if (((Exit*)App->container[i])->door == true){//check if the exit is closed
							((Exit*)App->container[i])->closed = false;
							if (((Exit*)App->container[i])->destination == App->hero->location){
								printf("the %s open the door from %s to %s\n", name.C_Str(), location->name.C_Str(), ((Exit*)App->container[i])->destination->name.C_Str());
							}
							else if (((Exit*)App->container[i])->origin == App->hero->location){
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
						if (((Exit*)App->container[i])->destination == App->hero->location){
							printf("the %s enter in the %s from %s \n", this->name.C_Str(), App->hero->location->name.C_Str(),((Exit*)App->container[i])->origin->name.C_Str());
						}
						else if (((Exit*)App->container[i])->origin == App->hero->location){
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
			if (((Item*)item->data)->isItem != ENVIROMENT && ((Item*)item->data)->canTake == true){//Check if is enviroment item and if you can take
				
				return true;
				//	contai.clean_selected(i); end erase
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
				if (((Item*)item->data)->isItem != ENVIROMENT && ((Item*)item->data)->canTake == true){//Check if is enviroment item and if you can take
					this->list.Push_back(((Item*)item->data));
					if (this->location == App->hero->location){
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
void Monkey::Steal(){//TAKE OBJECTS

	if (!App->hero->list.empty()){
		List<Entity*>::Node* item = App->hero->list.first_data;
		for (; item != nullptr; item = item->next)
		{
			if (((Item*)item->data)->isItem != ENVIROMENT && ((Item*)item->data)->canTake == true && ((Item*)item->data)->equiped==false){//Check if is enviroment item and if you can take
				this->list.Push_back(((Item*)item->data));
				if (this->location == App->hero->location){
					printf("%s steal %s from you\n", name.C_Str(), ((Item*)item->data)->name.C_Str());
				}
				if (((Item*)item->data)->isItem == BOOTS || ((Item*)item->data)->isItem == ARMOR || ((Item*)item->data)->isItem == WEAPON){
					Equip();
				}
				App->hero->list.Erase(item);
				break;
				//	contai.clean_selected(i); end erase
			}


		}
	}

}




void Monkey::Die(){

	if (!this->list.empty()){
		printf("%s drop after die:\n", name.C_Str(), list.first_data->data->name.C_Str());
		for (; list.first_data != nullptr; list.first_data = list.first_data->next){
			if (((Item*)list.first_data->data)->equiped == true){
				((Item*)list.first_data->data)->equiped = false;
				}
			location->list.Push_back(list.first_data->data);
			printf("%s\n", list.first_data->data->name.C_Str());
	


			}			
		}
	printf("the %s is dead\n", name.C_Str());
	isDead = true;
	}


void Monkey::Equip(){
	if (!this->list.empty()){
		List<Entity*>::Node* item = this->list.first_data;
		for (; item != nullptr; item = item->next){
			if (((Item*)item->data)->isItem == BOOTS || ((Item*)item->data)->isItem == ARMOR || ((Item*)item->data)->isItem == WEAPON){
				if (((Item*)item->data)->equiped == false){//equip and items give you stats
					((Item*)item->data)->equiped = true;
					atack += ((Item*)item->data)->atack;
					armor += ((Item*)item->data)->defense;
					return;
				}
				
			}
		}
	}
}


