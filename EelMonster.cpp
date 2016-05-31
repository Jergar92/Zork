#include "World.h"
#include "time.h"
#include <Windows.h>
#include "EelMonster.h"
#define time 2500

Eel::Eel()
{

}
Eel::Eel(const char* name, const char* description, int life, int atack, int armor, Room* location) :Creature(name, description, life, atack, armor, location)
{
	Item*  meat = new Item("Meat", "a good piece of meat that give me energy", 0, 20, true, MEAT);
	App->container.push_back(meat);
	list.Push_back(meat);
	isType = MONSTER;
	CreatureType = HOSTILE_ALL;
	currentState = IDLE;
}

Eel::~Eel()
{
}
void Eel::Update(){
	if (isDead == true){
		return;
	}
	int i = 0;
	currentTime = GetTickCount();
	if (currentTime >= (lastTime + time)){
		if (life > 0){
			lastTime = currentTime;
			if (this->CreatureType == HOSTILE_ALL){
				if (this->location != App->hero->location&&App->hero->isDead != true){
					for (i = 0; i < App->container.size(); i++){
						if (App->container[i]->isType == MONSTER && !(App->container[i]->name == this->name)){
							if (((Creature*)App->container[i])->location == location && ((Creature*)App->container[i])->isDead == false){
								currentState = ATTACK_NPC;
								break;
							}
							else{
								currentState = IDLE;
							}
						}
					}
				}
				else{
					for (i = 0; i < App->container.size(); i++){

						if (App->container[i]->isType == MONSTER && !(App->container[i]->name == this->name)){
							if (((Creature*)App->container[i])->location == location&&((Creature*)App->container[i])->isDead == false){
								currentState = ATTACK_NPC;
								break;
							}
							else{
								currentState = IDLE;
							}

						}
						else if (App->container[i]->isType == PLAYER)
						{
							if (App->hero->location == location){
								currentState = ATTACK_HERO;
								break;
							}
							else{
								currentState = IDLE;
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
void Eel::Attack(Player* hero){
	if (hero->armor < attack){
		hero->life -= (attack - hero->armor);
		printf("%s hit to %s and do %i damage\n", name.C_Str(), hero->name.C_Str(), (attack - hero->armor));
	}
	else{
		hero->life -= 1;
		printf("%s hit to %s and do %i damage\n", name.C_Str(), hero->name.C_Str(), 1);
	}
}
void Eel::Attack(Creature* monster){
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
void Eel::Die(){

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
}
