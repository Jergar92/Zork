#include "World.h"
#define NUM_EXITS 24
int main(){
	char operation[20];
	//bool doit = false;
	World a;
	a.createWorld();
	a.createExits();
	while (1){
		printf("%s, %s \n", a.player->location->name, a.player->location->description);
		gets_s(operation, 20);
		a.Torken(operation);
	
	}
	system("pause");
	return 0;
}
