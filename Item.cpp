#include "World.h"
Item::Item(){

}
Item::Item(const char* n, const char* d, unsigned int _atack, unsigned int _defense, bool _equiped, bool _canTake, bool _canPush, Room* _location, itemType _itemType) :Entity(n, d)
{
	atack = _atack;
	defense = _defense;
	equiped = _equiped;
	canTake = _canTake;
	canPush = _canPush;
	location = _location;
	isItem = _itemType;
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