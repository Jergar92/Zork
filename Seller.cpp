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
	currentTime = GetTickCount();
	if (currentTime >= (lastTime + 20000)){
		lastTime = currentTime;

		if (!list.empty()){
			List<Entity*>::Node* item = list.first_data;
			for (; item != nullptr; item = item->next)
			{

				if (((Item*)item->data)->isItem == MEAT){
				 if (location == App->hero->location){
					 printf("Selter - Human I finished processing the meat");
				 }
					((Item*)item->data)->toDestroy = true;
					location->list.Erase(item);
					Item*  potion = new Item("Meat", "a good piece of meat that give me energy", 20, 0, true, MEAT);
					App->container.push_back(potion);
					list.Push_back(potion);
					break;
					//	contai.clean_selected(i); end erase
				}
			}
		}
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
void Seller::Inventory(){
	if (!list.empty()){
		for (int i = 0; i < list.size(); i++){
			if (!list.empty()){
				const List<Entity*>::Node* item = list.first_data;
				printf("Seller - This is my inventory:\n");
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


