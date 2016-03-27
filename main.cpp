#include "World.h"
#define NUM_EXITS 24
int main(){
	char operation[20];
	char *ope;
	ope = operation;
	World a;
	a.createWorld();
	a.Help("help");
	printf("You are in %s, %s \n", a.player->location->name, a.player->location->description);
	while (0 != strcmp(ope, "quit")){
		gets_s(ope, 20);
		a.Torken(ope);
	}
	return 0;
}
