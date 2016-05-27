#include "World.h"



Monkey::Monkey()
{

}
Monkey::Monkey(const char* name, const char* description, int life, int atack, int armor,Room* location) :Creature(name, description, life, atack, armor,location)
{
	isType = MONSTER;
}

Monkey::~Monkey()
{
}




void Monkey::Go(Vector<MyString> &strings){//this move the player if the move is possible
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
void Monkey::Look()const{//LOOK CURRENT ROOM AND HIS ITEMS
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
	}
}


void Monkey::Open(Vector<MyString> &strings){
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
void Monkey::Close(Vector<MyString> &strings){
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
void Monkey::Take(Vector<MyString> &strings){//TAKE OBJECTS

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




void Monkey::Drop(Vector<MyString> &strings){

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

void Monkey::Equip(Vector<MyString> &strings){
	if (!this->list.empty()){
		List<Entity*>::Node* item = this->list.first_data;
		for (; item != nullptr; item = item->next){
			if (strings[1] == ((Item*)item->data)->name && ((Item*)item->data)->isItem == BOOTS || ((Item*)item->data)->isItem == ARMOR || ((Item*)item->data)->isItem == WEAPON){
				if (((Item*)item->data)->equiped == false){//equip and items give you stats
					((Item*)item->data)->equiped = true;
					atack += ((Item*)item->data)->atack;
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

void Monkey::UnEquip(Vector<MyString> &strings){
	if (!this->list.empty()){
		List<Entity*>::Node* item = this->list.first_data;
		for (; item != nullptr; item = item->next){
			if (strings[1] == ((Item*)item->data)->name && ((Item*)item->data)->isItem == BOOTS || ((Item*)item->data)->isItem == ARMOR || ((Item*)item->data)->isItem == WEAPON){
				if (((Item*)item->data)->equiped == true){//unequip and lost stats
					((Item*)item->data)->equiped = false;
					atack -= ((Item*)item->data)->atack;
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
