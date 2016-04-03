#include "World.h"
#include "My_String.h"
#define NUM_EXITS 24
int main(){
	My_String orders("orders");
	
	char operation[20];
	char *ope;
	ope = operation;
	World a;
	a.createWorld();
	a.Help("help");
	printf("You are in %s, %s \n", a.player->location->name, a.player->location->description);
	while (Equals(orders, "quit")){
		gets_s(operation, 20);
		a.Torken(ope);
	}
	
	return 0;
}
