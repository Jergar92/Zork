#include "World.h"
#include "time.h"
#include <Windows.h>
#include "HawkMonster.h"

Hawk::Hawk()
{

}
Hawk::Hawk(const char* name, const char* description, int life, int atack, int armor, Room* location) :Creature(name, description, life, atack, armor, location)
{
	Item*  meat = new Item("Meat", "a good piece of meat that give me energy", 0, 20, true, MEAT);
	App->container.push_back(meat);
	list.Push_back(meat);
	isType = MONSTER;
	CreatureType = HOSTILE_ALL;
	currentState = IDLE;
}

Hawk::~Hawk()
{
}
void Hawk::Update(){
	if (isDead == true){
		return;
	}
	int i = 0;
	currentTime = GetTickCount();
	if (currentTime >= (lastTime + 4000)){
		if (life > 0){
			lastTime = currentTime;
			if (this->CreatureType == HOSTILE_ALL){
				if (this->location != App->hero->location&&App->hero->isDead != true){
					for (i = 0; i < App->container.size(); i++){
						if (App->container[i]->isType == MONSTER && !(App->container[i]->name == this->name) && ((Creature*)App->container[i])->isDead == false){
							if (((Creature*)App->container[i])->location == location){
								currentState = ATACK_NPC;
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

						if (App->container[i]->isType == MONSTER && !(App->container[i]->name == this->name) && ((Creature*)App->container[i])->isDead == false){
							if (((Creature*)App->container[i])->location == location){
								currentState = ATACK_NPC;
								break;
							}
							else{
								currentState = IDLE;
							}

						}
						else if (App->container[i]->isType == PLAYER)
						{
							if (App->hero->location == location){
								currentState = ATACK_HERO;
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
		case IDLE:
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
void Hawk::Atack(Player* hero){
	if (hero->armor < atack){
		hero->life -= (atack - hero->armor);
		printf("%s hit to %s and do %i damage\n", name.C_Str(), hero->name.C_Str(), (atack - hero->armor));

	}
	else{
		hero->life -= 1;
		printf("%s hit to %s and do %i damage\n", name.C_Str(), hero->name.C_Str(), 1);
	}
}
void Hawk::Atack(Creature* monster){
	if (monster->armor < atack){
		monster->life -= (atack - monster->armor);
		printf("%s hit to %s and do %i damage\n", name.C_Str(), monster->name.C_Str(), monster->armor);

	}
	else{
		monster->life -= 1;
		printf("%s hit to %s and do %i damage\n", name.C_Str(), monster->name.C_Str(), 1);
	}
}
void Hawk::Die(){

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
