#include "World.h"



Player::Player()
{

}
Player::Player(const char* name, const char* description, int life, int atack, int armor,Room* location) :Creature(name, description,life,atack,armor,location)
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
			const List<Entity*>::Node* item = ((Player*)App->container[i])->location->list.first_data;
			for (; item != nullptr; item = item->next)
			{
						printf("You see a %s\n", item->data->name.C_Str());
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
	



void Player::Drop(Vector<MyString> &strings){
	
	if (! this->list.empty()){
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

void Player::UnEquip(Vector<MyString> &strings){
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
					for (int j = 0; j < App->container.size(); j++){
						if (App->container[j]->isType == EXIT){
							if (((Exit*)App->container[j])->origin == location){
								if (((Exit*)App->container[j])->direction == direction && (((Exit*)App->container[j])->destination->name == "Abandoned Cave")){//check if they have the same direction
									//(((Item*)item->data)->location = ((Exit*)App->container[j])->destination;//change your location
								
										printf("You have blocked the entrance to the Abandoned cave\n");
										((Exit*)App->container[j])->destination->list.Push_back(((Item*)item->data));
										((Item*)item->data)->canPush = false;
										((Exit*)App->container[j])->origin->list.Erase(item);
										((Exit*)App->container[j])->closed = true;//block the exit
								}
								else if (((Exit*)App->container[j])->direction == direction && ((Exit*)App->container[j])->destination->name == "Monster Cave"){
									printf("the big rock block the cave\n");
									((Item*)item->data)->description = "The big rock now block the cave";//change description of the item
									((Item*)item->data)->canPush = false;
									((Exit*)App->container[j])->destination->list.Push_back(((Item*)item->data));
									((Exit*)App->container[j])->origin->list.Erase(item);
									//this blocks the fight against the monster (monsters not implemented)
								}
								else if (((Exit*)App->container[j])->direction == direction && ((Exit*)App->container[j])->destination->name == "Waterfall"){
									printf("the big rock block the water\n");
									((Item*)item->data)->description = "The big rock now block the water";//change description of the item
									((Item*)item->data)->canPush = false;
									((Exit*)App->container[j])->destination->list.Push_back(((Item*)item->data));
									((Exit*)App->container[j])->origin->list.Erase(item);
									for (int j = 0; j < App->container.size(); j++){//ITEM robot now we can take
										if (App->container[j]->isType == ITEM && App->container[j]->name == "Robot"){
											((Item*)App->container[j])->canTake = true;
											((Item*)App->container[j])->description = "this robot is in perfect condition";//block the exit
										}
									}
								}
								else if (((Exit*)App->container[j])->direction == direction && ((Exit*)App->container[j])->destination->name == "Home Base"){
									printf("You have blocked the entrance to your base, congratulations you have committed suicide\n");
									((Exit*)App->container[j])->closed = true;//block the exit
									((Item*)item->data)->canPush = false;
									((Exit*)App->container[j])->destination->list.Push_back(((Item*)item->data));
									((Exit*)App->container[j])->origin->list.Erase(item);
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
