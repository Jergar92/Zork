#include "World.h"
#include "time.h"
#include <Windows.h>
#include "Seller.h"
#define time 20000

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
	if (currentTime >= (lastTime + time)){
		lastTime = currentTime;

		if (!list.empty()){
			List<Entity*>::Node* item = list.first_data;
			for (; item != nullptr; item = item->next)
			{

				if (((Item*)item->data)->isItem == MEAT){//delete meat and create potion
				 if (location == App->hero->location){
					 printf("Selter - Human I finished processing the meat\n");
				 }
					((Item*)item->data)->toDestroy = true;//this will delete on update
					list.Erase(item);
					Item*  potion = new Item("Potion", "this will recover my life\n", 20, 0, true, POTION);//create potion
					App->container.push_back(potion);
					list.Push_back(potion);
					break;
				}
			}
		}
	}
}

void Seller::Speak(){//give info to player
	printf("Seller - Hi, human I am a food processing machine , if I bring meat I will make it potions, is a long process , so if you want you can go and come back later.\n");
}
void Seller::Inventory(){//inspects his inventory
	if (!list.empty()){
				const List<Entity*>::Node* item = list.first_data;
				printf("Seller - This is my inventory:\n");
				for (; item != nullptr; item = item->next)
				{
					printf("%s\n", item->data->name.C_Str());
				}
			}	
	else{
		printf("Seller - I don't have nothing");
	}
}


