#include "World.h"
#include "time.h"
#include <Windows.h>
#include "Seller.h"

Seller::Seller()
{

}
Seller::Seller(const char* name, const char* description, int life, int atack, int armor, Room* location) :Creature(name, description, life, atack, armor, location)
{
	isType = MONSTER;
	CreatureType = SELLER;
	currentState = IDLE;
}

Seller::~Seller()
{
}
void Seller::Update(){
	int i = 0;
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



void Seller::Atack(Player* hero){
	if (hero->armor < atack){
		hero->life -= (atack - hero->armor);
		printf("%s hit to %s and do %i damage\n", name.C_Str(), hero->name.C_Str(), (atack - hero->armor));

	}
	else{
		hero->life -= 1;
		printf("%s hit to %s and do %i damage\n", name.C_Str(), hero->name.C_Str(), 1);
	}
}
void Seller::Atack(Creature* monster){
	if (monster->armor < atack){
		monster->life -= (atack - monster->armor);
		printf("%s hit to %s and do %i damage\n", name.C_Str(), monster->name.C_Str(), monster->armor);

	}
	else{
		monster->life -= 1;
		printf("%s hit to %s and do %i damage\n", name.C_Str(), monster->name.C_Str(), 1);
	}
}
void Seller::Die(){

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


