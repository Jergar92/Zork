#include "World.h"
#define NUM_EXITS 24
int main(){
	char operation[20];
	World a;
	a.createWorld();
	a.createExits();
	a.Help("help");
	printf("You are in %s, %s \n", a.player->location->name, a.player->location->description);
	while (0 != strcmp(operation, "quit")){
		gets_s(operation, 20);
		a.Torken(operation);
	}
	a.~World();
	system("pause");
	return 0;
}
