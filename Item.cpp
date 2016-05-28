#include "World.h"
Item::Item(){

}
Item::Item(const char* name, const char* description, unsigned int atack, unsigned int defense, bool equiped, bool canTake, bool canPush, Room* location, itemType isItem) :Entity(name, description)
, atack(atack), defense(defense), equiped(equiped), canTake(canTake), canPush(canPush), location(location), isItem(isItem)
{
	isType = ITEM;
}
Item::Item(const char*name, const char* description, unsigned int energy, bool canTake, itemType isItem) : Entity(name, description)
, energy(energy), canTake(canTake)
{
	isType = ITEM;
}

Item::~Item(){
	
}
void Item::Look()const{
	printf("This is a %s, %s ", name.C_Str(), description.C_Str());

}
void Item::Stats()const{
	printf("%s have %i atack and %i defense\n", name.C_Str(), atack, defense);
}